//
// Created by Alec Desjardins on 5/23/26.
//
#include <string>
#include <string_view>
#include <filesystem>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, std::string> index(
    const std::string_view &directory)
{
    std::unordered_map<std::string, std::string> index;

    if (std::filesystem::path p = directory; !std::filesystem::exists(p)) {
        std::cout << "Directory does not exists. Will not index";
        return index;
    }

    std::cout << "Indexing: " << directory << '\n';

    // need to handle colliding filenames
    // O(N) indexing with O(1) lookup
    for (const std::filesystem::directory_entry &entry:
         std::filesystem::recursive_directory_iterator(directory))
        if (std::filesystem::is_regular_file(entry)) {
            index.insert({
                entry.path().filename(),
                entry.path()
            });
        }

    return index;
}
