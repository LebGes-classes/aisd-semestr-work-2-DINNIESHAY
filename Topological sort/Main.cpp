#include "Graph.h"
#include "Printer.h"
#include <iostream>

Printer<int> printer;

/*
  Тестирование топологической сортировки на графе с циклом
  Ожидается: Сообщение об ошибке
*/
void testGraphWithCycle()
{
  Graph graph;
  graph.addEdge(1, 2);
  graph.addEdge(1, 3);
  graph.addEdge(2, 4);
  graph.addEdge(4, 5);
  graph.addEdge(5, 2);
  graph.addEdge(3, 5);

  graph.print();

  try
  {
    std::vector<int> sorted = graph.topologicalSort();

    std::cout << "\nTopological sorting: ";
    printer.printVector(sorted);
  }
  catch (std::exception & e)

  {
    std::cerr << e.what() << std::endl;
  }
}

/*
  Тестирование топологической сортировки на графе с циклом
  Ожидается: Один из вариантов топологической сортировки
*/
void testGraphWithoutCycle()
{
  Graph graph;
  graph.addEdge(1, 2);
  graph.addEdge(1, 6);
  graph.addEdge(2, 8);
  graph.addEdge(4, 3);
  graph.addEdge(4, 8);
  graph.addEdge(4, 9);
  graph.addEdge(4, 5);
  graph.addEdge(5, 9);
  graph.addEdge(7, 1);
  graph.addEdge(7, 2);
  graph.addEdge(7, 3);
  graph.addEdge(9, 3);
  graph.addEdge(10, 5);

  graph.print();

  try
  {
    std::vector<int> sorted = graph.topologicalSort();

    std::cout << "\nTopological sorting: ";
    printer.printVector(sorted);
  }
  catch (std::exception & e)
  {
    std::cerr << e.what();
  }
}

int main()
{
  testGraphWithCycle();
  testGraphWithoutCycle();
}
