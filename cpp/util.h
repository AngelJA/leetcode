#ifndef CPP_UTIL_H_
#define CPP_UTIL_H_

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int test_number = 0;

template <typename T> void print(const T& v) {
    std::cout << v;
}

template <typename T> void print(const vector<T>& vec) {
    // recursive function to print vectors
    std::cout << "[";
    if (vec.size()) {
        for (auto v = vec.begin(); v != vec.end() - 1; ++v) {
            print(*v);
            std::cout << ", ";
        }
        print(vec.back());
    }
    std::cout << "]";
}

template <typename T> void printFailed(
        const T& input,
        const T& expected) {
    std::cout << "input: ";
    print(input);
    std::cout << "\n";
    std::cout << "expected: ";
    print(expected);
    std::cout << "\n\n";
}

template <typename T> bool test(const T& input, const T& expected) {
    ++test_number;
    if (input == expected) {
        std::cout << "test " << test_number << " passed" << "\n\n";
        return true;
    }
    std::cout << "test " << test_number << " failed\n";
    printFailed(input, expected);
    return false;
}

#endif  // CPP_UTIL_H_
