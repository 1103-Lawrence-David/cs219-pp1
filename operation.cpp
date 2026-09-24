#include "operation.h"


void readFile(ifstream& fp, int& length, string* arrStr, uint32_t* arrHex1, uint32_t* arrHex2){
    string temp, strToHex;
    
    length = 0;

    while (getline(fp, temp)){ // issue with single 
        getline(fp, arrStr[length], ' ');
        
        getline(fp, strToHex, 'x'); //formatting, trashing unnecessary section

        getline(fp, strToHex, ' ');
        uint32_t hextemp = static_cast<uint32_t>(stoul(strToHex));
        arrHex1[length] = hextemp;

        if(getline(fp, strToHex, ' ') ){
            getline(fp, strToHex, ' ');
            arrHex1[length] = static_cast<uint32_t>(stoul(strToHex));
        }
        length++;
    }
}

void ADD(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 + b2;
    cout << std::hex << temp << endl;  
}

void SUB(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 - b2;
    cout << std::hex << temp << endl;
}

void AND(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 & b2;
    cout << std::hex << temp << endl;   
}

void OR(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 | b2;
    cout << std::hex << temp << endl;
}

void XOR(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 ^ b2;
    cout << std::hex << temp << endl;
}

void NOT(uint32_t b){
    uint32_t temp = ~b;
    cout << std::hex << temp << endl;
}

void LSL(uint32_t b, int i){
    if(i > 0 && i < 32){
        uint32_t temp = b << i;
        cout << std::hex << temp << endl;
    }
    else if(i >= 32){
        cout << "second operand must be smaller than 32." << endl;
    }
    else{
        cout << "Second operand must be positive or exist." << endl;
    }
}

void LSR(uint32_t b, int i){
    if(i > 0 && i < 32){
        uint32_t temp = b >> i;
        cout << std::hex << temp << endl;
    }
    else if(i >= 32){
        cout << "second operand must be smaller than 32." << endl;
    }
    else{
        cout << "Second operand must be positive or exist." << endl;
    }
}

void EQ(uint32_t b1, uint32_t b2){
    if(b1 == b2){
        cout << "True" << endl;
    }
    else if (b1 != b2){
        cout << "False" << endl;
    }
    else { //debugging
        cout << "error with EQ" << endl;
    }
}

void LT(uint32_t b1, uint32_t b2){
    if(b1 < b2){
        cout << "True" << endl;
    }
    else if (b1 >= b2){
        cout << "False" << endl;
    }
    else {
        cout << "error with LT" << endl;
    }
}

void GT(uint32_t b1, uint32_t b2){
    if(b1 > b2){
        cout << "True" << endl;
    }
    else if (b1 <= b2){
        cout << "False" << endl;
    }
    else {
        cout << "error with GT" << endl;
    }
}

void display(uint32_t* b, int i){
    for(int index = 0; index < i; index++){
        cout << b[index] << endl;
    }
}