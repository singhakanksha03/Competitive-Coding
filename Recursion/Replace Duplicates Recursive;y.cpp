/*
Given a string S, remove consecutive duplicates from it recursively.
Input Format :
First line of input will contain T number of test cases
Next T line will contain the string S
Output Format :
For every test case print the answer in a separate line
Constraints :
1 <= T <= 10
1 <= |S| <= 10^4
where |S| represents the length of string
Sample Input 1 :
1
aabccba
Sample Output 1 :
abcba
Sample Input 2 :
1
xxxyyyzwwzzz
Sample Output 2 :
xyzwz

*/

#include<bits/stdc++.h>
using namespace std;

void removeRec(char *input){
    if(input[0]=='\0'){
        return;
    }
    if(input[0]!=input[1]){
        removeRec(input+1);
    }else{
        for(int i=0;input[i]!='\0';i++){
            input[i]=input[i+1];
        }
        removeRec(input);
    }
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        char *input;
        cin>>input;
        removeRec(input);
        cout<<input<<endl;
    }
    
    return 0;
}