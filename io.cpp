//
// Created by Alec Desjardins on 5/23/26.
//
#include <string>
#include <iostream>

std::string get_input();

std::string get_directory()
{
    std::cout << "enter directory to index: ";
    return get_input();
}

std::string get_filename()
{
    std::cout << "enter filename you wish to find: ";
    return get_input();
}

std::string get_input()
{
    std::string input;
    std::cin >> input;
    return input;
}