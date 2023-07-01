#include<iostream>
#include<vector>
#include<string>
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

constexpr std::unordered_map<std::string, TokenType> KEYWORDS = {
  { "let", TokenType::Let },
};

std::vector<Token> tokenize(const std::string& source_code) {
  std::vector<Token> tokens;
  for (const char c : source_code) {
    switch (c) {
      case '(':
        tokens.push_back(Token{ c, TokenType::OpenParen });
        break;
      case ')':
        tokens.push_back(Token{ c, TokenType::CloseParen });
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        tokens.push_back(Token{ c, TokenType::BinaryOperator });
        break;
      case '=':
        tokens.push_back(Token{ c, TokenType::Equals });
        break;
      case '0'...'9':
        {
          std::string number;
          number += c;
          while (i < source_code.size() && is_digit(source_code[i])) {
            number += source_code[i++];
          }

          tokens.push_back(Token{ number, TokenType::Number });
        }
        break;
      case 'a'...'z':
      case 'A'...'Z':
        {
          std::string identifier;
          identifier += c;
          while (i < source_code.size() && is_alpha(source_code[i])) {
            identifier += source_code[i++];
          }

          const auto reserved = KEYWORDS.find(identifier);
          if (reserved != KEYWORDS.end()) {
            tokens.push_back(Token{ identifier, reserved->second });
          } else {
            tokens.push_back(Token{ identifier, TokenType::Identifier });
          }
        }
        break;
      default:
        if (is_skippable(c)) {
          // Skip uneeded chars.
        } else {
          // Handle unreconized characters.
          // TODO: Implement better errors and error recovery.
          std::cerr << "Unrecognized character found in source: " << c << std::endl;
          exit(1);
        }
    }
  }

  return tokens;
}
