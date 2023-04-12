#ifndef KEYBOARD_H
#define KEYBOARD_H

class Keyboard {
public:
    Keyboard();
    char* input();
    ~Keyboard();
private:
    char* buffer;
};

#endif //KEYBOARD_H