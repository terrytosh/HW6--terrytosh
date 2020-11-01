#include "dlist.h"
#include <iostream>
#include<string>
#include <cstdlib>

/*
Psuedocode:
isValidDigit():
If (string is an operator): return true
Else (string is valid): return false

isValidOperator(): 
Intialize a bool flag to false.
Initalize an array of strings populated with the
valid operators.
for (i = 0; i < size of array; i++):
if (current string equals op[i]): then the operator is valid so
set flag to true. Return flag

hasTwoOperands():
Initalize a bool flag to true.
try: pop from stack
  try: pop again from stack
  catch: (list is empty): set flag to false
catch (list is empty): set flag to false
return flag

hasOneOperand():
Initalize a bool flag to true.
try: pop from stack
if statement trows error, catch it and
set flag to false.
Return flag

canDivide():
Initalize a bool flag to true.
Pop from temp stack and equal to str1
If the element is a "0", set flag to false
Return flag

add():
Pop first two elements and set them to str1 & str2
Intialize num1 & num2 as stof(str1) & stof(str2)
Add num1 and num2 and store in sum
Return to_string(sum)

subtract():
Pop first two elements and set them to str1 & str2
Intialize num1 & num2 as stof(str1) & stof(str2)
Subtract num2 from num1 and store in difference
Return to_string(difference)

multiply():
Pop first two elements and set them to str1 & str2
Intialize num1 & num2 as stof(str1) & stof(str2)
Multiply num1 and num2 and store in product
Return to_string(product)

divide():
Pop first two elements and set them to str1 & str2
Intialize num1 & num2 as stof(str1) & stof(str2)
Divide num2 by num1 and store in quotient
Return to_string(quotient)

negate():
Pop first element and set to str
Initalize negate as stof(str)
Multiply negate by -2
Return to_string(negate)

duplicate():
Pop first element and set to str
Return str

formatOutputString():
Initalize a flag bool to true, an int ctr to 0,
and index to 0
for (i = str.length() - 1; cont == true; i--):
If (current character is a decimal): set cont to
flase and index to if
Else if (current character is a 0): set index to if
Else: set cont to false and index to i + 1
increment ctr
Remove characters (index to ctr) from str
Return str

printAll():
while (stack is not empty):
pop from stack and set to str
If (str == '0'): print '0' to console
Else: print formatOutputString(str) to console
If (stack is empty): print "\n" to console
Else: print " " to console
*/

bool isValidDigit(std::string str);
bool isValidOperator(std::string str);
bool hasTwoOperands(Dlist<std::string> stack);
bool hasOneOperand(Dlist<std::string> stack);
bool canDivide(Dlist<std::string> stack);
std::string add(Dlist<std::string> &stack);
std::string subtract(Dlist<std::string> &stack);
std::string multiply(Dlist<std::string> &stack);
std::string divide(Dlist<std::string> &stack);
std::string negate(Dlist<std::string> &stack);
std::string duplicate(Dlist<std::string> &stack);
std::string formatOutputString(std::string str);
void printAll(Dlist<std::string> stack);

int main() {
  Dlist<std::string> stack;
  std::string str = "";

  while (str != "q") {
    std::cin >> str;
    if (isValidDigit(str)) {
      stack.InsertFront(str);
    }
    else if (isValidOperator(str)) {
      switch (str[0]) {
        case '+': {
          if (hasTwoOperands(stack)) {
            std::string sum = add(stack);
            stack.InsertFront(sum);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case '-': {
          if (hasTwoOperands(stack)) {
            std::string difference = subtract(stack);
            stack.InsertFront(difference);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case '*': {
          if (hasTwoOperands(stack)) {
            std::string product = multiply(stack);
            stack.InsertFront(product);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case '/': {
          if (hasTwoOperands(stack)) {
            if (canDivide(stack)) {
              std::string quotient = divide(stack);
              stack.InsertFront(quotient);
            }
            else {
              std::cout << "Divide by zero\n";
            }
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case 'n': {
          if (hasOneOperand(stack)) {
            std::string neg = negate(stack);
            stack.InsertFront(neg);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case 'd': {
          if (hasOneOperand(stack)) {
            std::string str = duplicate(stack);
            stack.InsertFront(str);
            stack.InsertFront(str);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case 'r': {
          if (hasTwoOperands(stack)) {
            std::string str1 = stack.RemoveFront();
            std::string str2 = stack.RemoveFront();
            stack.InsertFront(str1);
            stack.InsertFront(str2);
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case 'p': {
          if (hasOneOperand(stack)) {
            Dlist<std::string> temp = stack;
            std::string str = temp.RemoveFront();
            if (str[0] == '0') {
              std::cout << "0" << "\n";
            }
            else {
              std::cout << formatOutputString(str) << "\n";
            }
          }
          else {
            std::cout << "Not enough operands\n";
          }
          break;
        }
        case 'c': {
          while (!stack.IsEmpty()) {
            std::string str = stack.RemoveFront();
          }
          break;
        }
        case 'a': {
          printAll(stack);
          break;
        }
      }
    }
    else {
      std::cout << "Bad input\n";
    }
  }
  return 0;
}

bool isValidDigit(std::string str) {
  if (isValidOperator(str)) {
    return false;
  }
  return true;
}

bool isValidOperator(std::string str) {
  bool flag = false;
  std::string op[11] = { "+", "-", "*", "/", "n", 
                         "d", "r", "p", "c", "a", "q" };
  for (int i = 0; i < 11; i++) {
    if (str == op[i]) {
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
  return std::to_string(sum);
}

std::string subtract(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float difference = num2 - num1;
  return std::to_string(difference);
}

std::string multiply(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float product = num2 * num1;
  return std::to_string(product);
}

std::string divide(Dlist<std::string> &stack) {
  std::string str1 = stack.RemoveFront();
  std::string str2 = stack.RemoveFront();
  float num1 = std::stof(str1);
  float num2 = std::stof(str2);
  float quotient = num2 / num1;
  return std::to_string(quotient);
}

std::string negate(Dlist<std::string> &stack) {
  std::string str = stack.RemoveFront();
  float negate = std::stof(str);
  negate = negate * -1;
  return std::to_string(negate);
}

std::string duplicate(Dlist<std::string> &stack) {
  std::string str = stack.RemoveFront();
  return str;
}

void printAll(Dlist<std::string> stack) {
  while(!stack.IsEmpty()) {
    std::string str = stack.RemoveFront();
    if (str[0] == '0') {
      std::cout << "0";
    }
    else {
      std::cout << formatOutputString(str);
    }
    if(stack.IsEmpty()) {
      std::cout << "\n";
    }
    else {
      std::cout << " ";
    }
  }
}

std::string formatOutputString(std::string str) {
  bool cont = true;
  int ctr = 0, index = 0;
  for (int i = str.length() - 1; cont; i--) {
    if (str[i] == '.') {
      cont = false;
      index = i;
    }
    else if (str[i] == '0') {
      index = i;
    }
    else {
      cont = false;
      index = i + 1;
    }
    ctr++;
  }
  str.erase(index, ctr);
  return str;
}