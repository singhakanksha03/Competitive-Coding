/*Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S
Output format :
Modified String
Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 
Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
*/


#include <iostream>
using namespace std;


int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}
void removeX(char input[]) {
    // Write your code here
    if(input[0]=='\0'){
        return;
    }
    if(input[0]=='x'){
        int size=len(input);
        for(int i=1;i<size;i++){
            input[i-1]=input[i];
        }
        input[size-1]='\0';
        removeX(input);
    }
	removeX(input+1);
}

int main() {
    char input[100];
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
}
