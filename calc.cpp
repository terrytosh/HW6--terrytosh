#include "dlist.h"
#include <iostream>
#include<string>
#include <cstdlib>

bool isValidDigit(std::string str);
bool isValidOperator(std::string str);
bool hasTwoOperands(Dlist<std::string> stack);
bool hasOneOperand(Dlist<std::string> stack);
bool canDivide(Dlist<std::string> stack);
std::string add(Dlist<std::string> &stack);
std::string subtract(Dlist<std::string> &stack);
std::string multiply(Dlist<std::string> &stack);
std::string divide(Dlist<std::string> &stack);

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
        case '+': {
          if (hasTwoOperands(stack)) {
            std::cout << "perform + op\n";
            std::string sum = add(stack);
            std::cout << "sum = " << sum << "\n";
            stack.InsertFront(sum);
          }
          else {
            std::cout << "not enough ops\n";
          }
          break;
        }
        case '-': {
          if (hasTwoOperands(stack)) {
            std::cout << "perform - op\n";
            std::string difference = subtract(stack);
            std::cout << "difference = " << difference << "\n";
            stack.InsertFront(difference);
          }
          else {
            std::cout << "not enough ops\n";
          }
          break;
        }
        case '*': {
          if (hasTwoOperands(stack)) {
            std::cout << "perform * op\n";
            std::string product = multiply(stack);
            std::cout << "product = " << product << "\n";
            stack.InsertFront(product);
          }
          else {
            std::cout << "not enough ops\n";
          }
          break;
        }
        case '/': {
          if (hasTwoOperands(stack)) {
            if (canDivide(stack)) {
              std::cout << "perform / op\n";
              std::string quotient = divide(stack);
              std::cout << "quotient = " << quotient << "\n";
              stack.InsertFront(quotient);
            }
            else {
              std::cout << "Can't divide by 0\n";
            }
          }
          else {
            std::cout << "not enough ops\n";
          }
          break;
        }
        case 'n': {
          if (hasOneOperand(stack)) {
            std::cout << "perform n op\n";
          }
          else {
            std::cout << "not enough operands\n";
          }
        break;
        }
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

bool hasTwoOperands(Dlist<std::string> stack) {
  bool flag = true;
  try {
    std::string num1 = stack.RemoveFront();
    try {
      std::string num2 = stack.RemoveFront();
    }
    catch (emptyList e) {
      flag = false;
    }
  }
  catch (emptyList e) {
    flag = false;
  }
  return flag;
}

bool hasOneOperand(Dlist<std::string> stack) {
  bool flag = true;
  try {
    std::string num1 = stack.RemoveFront();
  }
  catch (emptyList e) {
    flag = false;
  }
  return flag;
}

bool canDivide(Dlist<std::string> stack) {
  bool flag = true;
  std::string str1 = stack.RemoveFront();
  if (str1 == "0") {
    flag = false;
  }
  return flag;
}

std::string add(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float sum = num1 + num2;
  std::cout << sum << "\n";
  return std::to_string(sum);
}

std::string subtract(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float difference = num2 - num1;
  std::cout << difference << "\n";
  return std::to_string(difference);
}

std::string multiply(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float product = num2 * num1;
  std::cout << product << "\n";
  return std::to_string(product);
}

std::string divide(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float quotient = num2 / num1;
  std::cout << quotient << "\n";
  return std::to_string(quotient);
}