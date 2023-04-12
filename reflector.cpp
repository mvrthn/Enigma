#include "Reflector.h"

#include <iostream>

Reflector::Reflector(RotorFabric* rf, int n) {
    connections = new char[26];
    rf->createReflector(connections, n);
}

void Reflector::print() {
    std::cout << "Reflector: [";
    for(int i = 0; i < 26; i++) {
        std::cout << connections[i];
    }
    std::cout << "]\n";
}

char Reflector::process(char c) {
    return connections[c - 'A'];
}

Reflector::~Reflector() {
    delete[] connections;
}