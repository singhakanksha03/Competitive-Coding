/*
Given an input string (STR), print all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.
Input Format:
The only input line contains a string (STR) of alphabets in lower case
Output Format:
Print each permutations in a new line
Constraint:
1<=length of STR<=8
Time Limit: 1sec
Sample Input 1:
cba
Sample Output 1:
abc
acb
bac
bca
cab
cba

*/

#include <iostream>
#include <string>
using namespace std;
void printPermutationsHelper(string input, string output){
    if(input.length() == 0){
        cout << output << endl;
        return;
    }
    
    for(int i = 0; i< input.length(); i++){ 
        printPermutationsHelper(input.substr(0,i) + input.substr(i+1), output + input[i]);
    }
}
void printPermutations(string input){

    printPermutationsHelper(input,"");
}
#include <iostream>
#include <string>
using namespace std;

#include "solution.h"

int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}