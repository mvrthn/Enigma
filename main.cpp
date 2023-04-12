#include "Enigma.h"

int main() {
    int r[3] = {0, 1, 2};
    Enigma *enigma = new Enigma(r, 0);
    enigma->printRotors();
    enigma->printReflector();
    delete enigma;
    return 0;
}