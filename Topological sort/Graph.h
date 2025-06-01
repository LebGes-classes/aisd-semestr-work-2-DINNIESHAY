#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <map>
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
  //Вывод списка смежности
  void print();

private:

  //Список смежности
  std::map<int, std::list<int>> adjList;
  //Размер графа
  int numOfVertices = 0;

  //Цвета (статус) вершин для DFS
  enum Color
  {
    WHITE, //Вершина не посещена в процессе DFS
    GREY, //Вершина в процессе обработки 
    BLACK //Вершина полностью обработана
  };

  //Проверка наличия цикла с помощью DFS
  bool dfsHasCycle(int vertex, std::vector<Color> & colors);
};

#endif