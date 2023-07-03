#include <iostream>
#include <vector>
#include <string>

using namespace std;
// Uses RVO (Return Value Optimization used in the return {})
// uses template to make it so that only explicit types that are valid will be allowed
// Basically a free type checker (you can think of it this way)
template <typename T>
vector<T> aList() {
  // aList just stands for ArrayList in Java 
  return {};
}
