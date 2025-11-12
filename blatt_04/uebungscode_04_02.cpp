#include <cmath>
#include <iostream>
#include <string>
#include <vector>

int lies_ganzzahl() {
    std::string wort;
    std::cin >> wort;
    int ganzzahl = 0;
    try {
    ganzzahl = std::stoi(wort);
    } catch (const std::invalid_argument& e) {
    ganzzahl = -1000;
    }
    return ganzzahl;
}

void print_array(const std::vector<int>& arr) { // konstante Referenz zum Vector, da dieser nur ausgelesen und nicht verändert wird
    std::cout << '{' << ' ';
    bool first = true;
    for (const int& element : arr) { // konstante konstante Element-Referenz, da auch die Elemente nur ausgelesen werden
        if (!first) std::cout << ", "; // stellt sicher, dass vor dem ersten Element kein Komma gedruckt wird
        std::cout << std::to_string(element);
        first = false;
    }
    std::cout << " } " << std::endl;
}

void vector_abs(std::vector<int>& arr) { // Call by Reference, um das Array direkt verändern zu können
    int i = 0; // Zählervariable für den Index
    for (const int& element : arr) { // Const Call by Reference, da das Element nur ausgelesen wird
        arr[i] = std::fabs(element);
        i++;
    }
}

void print_array(const std::vector<std::string>& arr) { // konstante Referenz zum Vector, da dieser nur ausgelesen und nicht verändert wird 
    for (const std::string& element : arr) { // konstante konstante Element-Referenz, da auch die Elemente nur ausgelesen werden
        std::cout << element << std::endl;
    }
}

void new_numbers_until_42(std::vector<int>& arr) { // keine konstante Referenz, da das Array verändert werden muss
    int input = lies_ganzzahl();
    while (input != 42) {
        arr.push_back(input);
        input = lies_ganzzahl();
    }
}

int main() {
    std::vector<int> vec = {0, -1, 2, -42};
    vector_abs(vec);
    print_array(vec);
    std::vector<std::string> vec2 = {"Hallo", "Welt", "ebfouhrvbewuovhrbwe"};
    print_array(vec2);
    new_numbers_until_42(vec);
    print_array(vec);
}