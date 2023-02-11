/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S
Output Format :
'true' or 'false'
Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.
Sample Input 1 :
racecar
Sample Output 1:
true
Sample Input 2 :
ninja
Sample Output 2:
false
*/

bool isPalindrome(char str[],int start,int end)
{
    if(start >= end) //base case
    return true;
    else{
        //if mismatch happens false will be returned else true
        return ((str[start] == str[end]) && isPalindrome(str,start+1,end-1));
    }
}

bool checkPalindrome(char input[]) {
    // Write your code here
    int count=0;
    int i=0;
    while(input[i]!='\0'){
        count++;
        i++;
    }
    return isPalindrome(input,0,count-1);
    
}


#include <iostream>
#include "solution.h"
using namespace std;

int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
