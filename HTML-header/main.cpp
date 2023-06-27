#include <iostream>
#include <cpr/cpr.h>
#include <string>

int main() {
    cpr::Response r = cpr::Get(cpr::Url("http://httpbin.org/html"),
                               cpr::Header({{"Accept", "text/html"}}));

    std::string responseText = r.text;
    std::string title;

    // Find the start and end positions of the <h1> tags
    size_t start = responseText.find("<h1>");
    size_t end = responseText.find("</h1>");

    if (start != std::string::npos && end != std::string::npos) {
        // Extract the text between the <h1> tags
        title = responseText.substr(start + 4, end - start - 4);
    } else {
        // If <h1> tags are not found, set a default title
        title = "Title Not Found";
    }

    std::cout << "Title: " << title << std::endl;

    return 0;
}
