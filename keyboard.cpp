#include "Keyboard.h"

#include <cstdio>

Keyboard::Keyboard() {
    buffer = new char[128];
}

char* Keyboard::input() {
    for(int i = 0; i < 128; i++) {
        char c = (char) getchar();
        if(c == '\n' || c == '\0') {
            *(buffer + i) = '\0';
            break;
        }
        if(c >= 'A' && c <= 'Z') {
            *(buffer + i) = c; 
            continue;
        }
        if(c >= 'a' && c <= 'z') {
            *(buffer + i) = c - 32;
            continue;
        }
        i--;
    }
    return buffer;
}

Keyboard::~Keyboard() {
    delete[] buffer;
}