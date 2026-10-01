#include "operation.h"

//This function reads the file, puts the information into corresponding arrays, and if necessary utilizes error flag arrays
void readFile(ifstream& fp, int& length, string* arrStr, uint32_t* arrHex1, uint32_t* arrHex2, bool* flag1, bool* flag2, bool* flag3){
    string temp;
    char tempChar;
    uint32_t hextemp, tempI2;

    while (getline(fp, temp)) {
        stringstream ss(temp);
        
        ss >> arrStr[length];
        ss.get(tempChar);
        if(tempChar == ' '){
        ss >> std::hex >> tempI2;
        
            if(tempI2 >= 0 ){
                hextemp = tempI2;
                arrHex1[length] = hextemp;
                tempI2 = 0; //Without this, it can overflow and corrupt reulting outputs.
                tempChar = 'p'; //also without this it doesnt properly update for some reason.
            }
            else{
                flag1[length] = true;
            }
        }
        else{
            flag2[length] = true;
        }
    
        ss.get(tempChar);
        if(tempChar == ' '){
            ss >> std::hex >> tempI2;

            if(tempI2 >= 0){
                hextemp = tempI2;
                arrHex2[length] = hextemp;
                tempI2 = 0; //Without this, it can overflow and corrupt reulting outputs.
                tempChar = 'p'; //also without this doesnt properly update for some reason.
            }
            else{
                flag1[length] = true;
            }
        }
        else{
            flag2[length] = true;
        }
        
        ss.get(tempChar);
        if(tempChar == ' '){
            flag3[length] = true;
        }
        length++;
    }
}

//This function adds b1 to b2, then outputs the result. 
void ADD(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 + b2;
    cout << "<0x" << std::hex << temp << ">" << endl;  
}

//This function subtracts b2 from b1, then outputs the result. 
void SUB(uint32_t b1, uint32_t b2){ //not correct
    uint32_t temp = b1 - b2;
    cout << "<0x" << std::hex << temp << ">" << endl;
}

//This function does bitwise AND to b1 and b2, then outputs the result. 
void AND(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 & b2;
    cout << "<0x" << std::hex << temp << ">" << endl;   
}

//This function does bitwise OR to b1 and b2, then outputs the result. 
void OR(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 | b2;
    cout << "<0x" << std::hex << temp << ">" << endl;
}
//This function does bitwise XOR to b1 and b2, then outputs the result. 
void XOR(uint32_t b1, uint32_t b2){
    uint32_t temp = b1 ^ b2;
    cout << "<0x" << std::hex << temp << ">" << endl;
}

//This function does bitwise NOT to b, then outputs the result. 
void NOT(uint32_t b){
    uint32_t temp = ~b;
    cout << "<0x" << std::hex << temp << ">" << endl;
}

//This function outputs the result of b being shifted by i left, if i is greater than 0 and less than 32. Otherwise, an error is returned.
void LSL(uint32_t b, int i){
    if(i > 0 && i < 32){
        uint32_t temp = b << i;
        cout << "<0x" << std::hex << temp << ">" << endl;
    }
    else if(i >= 32){
        cout << "<Shift Value exceeds bit size>" << endl;
    }
}

//This function outputs the result of b being shifted by i right, if i is greater than 0 and less than 32. Otherwise, an error is returned.
void LSR(uint32_t b, int i){
    if(i > 0 && i < 32){
        uint32_t temp = b >> i;
        cout << "<0x"<< std::hex << temp << ">" << endl;
    }
    else if(i >= 32){
        cout << "<Shift Value exceeds bit size>" << endl;
    }
}
//This function checks if b1 is equal to b2. If it is, true is output. If it isnt, false is output. if somehow it doesn't trigger either,
//An error is returned instead. 
void EQ(uint32_t b1, uint32_t b2){
    if(b1 == b2){
        cout << "<True>" << endl;
    }
    else if (b1 != b2){
        cout << "<False>" << endl;
    }
    else { //debugging
        cout << "<error with EQ>" << endl;
    }
}
//This function checks if b1 is less than b2. If it is, true is output. If it isnt, false is output. if somehow it doesn't trigger either,
//An error is returned instead. 
void LT(uint32_t b1, uint32_t b2){
    if(b1 < b2){
        cout << "<True>" << endl;
    }
    else if (b1 >= b2){
        cout << "<False>" << endl;
    }
    else {
        cout << "<error with LT>" << endl;
    }
}

//This function checks if b1 is greater than b2. If it is, true is output. If it isnt, false is output. if somehow it doesn't trigger either,
//An error is returned instead. 
void GT(uint32_t b1, uint32_t b2){
    if(b1 > b2){
        cout << "<True>" << endl;
    }
    else if (b1 <= b2){
        cout << "<False>" << endl;
    }
    else {
        cout << "<error with GT>" << endl;
    }
}

//The following display can be modified to display the 2 boolean flag arrays for debugging purposes. 
//copy and paste the following immediately following  b2[i]:  << flag1[i] << "     " << flag2[i] << "     "
void display(uint32_t* b1, uint32_t* b2, string* s, int i, bool* flag1, bool* flag2){ 
    if(s[i] != "NOT"){
        cout << s[i] << "     0x"  << std::hex << b1[i] << "     0x" << b2[i] << ": ";
    }
    else{
        cout << s[i] << "     0x"  << std::hex << b1[i] << ": ";
    }
}


//Originally the idea was to have a seperate function called "operationRun", which would check the operation stored in op against preset values. I realized i could do that here, but there are soom
//Remenats of that idea in the code, as much was written with that in mind.
void operationSet(string* arrStr, uint32_t* b1, uint32_t* b2, int length, bool* flag1, bool* flag2, bool* flag3){
   for(int i = 0; i < length; i++){
        if(flag3[i] == true){
            cout << "<Invalid Operand Count>" << endl;
        }
        else if(flag1[i] == true && (arrStr[i] == "LSL" || arrStr[i] == "LSR")){
            display(b1, b2, arrStr, i, flag1, flag2);
            cout << "<Negative shift count>" << endl;
        }
        else if(flag2[i] == true && (arrStr[i] != "NOT") ){
            display(b1, b2, arrStr, i, flag1, flag2);
            cout << "<Invalid Operand Count>" << endl;
        }
        else if(arrStr[i] == "ADD"){
            display(b1, b2, arrStr, i, flag1, flag2);
            ADD(b1[i], b2[i]);
        }
        else if(arrStr[i] == "SUB"){
            display(b1, b2, arrStr, i, flag1, flag2);
            SUB(b1[i], b2[i]);
        }
        else if(arrStr[i] == "AND"){
            display(b1, b2, arrStr, i, flag1, flag2);
            AND(b1[i], b2[i]);
        }
        else if(arrStr[i] == "OR"){
            display(b1, b2, arrStr, i, flag1, flag2);
            OR(b1[i], b2[i]);
        }
        else if(arrStr[i] == "XOR"){
            display(b1, b2, arrStr, i, flag1, flag2);
            XOR(b1[i], b2[i]);
        }
        else if(arrStr[i] == "NOT"){
            display(b1, b2, arrStr, i, flag1, flag2);
            NOT(b1[i]);
        }
        else if(arrStr[i] == "LSL"){
            display(b1, b2, arrStr, i, flag1, flag2);
            LSL(b1[i], b2[i]);
        }
        else if(arrStr[i] == "LSR"){
            display(b1, b2, arrStr, i, flag1, flag2);
            LSR(b1[i], b2[i]);
        }
        else if(arrStr[i] == "EQ"){
            display(b1, b2, arrStr, i, flag1, flag2);
            EQ(b1[i], b2[i]);
        }
        else if(arrStr[i] == "LT"){
            display(b1, b2, arrStr, i, flag1, flag2);
            LT(b1[i], b2[i]);
        }
        else if(arrStr[i] == "GT"){
            display(b1, b2, arrStr, i, flag1, flag2);
            GT(b1[i], b2[i]);
        }
        else{
            display(b1, b2, arrStr, i, flag1, flag2);
            cout << "<unsupported operation>" << endl;
        }

    }
    
   
}
/* 
I couldn't figure out how to make this work properly in readFile() (which would have been ideal). However, the premise is simple.
this function loops through every character in the file, line by line. 
These characters are then checked to be "-". if it is, this means the number is negative, which isnt allowed.
However, the instructions only say to account for negative shifts, so we flag it and check against if it is a shift operation in operationSet()
*/
void errorCheck(ifstream& fp, int length, bool* flag){
    int i = 0;
    char c;
    string s;
    
    while(getline(fp, s)){
        stringstream ss(s);

        while(ss.get(c) && c != '\n'){
            if(c == '-'){
                flag[i] = true;
            }
        }

        i++;
    }
}
