//
// Created by juliv on 27.04.2023.
//

#ifndef TEMPLATE_EMBED_STRINGIFY_H
#define TEMPLATE_EMBED_STRINGIFY_H

#include <string>
#include <filesystem>

std::string makeIncludeGuard(std::filesystem::path path);
std::string stringify(const std::string& input);

#endif //TEMPLATE_EMBED_STRINGIFY_H
