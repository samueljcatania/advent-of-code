#include "main.h"

void day_one_part_two_solve() {
    std::string input_line;

    int highest = 0;
    int per_elf_sum = 0;

    std::ifstream input_file("InputFiles/Day1_Input.txt");

    while (getline(input_file, input_line)) {

        if (input_line.empty()) {

            if (per_elf_sum > highest) {
                highest = per_elf_sum;
            }

            per_elf_sum = 0;

        } else {
            per_elf_sum += std::stoi(input_line);
        }
    }

    std::cout << "Part 1: " << highest << std::endl;
    input_file.close();
}


void day_one_solve() {
    std::string input_line;

    int first_highest = 0;
    int second_highest = 0;
    int third_highest = 0;
    int per_elf_sum = 0;

    std::ifstream input_file("InputFiles/Day1_Input.txt");

    while (getline(input_file, input_line)) {

        if (input_line.empty()) {

            if (per_elf_sum > first_highest) {
                third_highest = second_highest;
                second_highest = first_highest;
                first_highest = per_elf_sum;
            } else if (per_elf_sum > second_highest) {
                third_highest = second_highest;
                second_highest = per_elf_sum;
            } else if (per_elf_sum > third_highest) {
                third_highest = per_elf_sum;
            }

            per_elf_sum = 0;

        } else {
            per_elf_sum += std::stoi(input_line);
        }
    }

    std::cout << "Part 2: " << first_highest + second_highest + third_highest << std::endl;
    input_file.close();

    day_one_part_two_solve();
}

