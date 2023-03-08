#ifndef __RT_GE_UTILS_JSON_HPP__
    #define __RT_GE_UTILS_JSON_HPP__

    #include "UtilsNamespace.hpp"
    #include <fstream>
    #include <nlohmann/json.hpp>
    #include <string>

    using json = nlohmann::json;

class RT::GE::Utils::JSON {

    private:
    json data;
    bool opened = false;
    void open(std::string path);

    public:
    JSON(std::string path);
    json getData();

};

#endif
