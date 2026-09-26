#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>
#include <fstream>

using namespace std;

void readFile(ifstream&, int&, string*, uint32_t*, uint32_t*, bool*); //needs more work for error mitigation (missing numbers, invalid numbers.)

void ADD(uint32_t, uint32_t);//WORKS
void SUB(uint32_t, uint32_t);//WORKS
void AND(uint32_t, uint32_t); //WORKS
void OR(uint32_t, uint32_t); //WORKS
void XOR(uint32_t, uint32_t); //WORKS
void NOT(uint32_t); //absolutely unfucked
void LSL(uint32_t, int);
void LSR(uint32_t, int);
void EQ(uint32_t, uint32_t);
void LT(uint32_t, uint32_t);
void GT(uint32_t, uint32_t);
void display(uint32_t*, uint32_t*, string*, int, bool*);

void operationSet(string*, uint32_t*, uint32_t*, int, int*, bool*);
bool errCheck(string*, uint32_t*, uint32_t*, int, int);

#endif