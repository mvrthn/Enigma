#include "Enigma.h"

int main() {
    int r[3] = {0, 1, 2};
    int code[3] = {0, 0, 0};
    Enigma enigma(r, 0);
    enigma.setCode(code);
    enigma.listen();
    return 0;
}