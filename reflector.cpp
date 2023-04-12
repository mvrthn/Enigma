#include "Reflector.h"

#include <iostream>

Reflector::Reflector(RotorFabric* rf, int n) {
    connections = new char[26];
    rf->createReflector(connections, n);
}

char Reflector::process(char c) {
    return connections[c - 'A'];
}

Reflector::~Reflector() {
    delete[] connections;
}