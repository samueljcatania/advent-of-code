#include <sstream>
#include <vector>
#include <set>
#include "main.h"


void update_knots(std::vector<std::pair<int, int>> &knots, std::set<std::pair<int, int>> &visited) {
    for (int a = 1; a < 10; a++) {
        if (knots[a].first - 2 == knots[a - 1].first and knots[a].second - 2 == knots[a - 1].second) {
            knots[a].first = knots[a].first - 1;
            knots[a].second = knots[a].second - 1;

        } else if (knots[a].first + 2 == knots[a - 1].first and knots[a].second - 2 == knots[a - 1].second) {
            knots[a].first = knots[a].first + 1;
            knots[a].second = knots[a].second - 1;

        } else if (knots[a].first - 2 == knots[a - 1].first and knots[a].second + 2 == knots[a - 1].second) {
            knots[a].first = knots[a].first - 1;
            knots[a].second = knots[a].second + 1;

        } else if (knots[a].first + 2 == knots[a - 1].first and knots[a].second + 2 == knots[a - 1].second) {
            knots[a].first = knots[a].first + 1;
            knots[a].second = knots[a].second + 1;

        } else if (knots[a].first - 2 == knots[a - 1].first) {
            knots[a].first = knots[a].first - 1;

            if (knots[a - 1].second != knots[a].second) {
                knots[a].second = knots[a - 1].second;
            }
        } else if (knots[a].first + 2 == knots[a - 1].first) {
            knots[a].first = knots[a].first + 1;

            if (knots[a - 1].second != knots[a].second) {
                knots[a].second = knots[a - 1].second;
            }
        } else if (knots[a].second + 2 == knots[a - 1].second) {
            knots[a].second = knots[a].second + 1;

            if (knots[a - 1].first != knots[a].first) {
                knots[a].first = knots[a - 1].first;
            }
        } else if (knots[a].second - 2 == knots[a - 1].second) {
            knots[a].second = knots[a].second - 1;

            if (knots[a - 1].first != knots[a].first) {
                knots[a].first = knots[a - 1].first;
            }
        }
        visited.insert(knots[9]);
    }
}

void day_nine_part_two_solve() {
    std::vector<std::pair<int, int>> knots(10, std::pair<int, int>(0, 0));
    std::set<std::pair<int, int>> visited;
    visited.insert(knots[9]);

    std::string input_line;
    std::ifstream input_file("InputFiles/Day9_Input.txt");

    while (getline(input_file, input_line)) {
        std::vector<std::string> split_string;
        std::istringstream input_stream(input_line);

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ' ');
            split_string.push_back(substring);
        }

        switch (split_string[0][0]) {

            case 'L':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    knots[0].first = knots[0].first - 1;

                    update_knots(knots, visited);
                }
                break;

            case 'R':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    knots[0].first = knots[0].first + 1;

                    update_knots(knots, visited);
                }
                break;

            case 'U':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    knots[0].second = knots[0].second + 1;

                    update_knots(knots, visited);
                }
                break;

            case 'D':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    knots[0].second = knots[0].second - 1;

                    update_knots(knots, visited);
                }
                break;

            default:
                break;
        }
    }
    std::cout << "Part 2: " << visited.size() << std::endl;
    input_file.close();
}

void day_nine_solve() {
    std::pair<int, int> head(0, 0);
    std::pair<int, int> tail(0, 0);
    std::set<std::pair<int, int>> visited;
    visited.insert(tail);

    std::string input_line;
    std::ifstream input_file("InputFiles/Day9_Input.txt");

    while (getline(input_file, input_line)) {
        std::vector<std::string> split_string;
        std::istringstream input_stream(input_line);

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ' ');
            split_string.push_back(substring);
        }

        switch (split_string[0][0]) {

            case 'L':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    head.first = head.first - 1;

                    if (tail.first - 2 == head.first) {
                        tail.first = tail.first - 1;

                        if (head.second != tail.second) {
                            tail.second = head.second;
                        }
                        visited.insert(tail);
                    }
                }
                break;

            case 'R':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    head.first = head.first + 1;

                    if (tail.first + 2 == head.first) {
                        tail.first = tail.first + 1;

                        if (head.second != tail.second) {
                            tail.second = head.second;
                        }
                        visited.insert(tail);
                    }
                }
                break;

            case 'U':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    head.second = head.second + 1;

                    if (tail.second + 2 == head.second) {
                        tail.second = tail.second + 1;

                        if (head.first != tail.first) {
                            tail.first = head.first;
                        }
                        visited.insert(tail);
                    }
                }
                break;

            case 'D':

                for (int i = 0; i < std::stoi(split_string[1]); i++) {
                    head.second = head.second - 1;

                    if (tail.second - 2 == head.second) {
                        tail.second = tail.second - 1;

                        if (head.first != tail.first) {
                            tail.first = head.first;
                        }
                        visited.insert(tail);
                    }
                }
                break;

            default:
                break;
        }
    }
    std::cout << "Part 1: " << visited.size() << std::endl;
    input_file.close();

    day_nine_part_two_solve();
}

