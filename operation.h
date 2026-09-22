#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <cstdint>

using namespace std;

void ADD(uint32_t&, uint32_t&);
void SUB(uint32_t&, uint32_t&);
void AND(uint32_t&, uint32_t&);
void OR(uint32_t&, uint32_t&);
void XOR(uint32_t, uint32_t); //WORKS
void NOT(uint32_t); //absolutely fucked
void LSL(uint32_t&, int);
void LSR(uint32_t&, int);
void EQ(uint32_t&, uint32_t&);
void LT(uint32_t&, uint32_t&);
void GT(uint32_t&, uint32_t&);

#endif