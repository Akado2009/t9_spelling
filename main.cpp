#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>


// only problem with a whitespace

std::string get_number_representation(const std::string &input, std::map<char, std::string> &cell_phone_map) {
    std::string result;
    char previous = '+';
    std::string temp_value;
    for(const char &symbol: input) {
        temp_value = cell_phone_map[symbol];
        if (previous == temp_value[0]) {
            result += " ";
        }
        result += temp_value;
        previous = temp_value[0];
    }

    return result;
}

std::map<char, std::string> invert_map(const std::map<char, std::string> input_map) {
    std::map<char, std::string> inv_map;
    for(const auto &[key, value]: input_map) {
        int index = 1;
        std::string new_value;
        for(const char &letter: value) {
            for(int j = 0; j < index; ++j) new_value += key;
            inv_map[letter] = new_value;
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