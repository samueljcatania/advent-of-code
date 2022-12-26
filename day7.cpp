#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "main.h"

void day_seven_part_two_solve() {


}

void day_seven_solve() {
    std::string input_line;
    std::vector<char> buffer;

    std::ifstream input_file("InputFiles/Day7_Input.txt");

    getline(input_file, input_line);

    input_file.close();

    day_seven_part_two_solve();
}

