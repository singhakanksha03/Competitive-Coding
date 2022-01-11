/*Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S
Output format :
Modified string
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
hello
Sample Output 1:
hel*lo
*/
#include <iostream>
using namespace std;

// Change in the given string itself. So no need to return or print the changed string.
int len(char input[]){
    int i=0;
    while(input[i]!='\0'){
        i++;
    }
    return i;
}
void pairStar(char input[]) {
    // Write your code here
	if(input[0]=='\0'){
        return;
    }
    if(input[0]==input[1]){
        int size=len(input);

        for(int i=size-1;i>0;i--){
            input[i+1]=input[i];
        }

        input[1]='*';
        input[size+1]='\0';
    }
    pairStar(input+1);
}

int main() {
   char input[100];
   cin.getline(input, 100);
   pairStar(input);
   cout << input << endl;
}
