#include <iostream>
#include <vector>
#include <memory>

// Defines the available node types in the AST
enum class NodeType {
  Program,
  NumericLiteral,
  Identifier,
  BinaryExpr
};

// Statements do not result in a value at runtime
// They contain one or more expressions internally
struct Stmt {
  NodeType kind;
  std::vector<std::unique_ptr<Stmt>> children;
};

// Defines a block which contains many statements.
// Only one program will be contained in a file.
struct Program : Stmt {
  NodeType kind = NodeType::Program;
};

// Expressions will result in a value at runtime unlike Statements
struct Expr : Stmt {};

// A binary operation with two sides separated by an operator.
// Both sides can be ANY Complex Expression.
// Supported Operators: + | - | / | * | %
struct BinaryExpr : Expr {
  NodeType kind = NodeType::BinaryExpr;
  std::unique_ptr<Expr> left;
  std::unique_ptr<Expr> right;
  std::string operatorSymbol;
};

// LITERAL / PRIMARY EXPRESSION TYPES

// Represents a user-defined variable or symbol in the source.
struct Identifier : Expr {
  NodeType kind = NodeType::Identifier;
  std::string symbol;
};

// Represents a numeric constant inside the source code.
struct NumericLiteral : Expr {
  NodeType kind = NodeType::NumericLiteral;
  double value;
};

int main() {
  // Example usage
  Program program;

  auto numLiteral = std::make_unique<NumericLiteral>();
  numLiteral->value = 42;
  program.children.push_back(std::move(numLiteral));
  
  auto identifier = std::make_unique<Identifier>();
  identifier->symbol = "x";
  program.children.push_back(std::move(identifier));

  auto binaryExpr = std::make_unique<BinaryExpr>();
  binaryExpr->left == std::move(program.children[0]);
  binaryExpr->right == std::move(program.children[1]);
  binaryExpr->operatorSymbol = "+";
  program.children.push_back(std::move(binaryExpr));

  return 0;
}
