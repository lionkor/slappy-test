#include <iostream>

int main() {
    std::cout << "life is like ";
    for (char c : "a box of chocolates") {
        std::cout << c;
    }
    std::cout << ", you never know what you're gonna get!" << std::endl;
}
