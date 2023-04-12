#include "Enigma.h"
#include "RotorFabric.h"
#include "Rotor.h"
#include "Reflector.h"

Enigma::Enigma(int *r, int n) {
    RotorFabric* rf = new RotorFabric();
    for(int i = 0; i < 3; i++) {
        rotors[i] = new Rotor(rf, r[i]);
    }
    reflector = new Reflector(rf, n);
    delete rf;
    pos = new int[3];
}

void Enigma::setCode(int* code) {
    for(int i = 0; i < 3; i++) {
        pos[i] = code[i];
    }
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

char Enigma::process(char c) {
    if(!validate(&c)) {
        return '0';
    }
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

bool Enigma::validate(char* c) {
    if(*c >= 'A' && *c <= 'Z') {
        return true;
    } 
    if(*c >= 'a' && *c <= 'z') {
        *c -= 32;
        return true;
    }
    return false;
}

Enigma::~Enigma() {
    for(auto rotor : rotors) {
        delete rotor;
    }
    delete reflector; 
}