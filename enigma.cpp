#include "Enigma.h"
#include "RotorFabric.h"
#include "Rotor.h"
#include "Reflector.h"
#include "Keyboard.h"

#include <iostream>

Enigma::Enigma(int *r, int n) {
    RotorFabric* rf = new RotorFabric();
    for(int i = 0; i < 3; i++) {
        rotors[i] = new Rotor(rf, r[i]);
    }
    reflector = new Reflector(rf, n);
    delete rf;
    keyboard = new Keyboard();
    pos = new int[3];
}

void Enigma::setCode(int* code) {
    for(int i = 0; i < 3; i++) {
        pos[i] = code[i];
    }
}

void Enigma::listen() {
    char* buffer = keyboard->input();
    for(char* c = buffer; *c != '\0'; c++) {
        *c = process(*c);
    }
    print(buffer);
}

char Enigma::process(char c) {
    for(int i = 0, a = 1; i >= 0; i += a) {
        c = rotors[i]->process(c, pos[i]);
        if(i == 2) {
            c = reflector->process(c);
            a = -1;
        }
    }
    increment();
    return c;
}

void Enigma::increment() {
    if(++pos[0] == 26) {
        pos[0] = 0;
        if(++pos[1] == 26) {
            pos[1] = 0;
            if(++pos[2] == 26) {
                pos[2] = 0;
            }
        }
    }
}

void Enigma::print(char* buffer) {
    std::cout << buffer << "\n";
}

Enigma::~Enigma() {
    for(auto rotor : rotors) {
        delete rotor;
    }
    delete reflector; 
    delete keyboard;
    delete[] pos;
}