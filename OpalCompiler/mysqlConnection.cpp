#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>


// Form of testing 
// 127.0.0.1 means localhost. 
// 3306 refers to port number 
// tcp refers to layer of control protocol. Stands for Transport Control Protocol'
// This is a test of MySQL client
int main() {
    try {
        // Create a MySQL Connector/C++ driver
        sql::mysql::MySQL_Driver *driver;
        driver = sql::mysql::get_mysql_driver_instance();
        
        // Establish a connection to the MySQL database
        sql::Connection *conn;
        conn = driver->connect("tcp://127.0.0.1:3306", "myuser", "mypassword");
        
        if (conn->isValid()) {
            std::cout << "Connected to MySQL successfully!" << std::endl;
        } else {
            std::cout << "Failed to connect to MySQL!" << std::endl;
        }
        
        // Close the connection
        delete conn;
    } catch (const sql::SQLException &e) {
        std::cerr << "MySQL Error: " << e.what() << std::endl;
    }

    return 0;
}
