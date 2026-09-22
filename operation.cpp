#include "operation.h"

void ADD(uint32_t& b1, uint32_t& b2){

}

void SUB(uint32_t& b1, uint32_t& b2){

}

void AND(uint32_t& b1, uint32_t& b2){

}

void OR(uint32_t& b1, uint32_t& b2){

}

void XOR(uint32_t b1, uint32_t b2){
    b1 ^= b2;
    cout << std::hex << b1 << endl;
}

void NOT(uint32_t b){
    b = !b;
    cout << std::hex << b << endl;
}

void LSL(uint32_t& b, int i){

}

void LSR(uint32_t& b, int i){

}

void EQ(uint32_t& b1, uint32_t& b2){

}

void LT(uint32_t& b1, uint32_t& b2){

}

void GT(uint32_t& b1, uint32_t& b2){

}
