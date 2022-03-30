#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <vector>

int key(int argc, char* argv[], const char* key) {
    for (int i = 0; i < argc; ++i)
        if (!strcmp(argv[i], key))
            return i;
    return 0;
}

int main(int argc, char* argv[]) {
    if (key(argc, argv, "-h") || argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [-o <output_file>] <input_file>" << std::endl;
        return 0;
    }

    size_t count = 0;
    std::map<size_t, size_t> size_distribution;
    std::map<size_t, std::set<std::string>> words_by_size;

    std::ifstream input(argv[argc-1]);
    std::string line;
    while (std::getline(input, line)) {
        std::for_each(line.begin(), line.end(), [](char& ch) {
            switch (ch) {
            case ',':
            case '.':
            case ':':
            case '!':
                ch = ' ';
            }
            return ch;
            });

        std::stringstream stream = std::stringstream(line);
        std::string word;
        while (stream >> word) {
            size_t size = word.size();

            ++size_distribution[size];
            ++count;
            words_by_size[size].insert(word);
        }
    }

    std::vector<size_t> size_distribution_reverse(size_distribution.size());
    size_t it = 0;
    for (auto& [size, count] : size_distribution) {
        size_distribution_reverse[it++] = size;
    }

    auto by_count = [&size_distribution](size_t lhs, size_t rhs) {
        return size_distribution[lhs] < size_distribution[rhs];
    };

    std::sort(size_distribution_reverse.begin(),
        size_distribution_reverse.end(), by_count);

    std::ostream* output;
    int k;
    if (k = key(argc, argv, "-o")) {
        output = new std::ofstream(argv[k + 1]);
    }
    else {
        output = &std::cout;
    }

    for (auto it : size_distribution_reverse) {
        if (10 * size_distribution[it] >= count) {
            for (auto& word : words_by_size[it]) {
                (*output) << size_distribution[it]
                    << ' ' << word << ' ' << '\n';
            }
        }
    }

    if (output != &std::cout) {
        delete output;
    }

    return 0;
}

