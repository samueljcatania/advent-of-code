#include <sstream>
#include <utility>
#include <vector>
#include <queue>
#include "main.h"

struct Directory {
    std::string name{};
    int size = 0;
    Directory *parent{};
    std::vector<Directory *> children;
};

Directory *new_directory(std::string name, Directory *parent) {
    auto *temp = new Directory;
    temp->name = std::move(name);
    temp->parent = parent;
    return temp;
}

int BFS(Directory *root) {
    int answer = 0;
    std::queue<Directory *> queue;
    queue.push(root);

    while (!queue.empty()) {
        Directory *directory = queue.front();
        queue.pop();

        if (directory->size <= 100000) { answer += directory->size; }

        for (Directory *sub_dir: directory->children) {
            queue.push(sub_dir);
        }
    }
    return answer;
}

void day_seven_part_two_solve(Directory *root) {
    int min_space_needed = 30000000 - (70000000 - root->size);

    int smallest_dir = root->size;
    std::queue<Directory *> queue;
    queue.push(root);

    while (!queue.empty()) {
        Directory *directory = queue.front();
        queue.pop();

        if (directory->size >= min_space_needed and directory->size < smallest_dir) {
            smallest_dir = directory->size;
        }

        for (Directory *sub_dir: directory->children) {
            queue.push(sub_dir);
        }
    }

    std::cout << "Part 2: " << smallest_dir << std::endl;
}

void day_seven_solve() {
    Directory *root = new_directory("root", nullptr);
    Directory *current_directory;
    std::string input_line;

    std::ifstream input_file("InputFiles/Day7_Input.txt");

    while (getline(input_file, input_line)) {
        std::vector<std::string> split_string;
        std::istringstream input_stream(input_line);

        while (input_stream.good()) {
            std::string substring;
            getline(input_stream, substring, ' ');

            split_string.push_back(substring);
        }

        if (split_string[0] == "$") {

            if (split_string[1] == "cd") {

                if (split_string[2] == "/") {
                    current_directory = root;

                } else if (split_string[2] == "..") {
                    current_directory = current_directory->parent;

                } else {
                    Directory *temp = new_directory(split_string[2], current_directory);
                    current_directory->children.push_back(temp);
                    current_directory = temp;
                }
            }

        } else if (split_string[0] != "dir") {
            current_directory->size += std::stoi(split_string[0]);
            Directory *parent = current_directory->parent;

            while (parent != nullptr) {
                parent->size += std::stoi(split_string[0]);
                parent = parent->parent;
            }

        }
    }
    std::cout << "Part 1: " << BFS(root) << std::endl;
    input_file.close();

    day_seven_part_two_solve(root);
}

