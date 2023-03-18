//
// Created by Julius on 18.03.2023.
//

#include "Models/HeatingTimeslot.h"
#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello, world!" << std::endl;
    HeatingTimeslot slot;
    std::cout << "Duration" << slot.getDuration() << std::endl;
    return 0;
}