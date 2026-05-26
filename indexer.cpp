//
// Created by Alec Desjardins on 5/23/26.
//
#include <string>
#include <string_view>
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, std::vector<std::string> > index(
    const std::string_view directory)
{
    std::unordered_map<std::string, std::vector<std::string> > index;

    if (std::filesystem::path p = directory; !std::filesystem::exists(p)) {
        std::cout << "Directory does not exists. Will not index" << '\n';
        return index;
    }

    std::cout << "Indexing: " << directory << '\n';

    // TODO implement own recursing directory iterator
    // TODO implement additional options like: ignoring hidden dirs or ignoring specific directories (aka target folders)
    for (const std::filesystem::directory_entry &entry:
         std::filesystem::recursive_directory_iterator(directory)) {
        if (const std::string filename = entry.path().filename(); index.
            contains(filename))
            index[filename].push_back(entry.path());
        else
            index.insert({
                filename,
                std::vector<std::string>{entry.path()}
            });
    }

    return index;
}
