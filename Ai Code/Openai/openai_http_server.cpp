#include <zip.h>

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/filesystem.hpp>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;
namespace fs = boost::filesystem;

void handle_request(http::request<http::string_body> const& req,
http::response<http::string_body>& res) {
    if (req.method() == http::verb::get && req.target() == "/download") {
        std::string zip_path = "/tmp/logs.zip";

// Create a ZIP archive with log files.
int err;
zip_t* archive = zip_open(zip_path.c_str(), ZIP_CREATE, &err);

if (archive == nullptr) {
    res.result(http::status::internal_server_error);
    return;
}

for (fs::directory_iterator it("log_folder"), end; it != end; ++it) {
    zip_file_add(archive, it->path().filename().string().c_str(),ZIP_FL_ENC_UTF_8);
}

zip_close(archive);

// Read ZIP file to send as HTTP response.
fs::ifstream zip_file(zip_path, std::ios::binary);
std::string zip_content((std::istreambuf_iterator<char>(zip_file)),std::istreambuf_iterator<char>());
res.body() = zip_content;
res.set(http::field::content_type, "application/zip");
res.result(http::status::ok);
    } else {
        res.result(http::status::not_found);
    }
}

int main() {
    boost::asio::io_context ioc;
    tcp::acceptor acceptor(ioc, {tcp::v4(), 8080});

    for (;;) {
        tcp::socket socket(ioc);
        acceptor.accept(socket);
        http::request<http::string_body> req;
        http::read(socket, req);
        http::response<http::string_body> res;
        handle_request(req, res);
        http::write(socket, res);
        socket.shutdown(tcp::socket::shutdown_send);
    }
    return 0;
}

/***********************************************************************
Implementing a C++ web server to provide HTTP file download services in a LAN requires several libraries and
components. In this example, I'm assuming that you've installed the `Boost.Asio` library for networking and
`Boost.Beast` for HTTP protocol handling. We will also use `libzip` for ZIP file creation.

Here is a minimal C++ code snippet to achieve your requirements:

```cpp
#include <zip.h>

#include <boost/asio.hpp>
#include <boost/beast.hpp>
#include <boost/filesystem.hpp>

using tcp = boost::asio::ip::tcp;
namespace http = boost::beast::http;
namespace fs = boost::filesystem;

void handle_request(http::request<http::string_body> const& req,
http::response<http::string_body>& res) {
    if (req.method() == http::verb::get && req.target() == "/download") {
        std::string zip_path = "/tmp/logs.zip";

// Create a ZIP archive with log files.
int err;
zip_t* archive = zip_open(zip_path.c_str(), ZIP_CREATE, &err);

if (archive == nullptr) {
    res.result(http::status::internal_server_error);
    return;
}

for (fs::directory_iterator it("log_folder"), end; it != end; ++it) {
    zip_file_add(archive, it->path().filename().string().c_str(),ZIP_FL_ENC_UTF_8);
}

zip_close(archive);

// Read ZIP file to send as HTTP response.
fs::ifstream zip_file(zip_path, std::ios::binary);
std::string zip_content((std::istreambuf_iterator<char>(zip_file)),std::istreambuf_iterator<char>());
res.body() = zip_content;
res.set(http::field::content_type, "application/zip");
res.result(http::status::ok);
    } else {
        res.result(http::status::not_found);
    }
}

int main() {
    boost::asio::io_context ioc;
    tcp::acceptor acceptor(ioc, {tcp::v4(), 8080});

    for (;;) {
        tcp::socket socket(ioc);
        acceptor.accept(socket);
        http::request<http::string_body> req;
        http::read(socket, req);
        http::response<http::string_body> res;
        handle_request(req, res);
        http::write(socket, res);
        socket.shutdown(tcp::socket::shutdown_send);
    }
    return 0;
}
```

This is a basic example, which can be built upon. There are many missing pieces, such as:

- Exception handling
- Multi-threading or asynchronous handling of multiple clients
- Creating ZIP files with content from disk
- Date filtering for logs

To build the code, you need to link against Boost.Asio, Boost.Beast, and libzip. Save the above code into a file
named `http_server.cpp` and run:

```bash
g++ http_server.cpp -o http_server -lboost_system -lzip
```

After compiling, run your program and go to `http://<your-embedded-linux-ip>:8080/download` from a browser in the
same LAN to download the ZIP file.

Please install the necessary libraries before running the code. This is just a basic outline; a full production
system would require more comprehensive features, like authentication, validation, and so on.
************************************************************************/

