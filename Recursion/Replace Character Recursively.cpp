/*
Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :
The first line of input will contain an integer T, which will denote the value of number of test cases. In the following lines, T test cases will be written.
The first line of each test case will contain a string S. 
The following line of each test case will contain two space separated characters, c1 and c2, respectively.
Output Format :
For each test case, the first and only line of output contains the updated string S.
Constraints :
 1 <= T <= 100
 1 <= Length of String S <= 100
Sample Input :
1
abacd
a x
Sample Output :
xbxcd

*/




#include<bits/stdc++.h>
using namespace std;
void replaceCharacter(char input[], char c1, char c2) {
    if(input[0]=='\0')
        return;
    if(input[0]!=c1)
        replaceCharacter(input+1,c1,c2);
    else{
        input[0]=c2;
        replaceCharacter(input+1,c1,c2);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        char input[1000000];
    	char c1, c2;
    	cin >> input;
    	cin >> c1 >> c2;
    	replaceCharacter(input, c1, c2);
    	cout << input << endl;
    }
    
}