#include <httpserver.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <zip.h>

using namespace httpserver;

class file_download_resource : public http_resource {
public:
    const std::shared_ptr<http_response> render_GET(const http_request& req) override {
        // Get the requested file path from the request
        std::string file_path = req.get_arg("file");

        // Check if the file exists
        std::ifstream file(file_path);
        if (!file.good()) {
            return std::shared_ptr<http_response>(new string_response("File not found", 404));
        }

        // Create a zip archive in memory
        zip_t* archive = zip_open("archive.zip", ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        if (!archive) {
            return std::shared_ptr<http_response>(new string_response("Failed to create zip archive", 500));
        }

        // Add the file to the zip archive
        zip_source_t* source = zip_source_file(archive, file_path.c_str(), 0, -1);
        if (!source || zip_file_add(archive, file_path.c_str(), source, ZIP_FL_ENC_UTF_8) < 0) {
            zip_source_free(source);
            zip_close(archive);
            return std::shared_ptr<http_response>(new string_response("Failed to add file to zip archive", 500));
        }

        // Close the zip archive
        if (zip_close(archive) != 0) {
            return std::shared_ptr<http_response>(new string_response("Failed to close zip archive", 500));
        }

        // Read the contents of the zip archive into a string
        std::ifstream zip_file("archive.zip", std::ios::binary);
        std::stringstream buffer;
        buffer << zip_file.rdbuf();
        std::string zip_contents = buffer.str();

        // Create and return the response with the contents of the zip archive
        auto response = std::shared_ptr<string_response>(new string_response(zip_contents, 200));
        response->with_header("Content-Type", "application/zip");
        response->with_header("Content-Disposition", "attachment; filename=archive.zip");
        return response;
    }
};

int main() {
    webserver server = create_webserver(8080);

    file_download_resource resource;
    server.register_resource("/download", &resource);

    server.start(true);

    return 0;
}

/***********************************************************************
Here is a C++ program that runs an HTTP web server on an embedded Linux system using the `libhttpserver` library¹.
This library is built upon `libmicrohttpd`² to provide a simple API for developers to create HTTP services in C++.
You can use this as a starting point and modify it to meet your specific requirements, such as adding the functionality
to download log files into zip folders using a web browser, running the server in LAN, providing a date selector for
users to select the date range for the log files to download, and adding a "download all" button to download all log
files from the device.

```cpp
#include <httpserver.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <zip.h>

using namespace httpserver;

class file_download_resource : public http_resource {
public:
    const std::shared_ptr<http_response> render_GET(const http_request& req) override {
        // Get the requested file path from the request
        std::string file_path = req.get_arg("file");

        // Check if the file exists
        std::ifstream file(file_path);
        if (!file.good()) {
            return std::shared_ptr<http_response>(new string_response("File not found", 404));
        }

        // Create a zip archive in memory
        zip_t* archive = zip_open("archive.zip", ZIP_CREATE | ZIP_TRUNCATE, nullptr);
        if (!archive) {
            return std::shared_ptr<http_response>(new string_response("Failed to create zip archive", 500));
        }

        // Add the file to the zip archive
        zip_source_t* source = zip_source_file(archive, file_path.c_str(), 0, -1);
        if (!source || zip_file_add(archive, file_path.c_str(), source, ZIP_FL_ENC_UTF_8) < 0) {
            zip_source_free(source);
            zip_close(archive);
            return std::shared_ptr<http_response>(new string_response("Failed to add file to zip archive", 500));
        }

        // Close the zip archive
        if (zip_close(archive) != 0) {
            return std::shared_ptr<http_response>(new string_response("Failed to close zip archive", 500));
        }

        // Read the contents of the zip archive into a string
        std::ifstream zip_file("archive.zip", std::ios::binary);
        std::stringstream buffer;
        buffer << zip_file.rdbuf();
        std::string zip_contents = buffer.str();

        // Create and return the response with the contents of the zip archive
        auto response = std::shared_ptr<string_response>(new string_response(zip_contents, 200));
        response->with_header("Content-Type", "application/zip");
        response->with_header("Content-Disposition", "attachment; filename=archive.zip");
        return response;
    }
};

int main() {
    webserver server = create_webserver(8080);

    file_download_resource resource;
    server.register_resource("/download", &resource);

    server.start(true);

    return 0;
}
```
This code creates an HTTP server that listens on port `8080` and registers a `/download` resource that handles `GET`
requests. When a `GET` request is received with a `file` argument specifying the path of the file to download, the
server checks if the file exists and creates a zip archive containing the file. The contents of the zip archive are then sent as the response with appropriate headers to trigger a download in the web browser.

You can compile and run this program on an embedded Linux system with `libhttpserver`, `libmicrohttpd`, and `libzip`
installed. You can also modify this code to add additional features such as running the server in LAN, providing a date selector for users to select the date range for log files to download, and adding a "download all" button to download all log files from the device. I hope this helps! Let me know if you have any questions or need further assistance. 😊

Source: Conversation with Bing, 9/1/2023
(1) GitHub - etr/libhttpserver: C++ library for creating an embedded Rest .... https://github.com/etr/libhttpserver.
(2) Libmicrohttpd - GNU Project - Free Software Foundation. https://www.gnu.org/software/libmicrohttpd/.
(3) A C++ Embedded Web Server - CodeProject. https://www.codeproject.com/articles/29290/a-c-embedded-web-server.
(4) eidheim/Simple-Web-Server - GitHub. https://github.com/eidheim/Simple-Web-Server.
************************************************************************/