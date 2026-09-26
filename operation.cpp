#include "operation.h"


void readFile(ifstream& fp, int& length, string* arrStr, uint32_t* arrHex1, uint32_t* arrHex2, bool* flag1){
    string temp, strToHex;
    char tempChar;
    
    length = 0;
    while (getline(fp, temp)) {
        stringstream ss(temp);
        ss >> arrStr[length];
        int tempI = 0;
        ss.get(tempChar);
        
        if(tempChar == ' '){
            ss >> std::hex >> tempI;
        
            if(tempI >= 0){
                uint32_t hextemp = (uint32_t) tempI;
                arrHex1[length] = hextemp;
            }
            
            else{
                flag1[length] = true;
            }
        }
        else{
            arrHex1[length] == 0;
            arrHex2[length] == 0;
        }
        
        ss.get(tempChar);

        if(tempChar == ' '){
            ss >> std::hex >> tempI;
            if(tempI >= 0){
                uint32_t hextemp = (uint32_t) tempI;
                arrHex2[length] = hextemp;
            }
            else{
                flag1[length] = true;
            }
        }
        else{
            arrHex2[length] == 0;
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

void display(uint32_t* b1, uint32_t* b2, string* s, int i, bool* flag1){
    for(int index = 0; index < i; index++){
        cout << s[index] << "     "  << std::hex << b1[index] << "     " << b2[index] << "     " << flag1[index];
        cout << endl;
    }
}

void operationSet(string* arrStr, uint32_t* b1, uint32_t* b2, int length, int* op, bool* flag2){
   for(int i = 0; i < length; i++){
        if(arrStr[i] == "ADD"){
            op[i] = 1;
        }
        else if(arrStr[i] == "SUB"){
            op[i] = 2;
        }
        else if(arrStr[i] == "AND"){
            op[i] = 3;
        }
        else if(arrStr[i] == "OR"){
            op[i] = 4;
        }
        else if(arrStr[i] == "XOR"){
            op[i] = 5;
        }
        else if(arrStr[i] == "NOT"){
            op[i] = 6;
        }
        else if(arrStr[i] == "LSL"){
            op[i] = 7;
        }
        else if(arrStr[i] == "LSR"){
            op[i] = 8;
        }
        else if(arrStr[i] == "EQ"){
            op[i] = 9;
        }
        else if(arrStr[i] == "LT"){
            op[i] = 10;
        }
        else if(arrStr[i] == "GT"){
            op[i] = 11;
        }
        else{
            op[i] = 0;
        }
    
        flag2[i] = errCheck(arrStr, b1, b2, i, op[i]);
    }
    
   
}

bool errCheck(string* strArr, uint32_t* b1, uint32_t* b2, int pos, int op){ //change to operation run or remove
    switch (op){
        case 0:
            return true;
        case 1:
    }


    return true;
}