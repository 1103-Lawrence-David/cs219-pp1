#include "operation.h"
#define SIZE 200
#define READ_FILE "pp1_input.txt"

int main (){
    int operation[SIZE], length = 0;
    uint32_t bit1[SIZE], bit2[SIZE];
    string arrStr1[SIZE];

    ifstream fptr("pp1_input.txt");
    if(!fptr.is_open()){
        cout<< "UH OH!" << endl;
        return 0;
    }

    readFile(fptr,length, arrStr1, bit1, bit2);
    
    display(bit1, length);
    
    return 0;
}