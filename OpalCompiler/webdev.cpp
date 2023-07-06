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
    // RBAC
    // Access control for Route
    /*
    E.g. only Admin role can access

    ROUTE_AUTH("admin", "/admin/report");
    */
    void ROUTE_AUTH(const std::string& str, const std::string& str) {
        // Logic goes here
    }
   
    // Route for the "/books" path
   /* CROW_ROUTE(app, "/books")
    ([](){
        return "This is the About page.";
        // Some logic goes here...
    });*/
    // IDK how good this is or will be but let's try
    CROW_ROUTE(app, "/books")
    ([](){
    // Perform any necessary operations to fetch or process data securely
    // e.g., querying a database, reading a file, etc.
    // Store the result in a local variable

    std::string result; // Define an empty string to store the result

    // Replace the return statement with the actual logic
    // Example: Fetching data from a database
    // Assuming there's a function called fetchBooksFromDatabase() that returns a vector of books
    std::vector<Book> books = fetchBooksFromDatabase();

    // Process the fetched data securely
    // Example: Construct a string representation of the books
    for (const auto& book : books) {
        // Sanitize and validate the book title to prevent any potential security issues
        std::string sanitizedTitle = sanitizeAndValidate(book.getTitle());
        
        // Add the sanitized title to the result
        result += sanitizedTitle + "\n";
    }

    // Clear sensitive data from memory
    // It's important to clear any sensitive data stored in variables
    // In this case, we clear the 'books' vector to remove any book data from memory
    books.clear();

    // Return the result securely
    // Encapsulate the result in a 'crow::response' object
    // Use 'move' to efficiently transfer ownership of the result to the response object
    return crow::response(std::move(result));
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

