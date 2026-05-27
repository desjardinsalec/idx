//
// Created by Alec Desjardins on 5/23/26.
//

#ifndef IDX_INDEXER_H
#define IDX_INDEXER_H
#include <string>
#include <unordered_map>
#include <vector>

std::unordered_map<std::string, std::vector<std::string> > index(
    std::string_view directory_path);

#endif //IDX_INDEXER_H
