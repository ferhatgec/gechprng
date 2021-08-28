#include "include/gech_prng.hpp"
#include <iostream>
#include <fstream>

// uptime or time (can be manipulated)
int get_seed() {
    std::ifstream data("/proc/uptime");

    for(std::string temp; std::getline(data, temp);
        ) {
        return std::stoi(temp);
    }

    return time(NULL);
}

int main(int argc, char** argv) noexcept {
    gechprng x;
    x.feed(get_seed());

    std::cout << "Your lucky number: " << x.generate() % 42 << '\n';
}