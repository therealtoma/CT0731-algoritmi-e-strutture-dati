#include <iostream>
#include <vector>

void print_array(std::vector<int> arr) {
    std::cout << "[ ";
    for(int i = 0; i < arr.size(); ++i) {
        std::cout << arr.at(i) << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> insertion_sort(std::vector<int> arr) {
    for(int i = 1; i < arr.size(); i++) {
        int key = arr.at(i);
        int j = i - 1;

        while(j >= 0 && key < arr.at(j)) {
            arr.at(j + 1) = arr.at(j);
            j--;
        }
        arr.at(j + 1) = key;
    }

    return arr;
}

int main() {

    std::vector<int> arr;
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(1);

    print_array(arr);

    arr = insertion_sort(arr);

    print_array(arr);

    return 0;
}