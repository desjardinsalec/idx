#include <iostream>

#include "io.h"
#include "indexer.h"
#include <unordered_map>

int main()
{
    const std::string directory{get_directory()};
    std::unordered_map indexed_dir{index(directory)};
    const std::string filename{get_filename()};

    std::cout << "Here is your path: " << indexed_dir[filename];

    return 0;
}
