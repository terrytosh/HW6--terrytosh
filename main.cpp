#include "dlist.h"
#include <iostream>

int main() {
  std::cout << "Hello World!\n";
  Dlist<int> catsweb; //records are big, so store pointer
  if (catsweb.IsEmpty()) {
    std::cout << "Empty\n";
  }
  else {
    std::cout << "Not empty\n";
  }
  catsweb.InsertFront(5);
  if (catsweb.IsEmpty()) {
    std::cout << "Empty\n";
  }
  else {
    std::cout << "Not empty\n";
  }

  Dlist<int> copyList(catsweb);
  if (copyList.IsEmpty()) {
    std::cout << "Empty\n";
  }
  else {
    std::cout << "Not empty\n";
  }
}