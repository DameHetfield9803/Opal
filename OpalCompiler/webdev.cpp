#include <crow.h>
#include <iostream>
//PLS HELP IDK HOW GOOD THIS IS
int main() {
    // Create a Crow application
    crow::SimpleApp app;

    // Set the number of threads as desired
    constexpr unsigned int numThreads = 4;

    // Define the routes
    // Route for the root path "/"
    CROW_ROUTE(app, "/")
    ([](){
        return "Hello, World!";
    });

    // Route for the "/about" path
    CROW_ROUTE(app, "/about")
    ([](){
        return "This is the About page.";
    });

    // Bind to the address and port, and enable multithreading
    app.bindaddr("127.0.0.1").port(8080).multithreaded(numThreads).run();

    return 0;
}

