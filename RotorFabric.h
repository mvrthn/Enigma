#ifndef ROTOR_FABRIC_H
#define ROTOR_FABRIC_H

class RotorFabric {
public:
    RotorFabric();
    void createRotor(char* str, int n);
    void createReflector(char* str, int n);
    ~RotorFabric();
private:
    char* tables;
    char* reflectors;
};

#endif //ROTOR_FABRIC_H