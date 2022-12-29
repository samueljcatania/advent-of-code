#include <sstream>

#include "main.h"

void day_two_part_two_solve() {
    std::string input_line;
    int total_score = 0;

    std::ifstream input_file("InputFiles/Day2_Input.txt");

    while (getline(input_file, input_line)) {

        std::istringstream split_line(input_line);

        char opponent;
        split_line >> opponent;

        char response;
        split_line >> response;

        switch (opponent) {
            case 'A':

                if (response == 'X') {
                    total_score += 3;
                } else if (response == 'Y') {
                    total_score += 1 + 3;
                } else {
                    total_score += 2 + 6;
                }

                break;

            case 'B':

                if (response == 'X') {
                    total_score += 1;
                } else if (response == 'Y') {
                    total_score += 2 + 3;
                } else {
                    total_score += 3 + 6;
                }

                break;

            case 'C':

                if (response == 'X') {
                    total_score += 2;
                } else if (response == 'Y') {
                    total_score += 3 + 3;
                } else {
                    total_score += 1 + 6;
                }

                break;

            default:
                break;
        }
    }

    std::cout << "Part 2: " << total_score << std::endl;
    input_file.close();
}

void day_two_solve() {
    std::string input_line;
    int total_score = 0;

    std::ifstream input_file("InputFiles/Day2_Input.txt");

    while (getline(input_file, input_line)) {

        std::istringstream split_line(input_line);

        char opponent;
        split_line >> opponent;

        char response;
        split_line >> response;

        switch (response) {
            case 'X':
                total_score += 1;

                if (opponent == 'A') {
                    total_score += 3;
                } else if (opponent == 'C') {
                    total_score += 6;
                }

                break;

            case 'Y':
                total_score += 2;

                if (opponent == 'B') {
                    total_score += 3;
                } else if (opponent == 'A') {
                    total_score += 6;
                }

                break;

            case 'Z':
                total_score += 3;

                if (opponent == 'C') {
                    total_score += 3;
                } else if (opponent == 'B') {
                    total_score += 6;
                }

                break;

            default:
                break;
        }
    }

    std::cout << "Part 1: " << total_score << std::endl;
    input_file.close();

    day_two_part_two_solve();
}

