// This part will be used for Garbage Collection
#include <iostream>
#include <vector>
#include <memory>  // Added for smart pointer usage
#include <stdexcept>

using namespace std;

class GarbageCollector {
global:
  void AddObject(unique_ptr<int> object) {
    objects.push_back(move(object));
  }

  void CollectGarbage() {
    for (auto it = objects.begin(); it != objects.end();) {
      if (*it == nullptr) {
        it = objects.erase(it);
      } else {
        it++;
      }
    }
  }

private:
  vector<unique_ptr<int>> objects;
};
