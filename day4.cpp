#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "main.h"

void day_four_part_two_solve() {
    std::string input_line;
    int fully_contained_count = 0;

    std::ifstream input_file("InputFiles/Day4_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {
        std::istringstream input_stream(input_line);
        std::vector<int> input_vector;

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ',');
            std::istringstream substring_stream(substring);

            while (substring_stream.good()) {
                std::string string_number;
                getline(substring_stream, string_number, '-');
                input_vector.push_back(std::stoi(string_number));
            }
        }

        if ((input_vector[0] >= input_vector[2] and input_vector[0] <= input_vector[3]) or
            (input_vector[1] >= input_vector[2] and input_vector[1] <= input_vector[3]) or
            (input_vector[2] >= input_vector[0] and input_vector[2] <= input_vector[1]) or
            (input_vector[3] >= input_vector[0] and input_vector[3] <= input_vector[1])) {
            fully_contained_count++;
        }
    }

    std::cout << "Part 2: " << fully_contained_count << std::endl;
    input_file.close();
}

void day_four_solve() {
    std::string input_line;
    int fully_contained_count = 0;

    std::ifstream input_file("InputFiles/Day4_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {
        std::istringstream input_stream(input_line);
        std::vector<int> input_vector;

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ',');
            std::istringstream substring_stream(substring);

            while (substring_stream.good()) {
                std::string string_number;
                getline(substring_stream, string_number, '-');
                input_vector.push_back(std::stoi(string_number));
            }
        }

        if ((input_vector[0] >= input_vector[2] and
             input_vector[1] <= input_vector[3]) or
            (input_vector[0] <= input_vector[2] and
             input_vector[1] >= input_vector[3])) {
            fully_contained_count++;
        }

    }

    std::cout << "Part 1: " << fully_contained_count << std::endl;
    input_file.close();

    day_four_part_two_solve();
}

