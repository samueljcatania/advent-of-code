#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "main.h"

void day_six_part_two_solve() {
    std::string input_line;
    std::vector<char> buffer;

    std::ifstream input_file("InputFiles/Day6_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    getline(input_file, input_line);

    for (int i = 0; i < input_line.length(); i++) {

        int n_remove = 0;
        for (int x = 0; x < buffer.size(); x++) {
            if (buffer[x] == input_line[i]) {
                n_remove = x + 1;
            }
        }

        for (int z = 0; z < n_remove; z++) {
            buffer.erase(buffer.begin());
        }

        buffer.push_back(input_line[i]);

        if (buffer.size() == 14) {
            std::cout << "Part 2: " << i + 1 << std::endl;
            i = int(input_line.length());
        }
    }
    input_file.close();

}

void day_six_solve() {
    std::string input_line;
    std::vector<char> buffer;

    std::ifstream input_file("InputFiles/Day6_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    getline(input_file, input_line);

    for (int i = 0; i < input_line.length(); i++) {

        int n_remove = 0;
        for (int x = 0; x < buffer.size(); x++) {
            if (buffer[x] == input_line[i]) {
                n_remove = x + 1;
            }
        }

        for (int z = 0; z < n_remove; z++) {
            buffer.erase(buffer.begin());
        }

        buffer.push_back(input_line[i]);

        if (buffer.size() == 4) {
            std::cout << "Part 1: " << i + 1 << std::endl;
            i = int(input_line.length());
        }
    }
    input_file.close();

    day_six_part_two_solve();
}

