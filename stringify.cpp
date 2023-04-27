//
// Created by juliv on 27.04.2023.
//

#include "stringify.h"

#include <algorithm>

std::string replaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}

std::string stringify(const std::string& input){
    std::string s = input;

    // Remove
    s = replaceAll(s, "\\", "\\\\");

    // Remove "
    s = replaceAll(s, "\"", "\\\"");


    return s;
}

std::string makeIncludeGuard(std::filesystem::path path){
    std::string name = path.generic_string();
    name = replaceAll(name, "/", "_");
    name = replaceAll(name, ".", "_");
    std::transform(name.begin(), name.end(), name.begin(), ::toupper);
    name += "_TEMPLATE_EMBED_GENERATED_H";
    return name;
}