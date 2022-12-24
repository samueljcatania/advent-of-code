#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "main.h"

void day_five_part_two_solve() {
    std::string input_line;
    std::vector<std::vector<char>> all_stacks(9);
    bool stack_input = true;

    std::ifstream input_file("InputFiles/Day5_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {

        if (stack_input) {

            if (input_line.empty()) {
                stack_input = false;

                for (auto &all_stack: all_stacks) {
                    all_stack.pop_back();
                }

            } else {
                int counter = 0;

                for (int i = 1; i < input_line.length(); i += 4) {
                    if (not std::isblank(input_line[i])) {
                        all_stacks[counter].push_back(input_line[i]);

                    }
                    counter++;
                }
            }

        } else {
            std::istringstream input_stream(input_line);
            std::vector<int> instructions;

            while (input_stream.good()) {
                std::string substring;
                getline(input_stream, substring, ' ');
                if (std::regex_match(substring, std::regex("[0-9]+"))) {
                    instructions.push_back(std::stoi(substring));
                }
            }

            std::vector<char> temp_vector;

            for (int i = 0; i < instructions.front(); i++) {
                temp_vector.push_back(all_stacks[instructions[1] - 1].front());
                all_stacks[instructions[1] - 1].erase(all_stacks[instructions[1] - 1].begin());
            }

            for (int i = 0; i < instructions.front(); i++) {
                all_stacks[instructions.back() - 1].insert(all_stacks[instructions.back() - 1].begin(),
                                                           temp_vector.back());
                temp_vector.pop_back();
            }
        }
    }
    std::string top_crates;

    for (auto &all_stack: all_stacks) {
        top_crates += all_stack.front();
    }

    std::cout << "Part 2: " << top_crates << std::endl;
    input_file.close();
}

void day_five_solve() {
    std::string input_line;
    std::vector<std::vector<char>> all_stacks(9);
    bool stack_input = true;

    std::ifstream input_file("InputFiles/Day5_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {

        if (stack_input) {

            if (input_line.empty()) {
                stack_input = false;

                for (auto &all_stack: all_stacks) {
                    all_stack.pop_back();
                }

            } else {
                int counter = 0;

                for (int i = 1; i < input_line.length(); i += 4) {
                    if (not std::isblank(input_line[i])) {
                        all_stacks[counter].push_back(input_line[i]);

                    }
                    counter++;
                }
            }

        } else {
            std::istringstream input_stream(input_line);
            std::vector<int> instructions;

            while (input_stream.good()) {
                std::string substring;
                getline(input_stream, substring, ' ');
                if (std::regex_match(substring, std::regex("[0-9]+"))) {
                    instructions.push_back(std::stoi(substring));
                }
            }

            for (int i = 0; i < instructions.front(); i++) {
                all_stacks[instructions.back() - 1].insert(all_stacks[instructions.back() - 1].begin(),
                                                           all_stacks[instructions[1] - 1].front());
                all_stacks[instructions[1] - 1].erase(all_stacks[instructions[1] - 1].begin());
            }
        }
    }
    std::string top_crates;

    for (auto &all_stack: all_stacks) {
        top_crates += all_stack.front();
    }

    std::cout << "Part 1: " << top_crates << std::endl;
    input_file.close();

    day_five_part_two_solve();

}

