#ifndef PRINTER_H
#define PRINTER_H

#include <vector>
#include <map>

//Принтер для вывода элементов коллекций
template <typename T>
class Printer
{
public:

  //Вывод элементов vector
  void printVector(const std::vector<T> vector);
  //Вывод элементов map
  void printMap(const std::map<int, T> vector);
};

/*
  Вывод vector в виде:
  1 2 3 4
*/
template <typename T>
void Printer<T>::printVector(std::vector<T> vector)
{
  for (int elem : vector)
  {
    std::cout << elem << " ";
  }
  std::cout << std::endl;
}

/*
  Вывод map в виде:
  key(int) -> value
*/
template <typename T>
void Printer<T>::printMap(const std::map<int, T> map)
{
  for (auto pair : map)
  {
    std::cout << pair.first << " -> ";
    for (auto value : pair.second)
    {
      std::cout << value << " ";
    }
    std::cout << std::endl;
  }
}

#endif