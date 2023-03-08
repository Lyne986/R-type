#include "Utils/JSON.hpp"
#include <iostream>

namespace RT::GE::Utils {

    void JSON::open(std::string path)
    {
        std::ifstream file(path);
        if (!file.is_open()) {
            std::cout << "JSON: File is not open " << path << std::endl;
            file.close();
            this->open(path);
            return;
        }
        file >> this->data;
        file.close();
    }

    JSON::JSON(std::string path) {
        std::cout << "path " << path << std::endl;
        if (path.empty()) {
            std::cout << "JSON: Path is empty" << std::endl;
            return;
        }
        try {
            this->open(path);
        } catch (std::exception &e) {
            std::cerr << "(Error while reading JSON file: )" << e.what() << std::endl;
        }
    }

    json JSON::getData() {
        try {
            return this->data;
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            return nullptr;
        }
    }
};