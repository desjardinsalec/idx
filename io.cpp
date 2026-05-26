//
// Created by Alec Desjardins on 5/23/26.
//
#include <string>
#include <iostream>

std::string get_input();

std::string get_directory()
{
    std::cout << "Enter directory to index: ";
    return get_input();
}

std::string get_filename()
{
    std::cout << "Enter filename you want: ";
    return get_input();
}

std::string get_input()
{
    std::string input;
    std::cin >> input;
    return input;
}