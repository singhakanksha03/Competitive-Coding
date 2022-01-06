/*Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
*/


#include <iostream>
using namespace std;

int len(char str[]){
    int i=0,count=0;
    while(str[i]!='\0'){
        i++;
        count++;
    }
    return count;
}

void replacePi(char input[]) {
	if(input[0]=='\0')
        return;
    if(input[0]=='p' && input[1]=='i'){
        input[0]='3';
        input[1]='.';
        
        int size=len(input);
        for(int i=size+2;i>1;i--){
            input[i]=input[i-2];
        }
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);
}



int main() {
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
