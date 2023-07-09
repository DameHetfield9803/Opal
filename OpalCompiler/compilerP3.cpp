#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Uses RVO (Return Value Optimization used in the return {})
// Uses template to make it so that only explicit types that are valid will be allowed
// Basically a free type checker (you can think of it this way)
template <typename T>
vector<T> aList(size_t size) {
  // aList stands for ArrayList
  // Instead of using the constructor initializer list {}, we can use vector reserve
  // to pre-allocate memory for better efficiency
  vector<T> result;
  result.reserve(size); // Adjust the number based on your expected size
  return result;
}
