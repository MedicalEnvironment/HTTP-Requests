#include <iostream>
#include <cpr/cpr.h>

int main() {
    //std::string name, city;
    //std::cin >> name >> city;

    bool validCommand = false;
    while(!validCommand) {
        int command;
        std::cout << "Enter the following command: " << "\n";
        std::cout << "-----------------------------" << "\n";
        std::cout << "1 - get " << "2 - post " << "3 - put " << "4 - delete " << "5 - patch" << "\n";
        std::cin >> command;
            if(command == 1) {
                cpr::Response g = cpr::Get(cpr::Url("http://httpbin.org/get"));
                std::cout << g.text << std::endl;
            }else if(command == 2) {
                cpr::Response g = cpr::Post(cpr::Url("http://httpbin.org/post"));
                std::cout << g.text << std::endl;
            }else if(command == 3) {
                cpr::Response g = cpr::Put(cpr::Url("http://httpbin.org/put"));
                std::cout << g.text << std::endl;
            }else if(command == 4) {
                cpr::Response g = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
                std::cout << g.text << std::endl;
            }else if(command == 5) {
                cpr::Response g = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
                std::cout << g.text << std::endl;
            }else{
                std::cout << "Please, input a correct variable" << "\n";
            }
        }


    return 0;
}
