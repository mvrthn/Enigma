#include "RotorFabric.h"

#include <cstring>
#include <iostream>

RotorFabric::RotorFabric() {
    tables = new char[5 * 27 + 1];
    strcpy(tables, "EKMFLGDQVZNTOWYHXUSPAIBRCJ0AJDKSIRUXBLHWTMCQGZNPYFVOE0BDFHJLCPRTXVZNYEIWGAKMUSQO0ESOVPZJAYQUIRHXLNFTGKDCMWB0VZBRGITYUPSDNHLXAWMJQOFECK0");
    reflectors = new char[3 * 27 + 1];
    strcpy(reflectors, "EJMZALYXVBWFCRQUONTSPIKHGD0YRUHQSLDPXNGOKMIEBFZCWVJAT0FVPJIAOYEDRZXWGCTKUQSBNMHL0");
}

void RotorFabric::createRotor(char* str, int n) {
    for(char* c = tables + n * 27; *c != '0'; c++) {
        *str++ = *c;
    }
}

void RotorFabric::createReflector(char* str, int n) {
    for(char* c = reflectors + n * 27; *c != '0'; c++) {
        *str++ = *c;
    }
}

RotorFabric::~RotorFabric() {
    delete[] tables;
    delete[] reflectors;
}