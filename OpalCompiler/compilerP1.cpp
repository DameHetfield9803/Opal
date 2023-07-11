#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
// vectors are basically what arrayList in Java but better 
// stdexcept is similar to Java's exception handler
// NULL values
static int null() {
    return NULL;
}

template <typename T>
T echo(T x) {
    std::cout << x << " \n";
    return x;
}

template <typename T>
T add(const std::vector<T>& operands) {
    T result = T();
    for (T operand : operands) {
        result += operand;
    }
    return result;
}


template <typename T>
T multiply(const std::vector<T>& operands) {
    T result = 1;
    for (T operand : operands) {
        result *= operand;
    }
    return result;
}


template <typename T>
T divide(const std::vector<T>& operands) {
    if (operands.empty()) {
        throw std::runtime_error("Division operator requires at least one operand.");
    }
    T result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            throw std::runtime_error("You cannot divide by 0! ");
        }
        result /= operands[i];
    }
    return result;
}

template <typename T>
T minus(const std::vector<T>& operands) {
    if (operands.empty()) {
        return T(); // Handle the case where there are no operands.
    }
    T result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main() {
  // main is for testing functions and etc...
    echo(10);
    return 0;
}
