#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include <vector>


// only problem with a whitespace

std::string get_number_representation(const std::string &input, std::map<char, std::string> &cell_phone_map) {
    std::stringstream ss;
    char previous = '+';
    std::string temp_value;
    for(const char &symbol: input) {
        temp_value = cell_phone_map[symbol];
        if (previous == temp_value[0]) {
            ss << " ";
        }
        ss << std::move(temp_value);
        previous = temp_value[0];
    }

    return ss.str();
}

std::map<char, std::string> invert_map(const std::map<char, std::string> input_map) {
    std::map<char, std::string> inv_map;
    for(const auto &[key, value]: input_map) {
        int index = 1;
        std::stringstream ss;
        for(const char &letter: value) {
            for(int j = 0; j < index; ++j) ss << std::move(key);
            inv_map[letter] = ss.str();
            ss.clear();
        }
    }
    return inv_map;
}

int main() {
    int N;
    std::cin >> N;

    const std::map<char, std::string> input_map{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"},
        {'0', " "}
    };

    std::map<char, std::string> cell_phone_map = invert_map(input_map);

    std::vector<std::string> input_strings(N);
    std::cin.ignore();
    for(int i = 0; i < N; ++i) {
        std::getline(std::cin, input_strings[i]);
    }
    int counter = 1;
    for(const std::string &istring: input_strings) {
        std::cout << "Case #" << counter << ": " << get_number_representation(istring, cell_phone_map) << std::endl;
        ++counter;
    }
    
    return 0;
}