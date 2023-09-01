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
