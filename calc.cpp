#include "dlist.h"
#include <iostream>
#include<string>

bool isValidDigit(std::string str);
bool isValidOperator(std::string str);

int main() {
  Dlist<std::string> stack;
  std::string str = "";

  while (str != "q") {
    std::cin >> str;
    if (isValidDigit(str)) {
      std::cout << "valid:add to stack front\n";
      stack.InsertFront(str);
    }
    else if (isValidOperator(str)) {
      std::cout << "valid op\n";
      switch (str[0]) {
        case '+': std::cout << "perform + op\n";
        break;
        case '-': std::cout << "perform - op\n";
        break;
        case '*': std::cout << "perform * op\n";
        break;
        case '/': std::cout << "perform / op\n";
        break;
        case 'n': std::cout << "perform n op\n";
        break;
        case 'd': std::cout << "perform d op\n";
        break;
        case 'r': std::cout << "perform r op\n";
        break;
        case 'p': std::cout << "perform p op\n";
        break;
        case 'c': std::cout << "perform c op\n";
        break;
        case 'a': std::cout << "perform a op\n";
        break;
      }
    }
    else {
      std::cout << "not valid\n";
    }
  }
  return 0;
}

bool isValidDigit(std::string str) {
  bool flag = true;
  bool contains = false;
  if (str.length() > 1) {
    if (str[str.length() - 1] == '.'){
      flag = false;
    }
    else {
      for (int i = 0; i < str.length() - 1; i ++) {
        if (str[i] == '.') {
          contains = true;
        }
      }
      if (!contains) {
        flag = false;
      }
    }
  }
  else if (str > "9" || str < "0"){
    flag = false;
  }

  return flag;
}

bool isValidOperator(std::string str) {
  bool flag = false;
  std::string op[11] = { "+", "-", "*", "/", "n", 
                         "d", "r", "p", "c", "a", "q" };
  for (int i = 0; i < 11; i++) {
    if (str== op[i]) {
      flag = true;
    }
  }
  return flag;
}