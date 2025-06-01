#include "Graph.h"
#include <iostream>

//Добавление дуги в граф
void Graph::addEdge(int vertexOne, int vertexTwo)
{
  if (adjList.count(vertexOne) == 0 || adjList.count(vertexTwo) == 0)
  {
    numOfVertices += 1;
  }

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
  std::vector<Color> colors(numOfVertices, WHITE);

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

bool Graph::dfsHasCycle(int vertex, std::vector<Color> & colors)
{
  bool cycleIsFound = false;

  //Вершина находится в обработке
  colors[vertex] = GREY;

  //Для каждого соседа вершины проверяем, существует ли от него цикл
  for (int neighbour : getNeighbours(vertex))
  {
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

/*
  Вывод списка смежности в виде: 
  1 -> 2 3 4
  2 -> 3 5
*/
void Graph::print()
{
  for (auto pair : adjList)
  {
    std::cout << pair.first << " -> ";
    for (auto j : pair.second)
    {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}