#include <iostream>

using namespace std;


int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}
int power(int n,int len){
    int mul=1;
    while(len>0){
        mul*=n;
        len--;
    }
    return mul;
}
int stringToNumber(char input[]) {
    
	if(input[0]=='\0'){
        return 0;
    }
   
    int num=input[0]-'0';
    int pow=(power(10,len(input)-1));
    return num * pow +stringToNumber(input+1);
    
}



int main() {
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}
