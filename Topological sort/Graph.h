#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
#include <set>
#include <vector>

//Ориентированный граф
class Graph
{
public:

  //Добавление дуги в граф
  void addEdge(int vertexOne, int vertexTwo);
  //Получение списка соседей вершины (идущих от неё)
  std::list<int> getNeighbours(int vertex);
  //Проверка, имеет ли граф цикл
  bool hasCycle();
  //Топологическая сортировка
  std::vector<int> topologicalSort();
  //Вывод списка смежности
  void print();

private:

  //Множество вершин графа
  std::set<int> vertices;
  //Размер графа
  int numOfVertices = 0;
  //Список смежности
  std::map<int, std::list<int>> adjList;

  //Цвета (статус) вершин для DFS
  enum Color
  {
    WHITE, //Вершина не посещена в процессе DFS
    GREY, //Вершина в процессе обработки 
    BLACK //Вершина полностью обработана
  };

  //Вспомогательный метод для проверки наличия цикла на основе поиска в глубину (DFS)
  bool dfsHasCycle(int vertex, std::map<int, Color> & colors);
  //Вспомогательный метод для топологическая сортировки на основе поиска в глубину (DFS)
  void dfsTopologicalSort(int vertex, std::map<int, bool> & visited, std::vector<int> & orderedVertices);
};

#endif