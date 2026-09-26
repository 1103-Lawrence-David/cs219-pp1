#include "operation.h"
#define SIZE 200
#define READ_FILE "pp1_input.txt"

//Flag is a debugging and logic tool. flag1 = true means there is a negativ enumber somewhere in the file input. flag 2 is a catch all for any errors in operation (number out of range, too many or few operations per request, etc.)

int main (){
    int operation[SIZE], length = 0;
    uint32_t bit1[SIZE], bit2[SIZE];
    string arrStr1[SIZE];
    bool flag1[SIZE], flag2[SIZE];

    ifstream fptr("pp1_input.txt");
    if(!fptr.is_open()){
        cout<< "UH OH!" << endl;
        return 0;
    }

    readFile(fptr,length, arrStr1, bit1, bit2, flag1);

    display(bit1, bit2, arrStr1, length, flag1);
    
    return 0;
}