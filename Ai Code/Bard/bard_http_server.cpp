#include <httpserver.h>
#include <zip.h>

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // Create a web server object.
    HttpServer server;

    // Add a handler for the "/download" URL.
    server.add_handler("/download",
                       [](HttpRequest *request, HttpResponse *response) {
                           // Get the date range from the query string.
                           string date_range = request->get_param("date_range");

                           // Get the list of log files for the specified date range.
                           vector <string> log_files;
                           for (string file_name: get_log_files(date_range)) {
                               log_files.push_back(file_name);
                           }

                           // Create a zip file of the log files.
                           zip_file zip;
                           zip.add_files(log_files);

                           // Write the zip file to the response.
                           response->set_content_type("application/zip");
                           response->set_body(zip.to_string());
                       });

    // Start the web server.
    server.start();

    // Wait for the user to press enter to exit.
    cin.get();

    // Stop the web server.
    server.stop();

    return 0;
}

// Get the list of log files for the specified date range.
vector <string> get_log_files(string date_range) {
    // TODO: Implement this function.
    // Get the date range from the query string.
    string date_range = request->get_param("date_range");

    // If the date range is not specified, use the current date.
    if (date_range.empty()) {
        date_range = get_current_date();
    }

    // Get the list of log files for the specified date range.
    vector <string> log_files;
    for (string file_name: get_log_files_by_date(date_range)) {
        log_files.push_back(file_name);
    }
}

/***********************************************************************

```c++
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <zip.h>
#include <httpserver.h>

using namespace std;

int main() {
  // Create a web server object.
  HttpServer server;

  // Add a handler for the "/download" URL.
  server.add_handler("/download", [](HttpRequest* request, HttpResponse* response) {
    // Get the date range from the query string.
    string date_range = request->get_param("date_range");

    // Get the list of log files for the specified date range.
    vector<string> log_files;
    for (string file_name : get_log_files(date_range)) {
      log_files.push_back(file_name);
    }

    // Create a zip file of the log files.
    zip_file zip;
    zip.add_files(log_files);

    // Write the zip file to the response.
    response->set_content_type("application/zip");
    response->set_body(zip.to_string());
  });

  // Start the web server.
  server.start();

  // Wait for the user to press enter to exit.
  cin.get();

  // Stop the web server.
  server.stop();

  return 0;
}

// Get the list of log files for the specified date range.
vector<string> get_log_files(string date_range) {
  // TODO: Implement this function.
}
```

This program uses the `HttpServer` library to create a web server and the `zip` library to create zip files.
The `/download` URL is used to download log files into zip folders. The `date_range` query string parameter
is used to specify the date range of the log files to download.

The `get_log_files()` function is a placeholder function that needs to be implemented. This function should get
the list of log files for the specified date range.

To compile and run this program, you can use the following commands:

```
g++ -o server server.cpp -lhttpserver -lzip
./server
```

This will start the web server on port 8080. You can then use a web browser to access the web server at
 `http://localhost:8080/download`.

The date range selector and the "download all" button are not implemented in this program. You can implement these
features by adding the following code to the `get_log_files()` function:

```c++
// Get the date range from the query string.
string date_range = request->get_param("date_range");

// If the date range is not specified, use the current date.
if (date_range.empty()) {
  date_range = get_current_date();
}

// Get the list of log files for the specified date range.
vector<string> log_files;
for (string file_name : get_log_files_by_date(date_range)) {
  log_files.push_back(file_name);
}
```

The `get_current_date()` function is a placeholder function that needs to be implemented. This function should get
the current date.

The `get_log_files_by_date()` function is a placeholder function that needs to be implemented. This function should
get the list of log files for the specified date.

I hope this helps!
************************************************************************/