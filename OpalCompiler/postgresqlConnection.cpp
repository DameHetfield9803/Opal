#include <iostream>
#include <pqxx/pqxx>
//pqxx is the library for PostgresSQL 

// A simple library that connects to PostgreSQL.
class PostgreSQLConnector {
public:
  PostgreSQLConnector(const std::string& database, const std::string& user, const std::string& password, const std::string& host, int port) {
    // Establish a connection to the PostgreSQL database.
    try {
      conn = pqxx::connection("dbname=" + database + " user=" + user + " password=" + password + " hostaddr=" + host + " port=" + std::to_string(port));
    } catch (const std::exception& e) {
      std::cerr << "Error: " << e.what() << std::endl;
    }
  }

  ~PostgreSQLConnector() {
    // Close the connection to the PostgreSQL database.
    // ~ in C++ is a destructor. It is called when an object is destroyed. In this example, the ~ is there to 'destroy' the connection when it goes out of scope
    conn.disconnect();
  }

  bool isConnected() {
    return conn.is_open();
  }

private:
  pqxx::connection conn;
};

int main() {
  // Create a PostgreSQL connector.
  PostgreSQLConnector connector("mydatabase", "myuser", "mypassword", "127.0.0.1", 5432);

  // Check if the connection is open.
  if (connector.isConnected()) {
    std::cout << "Connected to PostgreSQL successfully!" << std::endl;
  } else {
    std::cout << "Failed to connect to PostgreSQL!" << std::endl;
  }

  return 0;
}
