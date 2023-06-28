#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
// vectors are basically what arrayList in Java but better 

// basically print() in Python
string echo(string x){
  std::cout << x; 
}
int echo(int i){
  std::cout << i; 
}
int echo(char j){
  std::cout << j;
}

double echo(double a){
  std::cout << a;
}

float echo(float b){
  std::cout << b;
}

long echo(long c){
  std::cout << c;
}

bool echo(bool d){
  if(d==true){
    std::cout << true;
  }
  else{
    std::cout << false;
  }

  // Math operations 
  // Addition
double add(const std::vector<double>& operands){
   double result = 0.0;
    for (double operand : operands) {
        result += operand;
    }
    return result;
}
int add(const std::vector<int>& operands){
   int result = 0;
  for (int operand : operands){
    result += operand;
  }
  return result;
}
float add(const std::vector<float>& operands){
   float result = 0.0;
  for (float operand : operands){
    result += operand;
  }
  return result;
}

// Multiplication
double multiply(const std::vector<double>& operands){
   double result = 0.0;
    for (double operand : operands) {
        result *= operand;
    }
    return result;
}
int multiply(const std::vector<int>& operands){
   int result = 0;
  for (int operand : operands){
    result *= operand;
  }
  return result;
}
float multiply(const std::vector<float>& operands){
   float result = 0.0;
  for (float operand : operands){
    result *= operand;
  }
  return result;
}
long multiply(const std::vector<float>& operands){
   long result = 0.0;
  for (long operand : operands){
    result *= operand;
  }
  return result;
}

// Division
double divide(const std::vector<double>& operands) {
    if (operands.empty()) {
        throw std::runtime_error("Division operator requires at least one operand.");
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            throw std::runtime_error("Division by zero error.");
        }
        result /= operands[i];
    }
    return result;
}

int divide(const std::vector<int>& operands) {
    if (operands.empty()) {
        throw std::runtime_error("Division operator requires at least one operand.");
    }
    int result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            throw std::runtime_error("Division by zero error.");
        }
        result /= operands[i];
    }
    return result;
}

float divide(const std::vector<float>& operands) {
    if (operands.empty()) {
        throw std::runtime_error("Division operator requires at least one operand.");
    }
    float result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            throw std::runtime_error("Division by zero error.");
        }
        result /= operands[i];
    }
    return result;
}

long divide(const std::vector<long>& operands) {
    if (operands.empty()) {
        throw std::runtime_error("Division operator requires at least one operand.");
    }
    long result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        if (operands[i] == 0) {
            throw std::runtime_error("Division by zero error.");
        }
        result /= operands[i];
    }
    return result;
}

// Subtraction
int minus(const std::vector<int>& operands){
  if (operands.empty()) {
        // Handle the case where there are no operands.
        // You can choose to throw an exception or return a default value.
        // Here, we'll return 0 as the default value.
        return 0;
    }
    int result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}
double minus(const std::vector<double>& operands){
  if (operands.empty()) {
        // Handle the case where there are no operands.
        // You can choose to throw an exception or return a default value.
        // Here, we'll return 0 as the default value.
        return 0;
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}
float minus(const std::vector<float>& operands){
  if (operands.empty()) {
        // Handle the case where there are no operands.
        // You can choose to throw an exception or return a default value.
        // Here, we'll return 0 as the default value.
        return 0;
    }
    float result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}
long minus(const std::vector<long>& operands){
  if (operands.empty()) {
        // Handle the case where there are no operands.
        // You can choose to throw an exception or return a default value.
        // Here, we'll return 0 as the default value.
        return 0;
    }
    long result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

// For and While loops 
