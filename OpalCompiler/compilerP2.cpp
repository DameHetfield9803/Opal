#include <iostream>
#include <vector>

// A function that prints numbers from 'start' to 'end'
void for(int start, int end) {
  for (int i = start; i < end; ++i) {
    std::cout << i << std::endl;
  }
}

// Method overloading for customForLoop to handle different data types
template <typename T>
void for(T start, T end) {
  for (T i = start; i < end; ++i) {
    std::cout << i << std::endl;
  }
}

// A function that prints "True" while the condition is true
void while(bool condition) {
  while (condition) {
    std::cout << "True" << std::endl;
    // You need to change the condition inside the loop
    // to eventually make it false; otherwise, it will result in an infinite loop.
    condition = false;
  }
}

// A function that prints numbers from 0 to 9
void while() {
  int i = 0;
  do {
    std::cout << i << std::endl;
    i++;
  } while (i < 10);
}

// A function that prints elements of a vector
void foreach(const std::vector<int>& numbers) {
  for (int number : numbers) {
    std::cout << number << std::endl;
  }
}

// Method overloading for customForEach to handle different data types
template <typename T>
void foreach(const std::vector<T>& elements) {
  for (const T& element : elements) {
    std::cout << element << std::endl;
  }
}

// A function that prints "True" if the condition is true, otherwise prints "False"
void if(bool condition) {
  if (condition) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }
}

// A function that prints "True" if the condition is true, otherwise does nothing
void else if(bool condition) {
  if (condition) {
    std::cout << "True" << std::endl;
  }
}

// A function that prints "Else"
void else() {
  if (!customIf(false)) {
    std::cout << "Else" << std::endl;
  }
}

// A function that prints numbers from 0 to n-1
void fn(int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << i << std::endl;
  }
}

// Method overloading for customFunction to handle different data types
template <typename T>
void fn(const T& n) {
  for (T i = 0; i < n; ++i) {
    std::cout << i << std::endl;
  }
}

int main() {
  customForLoop(0, 5);
  std::cout << "--------" << std::endl;

  customForLoop('a', 'e');
  std::cout << "--------" << std::endl;

  customWhileLoop(true);
  std::cout << "--------" << std::endl;

  customDoWhileLoop();
  std::cout << "--------" << std::endl;

  std::vector<int> numbers = {1, 2, 3, 4, 5};
  customForEach(numbers);
  std::cout << "--------" << std::endl;

  std::vector<char> chars = {'a', 'b', 'c', 'd', 'e'};
  customForEach(chars);
  std::cout << "--------" << std::endl;

  customIf(true);
  std::cout << "--------" << std::endl;

  customElseIf(false);
  std::cout << "--------" << std::endl;

  customElse();
  std::cout << "--------" << std::endl
