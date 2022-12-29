#include <sstream>
#include <vector>
#include <set>
#include "main.h"


void day_nine_part_two_solve() {

}

void day_nine_solve() {
    std::pair<int, int> head(0, 0);
    std::pair<int, int> tail(0, 0);
    std::set<std::pair<int, int>> visited;
    visited.insert(tail);

    std::string input_line;
    std::ifstream input_file("InputFiles/Day9_Input.txt");

    while (getline(input_file, input_line)) {
        std::istringstream input_stream(input_line);

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ' ');

            switch (substring[0]) {
                case 'L':

                    for (int i = 0; i < substring[1] - '0'; i++) {
                        head.first = head.first - 1;
                    }


                    break;

                case 'R':

                    for (int i = 0; i < substring[1] - '0'; i++) {
                        head.first = head.first + 1;
                    }
                    break;

                case 'U':

                    for (int i = 0; i < substring[1] - '0'; i++) {
                        head.second = head.second + 1;
                    }
                    break;

                case 'D':

                    for (int i = 0; i < substring[1] - '0'; i++) {
                        head.second = head.second - 1;
                    }
                    break;

                default:
                    break;

            }
        }
    }


    std::cout << "Part 1: " << visited.size() << std::endl;
    input_file.close();

    day_nine_part_two_solve();
}

