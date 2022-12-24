#include <iostream>
#include <fstream>
#include <string>
#include "main.h"

void day_three_part_two_solve() {
    std::string input_line;
    int priority_sum = 0;

    std::ifstream input_file("InputFiles/Day3_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {
        bool found = false;

        std::string line_two, line_three;
        getline(input_file, line_two);
        getline(input_file, line_three);

        for (char one: input_line) {
            for (char two: line_two) {
                for (char three: line_three) {
                    if (one == two and two == three and not found) {
                        found = true;

                        if (int(one) < 97) {
                            priority_sum += int(one) - 38;
                        } else {
                            priority_sum += int(one) - 96;
                        }
                    }
                }
            }
        }
    }

    std::cout << "Part 2: " << priority_sum << std::endl;
    input_file.close();
}

void day_three_solve() {
    std::string input_line;
    int priority_sum = 0;

    std::ifstream input_file("InputFiles/Day3_Input.txt");

    if (!input_file) std::cerr << "Could not open the file!" << std::endl;

    while (getline(input_file, input_line)) {
        bool found = false;

        for (int i = 0; i < input_line.length() / 2; i++) {
            for (int a = int(input_line.length() / 2); a < input_line.length(); a++) {
                if (input_line[i] == input_line[a] and not found) {
                    found = true;

                    if (int(input_line[i]) < 97) {
                        priority_sum += int(input_line[i]) - 38;
                    } else {
                        priority_sum += int(input_line[i]) - 96;
                    }
                }
            }
        }
    }

    std::cout << "Part 1: " << priority_sum << std::endl;
    input_file.close();

    day_three_part_two_solve();
}

