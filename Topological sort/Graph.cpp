#include "Graph.h"
#include "Printer.h"
#include <iostream>

//Добавление дуги в граф
void Graph::addEdge(int vertexOne, int vertexTwo)
{
  vertices.insert(vertexOne);
  vertices.insert(vertexTwo);

  numOfVertices = vertices.size();

  adjList[vertexOne].push_back(vertexTwo);
}

//Получение списка соседей вершины (идущих от неё)
std::list<int> Graph::getNeighbours(int vertex)
{
  std::list<int> listOfNeighbours = adjList[vertex];

  return listOfNeighbours;
}

bool Graph::hasCycle()
{
  bool hasCycle = false;

  //Создаём список цветов вершин, сначала все WHITE (непосещённые)
  std::map<int, Color> colors;
  for (int v : vertices)
  {
    colors[v] = WHITE;
  }

  //Для каждой вершины проверяем, существует ли от неё цикл
  for (const auto pair : adjList)
  {
    int vertex = pair.first;
    if (colors[vertex] == WHITE && dfsHasCycle(vertex, colors))
    {
      hasCycle = true;
    }
  }

  return hasCycle;
}

//Вспомогательный метод для проверки наличия цикла на основе поиска в глубину (DFS)
bool Graph::dfsHasCycle(int vertex, std::map<int, Color> & colors)
{
  bool cycleIsFound = false;

  //Вершина находится в обработке
  colors[vertex] = GREY;

  //Для каждого соседа вершины проверяем, существует ли от него цикл
  for (int neighbour : getNeighbours(vertex))
  {
    //Если сосед уже находился в обработке, значит, путь зациклился
    if (colors[neighbour] == GREY)
    {
      cycleIsFound = true;;
    }
    if (colors[neighbour] == WHITE && dfsHasCycle(neighbour, colors))
    {
      cycleIsFound = true;
    }
  }

  //Обработка вершины завершена
  colors[vertex] = BLACK;

  return cycleIsFound;
}

//Топологическая сортировка
std::vector<int> Graph::topologicalSort()
{
  //Если граф имеет цикл, то сортировка неприменима, выбрасывается исключение
  if (this->hasCycle())
  {
    throw std::logic_error("Error: Graph has cycle. Topological sort can not be used for graph with cycles.\n");
  }

  /*
    Создаем map для хранения статуса посещения вершин в виде:
    key = номер вершины, value = true(посещена)/false(не посещена)
   */
  std::map<int, bool> visited;
  for (int v : vertices)
  {
    visited[v] = false;
  }

  //Создаем список вершин, в котором будет хранится сортированный порядок вершин
  std::vector<int> orderedVertices;

  //Проходим по всем вершинам
  for (int v = 1; v <= numOfVertices; v++)
  {
    //Если вершина не посещена, вызываем вспомогательный метод сортировки
    if (!visited[v])
    {
      dfsTopologicalSort(v, visited, orderedVertices);
    }
  }

  //Переворачиваем список для получения правильного порядка вершин сортировки
  std::reverse(orderedVertices.begin(), orderedVertices.end());

  return orderedVertices;
}

//Вспомогательный метод для топологическая сортировки на основе поиска в глубину (DFS)
void Graph::dfsTopologicalSort(int vertex, std::map<int, bool> & visited, std::vector<int> & orderedVertices)
{
  //Меняем статус вершины на true(посещена)
  visited[vertex] = true;
  for (int neighbour : getNeighbours(vertex))
  {
    //Если её соседи не посещены, вызываем для них вспомогательный метод сортировки
    if (!visited[neighbour])
    {
      dfsTopologicalSort(neighbour, visited, orderedVertices);
    }
  }
  //Вершина добавляется в список после обработки всех её соседей
  orderedVertices.push_back(vertex);
}

/*
  Вывод списка смежности в виде: 
  1 -> 2 3 4
  2 -> 3 5
*/
void Graph::print()
{
  Printer<std::list<int>> printer;
  printer.printMap(adjList);
}