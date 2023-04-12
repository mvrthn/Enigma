#include "Rotor.h"

#include <iostream>

Rotor::Rotor(RotorFabric* rf, int n) {
    connections = new char[26];
    rf->createRotor(connections, n);
}

void Rotor::print() {
    std::cout << "Rotor: [";
    for(int i = 0; i < 26; i++) {
        std::cout << connections[i];
    }
    std::cout << "]\n";
}

char Rotor::process(char c, int pos) {
    return connections[c - 'A' + pos];
}

Rotor::~Rotor() {
    delete[] connections;
}