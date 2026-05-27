#include <iostream>

#include "io.h"
#include "indexer.h"
#include <unordered_map>
#include <vector>

void print_paths(const std::vector<std::string> &paths)
{
    if (paths.empty()) {
        std::cout << "filename not found in index." << '\n';
        return;
    }
    std::cout << "here are your paths: " << '\n';
    for (const std::string& path : paths)
        std::cout << path << '\n';
}

int main()
{
    const std::string directory{get_directory()};
    std::unordered_map indexed_dir{index(directory)};
    if (indexed_dir.empty()) {
        return 0;
    }

    const std::string filename{get_filename()};
    print_paths(indexed_dir[filename]);

    return 0;
}
