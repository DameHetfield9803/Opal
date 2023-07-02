#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

enum class TokenType {
  // Literal Types
  Number,
  Identifier,

  // Keywords
  Let,

  // Grouping * Operators
  BinaryOperator,
  Equals,
  OpenParen,
  CloseParen,
};

const std::unordered_map<std::string, TokenType> KEYWORDS = {
  { "let", TokenType::Let },
};

struct Token {
  char value;
  TokenType type;
};

std::vector<Token> tokenize(const std::string& source_code) {
  std::vector<Token> tokens;
  std::string identifier;
  int state = 0;
  for (const char c : source_code) {
    switch (state) {
      case 0:
        if (is_digit(c)) {
          state = 1;
        } else if (is_alpha(c)) {
          identifier.push_back(c);
          state = 2;
        } else if (c == '(') {
          tokens.push_back({ c, TokenType::OpenParen });
        } else if (c == ')') {
          tokens.push_back({ c, TokenType::CloseParen });
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
          tokens.push_back({ c, TokenType::BinaryOperator });
        } else if (c == '=') {
          tokens.push_back({ c, TokenType::Equals });
        } else if (is_skippable(c)) {
          // Skip uneeded chars.
        } else {
          // Handle unreconized characters.
          // TODO: Implement better errors and error recovery.
          std::cerr << "Unrecognized character found in source: " << c << std::endl;
          exit(1);
        }
        break;
      case 1:
        if (is_digit(c)) {
          identifier.push_back(c);
        } else {
          tokens.push_back({ identifier, TokenType::Number });
          identifier.clear();
          state = 0;
        }
        break;
      case 2:
        if (is_alpha(c) || is_digit(c)) {
          identifier.push_back(c);
        } else {
          const auto reserved = KEYWORDS.find(identifier);
          if (reserved != KEYWORDS.end()) {
            tokens.push_back({ identifier, reserved->second });
          } else {
            tokens.push_back({ identifier, TokenType::Identifier });
          }
          identifier.clear();
          state = 0;
        }
        break;
    }
  }

  if (state == 1 || state == 2) {
    // Handle incomplete tokens.
    // TODO: Implement better errors and error recovery.
    std::cerr << "Incomplete token found in source." << std::endl;
    exit(1);
  }

  return tokens;
}
