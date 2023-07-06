#include <crow.h>
#include <iostream>
#include <string>
//PLS HELP IDK HOW GOOD THIS IS
int main() {
    // Create a Crow application
    crow::SimpleApp app;

    // Set the number of threads as desired
    constexpr unsigned int numThreads = 6;

    // Define the routes
    // Route for the root path "/"
    CROW_ROUTE(app, "/")
    ([](){
        return "Hello, World!";
    });

    /*
    - Routing syntax
    Controller/ Action/ Index

    localhost:3000/Product/Edit/abc

    Controller: Product
    Action: Edit
    Id (dynamic value): abc
    */

    // Access control for Route
    /*
    E.g. only Admin role can access

    ROUTE_AUTH("admin", "/admin/report");
    */
    void ROUTE_AUTH(const std::string& str, const std::string& str) {
        // Logic goes here
    }
   
    // Route for the "/books" path
    CROW_ROUTE(app, "/books")
    ([](){
        return "This is the About page.";
        // Some logic goes here...
    });

    // Route for the "/books/edit/id" path
    // :id here is dynamic, value will change
    CROW_ROUTE(app, "/book/edit/:id")
    ([](){
        return "This is the About page.";
        // Some logic goes here...
    });

    // Route for the 404 page.
    // If none of the routes are matched
    CROW_ROUTE(app, "/404")
    ([](){
        return "404. Page not found.";
    });

    // Bind to the address and port, and enable multithreading
    app.bindaddr("127.0.0.1").port(8080).multithreaded(numThreads).run();

    return 0;
}

