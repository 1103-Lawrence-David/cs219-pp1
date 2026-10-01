//Author: David Lawrence
//v 1.0: fully functional
#include "operation.h"
#define SIZE 200
#define READ_FILE "pp1_input.txt"

//Flag is a debugging and logic tool. flag1 = true means there is a negativ enumber somewhere in the file input. 
//flag 2 detects if an operand doesn't exist. if the function is not NOT, it is then determined to be missing operands.
//Flag 3 detects if there are more than 2 operands. If there are, its an immediate fail. It does not attempt to store this information, and instead displays the error by itself.

int main (){
    int length = 0;
    uint32_t bit1[SIZE], bit2[SIZE];
    string arrStr1[SIZE];
    bool flag1[SIZE], flag2[SIZE], flag3[SIZE];

    ifstream fptr(READ_FILE);
    if(!fptr.is_open()){
        cout<< "File could not be opened properly." << endl;
        return 1;
    }
    readFile(fptr,length, arrStr1, bit1, bit2, flag1, flag2, flag3);
    fptr.close();
    
    ifstream fptr2(READ_FILE);
    if(!fptr2.is_open()){
        cout<< "File could not be opened properly." << endl;
        return 1;
    }
    errorCheck(fptr2, length, flag1);
    fptr2.close();

    operationSet(arrStr1, bit1, bit2, length, flag1, flag2, flag3);

    return 0;
}
