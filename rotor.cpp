#include "Rotor.h"

#include <iostream>

Rotor::Rotor(RotorFabric* rf, int n) {
    connections = new char[26];
    rf->createRotor(connections, n);
}

char Rotor::process(char c, int pos) {
    return connections[c - 'A' + pos];
}

Rotor::~Rotor() {
    delete[] connections;
}