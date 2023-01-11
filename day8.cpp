#include <vector>
#include "main.h"

struct Tree {
    int height;
    bool visible = false;

    explicit Tree(int height) {
        this->height = height;
    }
};

void free_memory(const std::vector<std::vector<Tree *>>& forest) {
    for (const std::vector<Tree *>& row: forest) {
        for (Tree *tree: row) {
            delete tree;
        }
    }
}

void day_eight_part_two_solve(std::vector<std::vector<Tree *>> forest) {
    int highest_scenic = 0;

    for (int a = 0; a < int(forest.size()); a++) {
        for (int b = 0; b < int(forest[a].size()); b++) {

            int left_view = 0;
            int left_check = b - 1;
            while (left_check >= 0) {
                left_view++;
                if (forest[a][left_check]->height < forest[a][b]->height) { left_check--; }
                else { break; }
            }

            int right_view = 0;
            int right_check = b + 1;
            while (right_check < forest[a].size()) {
                right_view++;
                if (forest[a][right_check]->height < forest[a][b]->height) { right_check++; }
                else { break; }
            }

            int up_view = 0;
            int up_check = a - 1;
            while (up_check >= 0) {
                up_view++;
                if (forest[up_check][b]->height < forest[a][b]->height) { up_check--; }
                else { break; }
            }

            int down_view = 0;
            int down_check = a + 1;
            while (down_check < forest.size()) {
                down_view++;
                if (forest[down_check][b]->height < forest[a][b]->height) { down_check++; }
                else { break; }
            }

            int scenic_score = left_view * right_view * up_view * down_view;

            if (scenic_score > highest_scenic) {
                highest_scenic = scenic_score;
            }
        }
    }
    std::cout << "Part 2: " << highest_scenic << std::endl;

    free_memory(forest);
}

void day_eight_solve() {
    int line_num = 0;
    int total_visible = 0;

    std::string input_line;
    std::vector<std::vector<Tree *>> forest;

    std::ifstream input_file("InputFiles/Day8_Input.txt");

    while (getline(input_file, input_line)) {
        forest.emplace_back();

        for (char c: input_line) {
            forest[line_num].push_back(new Tree(c - '0'));
        }
        line_num++;
    }

    for (int a = 0; a < int(forest.size()); a++) {
        for (int b = 0; b < int(forest[a].size()); b++) {

            int left_check = b - 1;
            while (left_check >= 0) {
                if (forest[a][left_check]->height < forest[a][b]->height) { left_check--; }
                else { break; }
            }

            int right_check = b + 1;
            while (right_check < forest[a].size()) {
                if (forest[a][right_check]->height < forest[a][b]->height) { right_check++; }
                else { break; }
            }

            int up_check = a - 1;
            while (up_check >= 0) {
                if (forest[up_check][b]->height < forest[a][b]->height) { up_check--; }
                else { break; }
            }

            int down_check = a + 1;
            while (down_check < forest.size()) {
                if (forest[down_check][b]->height < forest[a][b]->height) { down_check++; }
                else { break; }
            }

            if (left_check == -1 or right_check == forest[a].size()
                or up_check == -1 or down_check == forest.size()) {
                forest[a][b]->visible = true;
                total_visible++;
            }
        }
    }
    std::cout << "Part 1: " << total_visible << std::endl;
    input_file.close();

    day_eight_part_two_solve(forest);
}

