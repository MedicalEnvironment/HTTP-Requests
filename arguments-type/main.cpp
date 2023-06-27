#include <iostream>
#include <cpr/cpr.h>
#include <map>

int main() {
    std::map<std::string, std::string> arguments;
    std::string name, value;

    while (true) {
        std::cout << "Enter argument name (or 'post' or 'get' to finish): ";
        std::cin >> name;

        if (name == "post" || name == "get") {
            break;
        }

        std::cout << "Enter argument value: ";
        std::cin >> value;

        arguments[name] = value;
    }

    cpr::Response response;
    if (name == "post") {
        std::vector<cpr::Pair> pairs;
        for (const auto& argument : arguments) {
            pairs.emplace_back(cpr::Pair(argument.first, argument.second));
        }
        cpr::Payload payload(pairs.begin(), pairs.end());
        response = cpr::Post(cpr::Url("http://httpbin.org/post"), payload);
    } else if (name == "get") {
        std::string url = "http://httpbin.org/get?";
        for (const auto& argument : arguments) {
            url += argument.first + "=" + argument.second + "&";
        }
        response = cpr::Get(cpr::Url(url));
    }

    std::cout << "Server Response:" << std::endl;
    std::cout << response.text << std::endl;

    return 0;
}
