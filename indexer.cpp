//
// Created by Alec Desjardins on 5/23/26.
//
#include <string>
#include <string_view>
#include <filesystem>
#include <iostream>
#include <unordered_map>
#include <vector>

void recurse(std::unordered_map<std::string, std::vector<std::string> > &index,
             const std::filesystem::directory_entry &current)
{
    if (current.is_regular_file()) {
        const auto &path{current.path()};
        if (const std::string filename = path.filename(); index.
            contains(filename))
            index[filename].push_back(path);
        else
            index.insert({
                filename,
                std::vector<std::string>{path}
            });
        return;
    }

    std::error_code ec{};
    if (current.is_directory()) {
        for (auto const &dir_entry: std::filesystem::directory_iterator
             {current, ec})
            recurse(index, dir_entry);
    }
}

std::unordered_map<std::string, std::vector<std::string> > index(
    const std::string_view directory_path)
{
    std::unordered_map<std::string, std::vector<std::string> > index{};

    const std::filesystem::directory_entry directory_root{directory_path};

    if (!directory_root.exists()) {
        return index;
    }

    std::cout << "indexing: " << directory_root << '\n';

    recurse(index, directory_root);

    const std::locale us_locale("en_US.UTF-8");

    std::cout << "indexed " << std::format(us_locale, "{:L}", index.size()) << " file(s)." << '\n';

    return index;
}
