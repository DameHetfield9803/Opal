/* #include <iostream>
#include <fstream>
#include <string_view>
#include <unordered_set>
#include <memory>
#include <mutex>

// A simple garbage collector that tracks all allocated objects and deletes them when they are no longer needed.
class GarbageCollector {
public:
  void addObject(void* object) {
    // Add the object to the set of allocated objects.
    std::lock_guard<std::mutex> lock(mutex);
    objects.insert(object);
  }

  void deleteObject(void* object) {
    // Remove the object from the set of allocated objects.
    std::lock_guard<std::mutex> lock(mutex);
    objects.erase(object);
    // Deallocate the object memory.
    free(object);
  }

  size_t getSize() {
    std::lock_guard<std::mutex> lock(mutex);
    return objects.size();
  }

private:
  std::unordered_set<void*> objects;
  std::mutex mutex;
};

int main() {
  // Choose a file extension that is not already in use by another programming language.
  constexpr std::string_view fileExtension = "op";

  // Create a file with the chosen file extension in binary mode.
  std::ofstream file(std::string(fileExtension) + ".cpp", std::ios::binary);

  // Write the code for your new programming language in the file.
  constexpr std::string_view codeBlock = R"(
#include <iostream>
#include <memory>

// Create a garbage collector object.
GarbageCollector gc;

int main() {
  // Allocate an object using std::unique_ptr.
  std::unique_ptr<int> object = std::make_unique<int>(100);

  // Add the object to the garbage collector.
  gc.addObject(object.get());

  // Do something with the object.
  std::cout << *object << std::endl;

  // The object will be automatically deleted when it goes out of scope.

  return 0;
})";

  // Write the entire code block to the file.
  file << codeBlock;

  // Test your new programming language by running it.
  system(("g++ -o " + std::string(fileExtension) + " " + fileExtension + ".cpp").c_str());
  system(("./" + std::string(fileExtension)).c_str());

  // You should see the message "100" printed to the console.

  // Check the size of the garbage collector.
  size_t size = gc.getSize();
  if (size > 0) {
    std::cerr << "There are " << size << " objects that are still allocated." << std::endl;
  }

  return 0;
}
*/

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <unordered_map>

// A simple garbage collector that tracks all allocated objects and deletes them when they are no longer needed.
// The only reason the string_view is giving an error is because apparently THIS FUCKING VERSION OF C++ IN GITHUB AND VSCODE IS TOO FUCKING OLD WTF
// Fret not it is not a syntax or wtv tf error it's just vscode and the inbuilt C++ extention
class GarbageCollector {
public:
    void addObject(std::unique_ptr<void> object) {
        // Add the object to the map of allocated objects.
        objects[object.get()] = std::move(object);
    }

    void deleteObject(void* object) {
        // Remove the object from the map of allocated objects.
        objects.erase(object);
    }

private:
    std::unordered_map<void*, std::unique_ptr<void>> objects;
};

void createAndRunNewLanguage() {
    // Choose a file extension that is not already in use by another programming language.
    const std::string fileExtension = "opal";

    // Create a file with the chosen file extension in binary mode.
    std::ofstream file(fileExtension + ".cpp", std::ios::binary);

    // Write the code for your new programming language in the file.
    const std::string codeBlock = R"(
#include <iostream>
#include <memory>

// Create a garbage collector object.
GarbageCollector gc;

int main() {
  // Allocate an object using std::make_unique.
  auto object = std::make_unique<int>(100);

  // Add the object to the garbage collector.
  gc.addObject(std::move(object));

  // Do something with the object.
  std::cout << *object << std::endl;

  // The object will be automatically deleted when it goes out of scope.

  return 0;
})";

    // Write the entire code block to the file.
    file << codeBlock;

    // Test your new programming language by running it.
    system(("g++ -o " + fileExtension + " " + fileExtension + ".cpp").c_str());
    system(("./" + fileExtension).c_str());

    // You should see the message "100" printed to the console.
}

int main() {
    // Create a garbage collector object.
    GarbageCollector gc;

    // Allocate an object using std::make_unique.
    auto object = std::make_unique<int>(100);

    // Add the object to the garbage collector.
    gc.addObject(std::move(object));

    // Do something with the object.
    std::cout << *object << std::endl;

    // The object will be automatically deleted when it goes out of scope.

    // Call the function to create and run your new programming language.
    createAndRunNewLanguage();

    return 0;
}
