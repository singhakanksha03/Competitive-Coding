/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
The numbers and their corresponding codes are given below:
0: ""
1: ""
2: "abc"
3: "def"
4: "ghi"
5: "jkl"
6: "mno"
7: "pqrs"
8: "tuv"
9: "wxyz"
Return empty string for numbers 0 and 1.
Note:
1. The order of strings are not important.
2. The input number will have digits between: [2, 9].
Input Format :
First line of input will contain T number of test cases.
Each input consists of a single line containing an integer n.
Output Format :
For each test case, print all possible strings in different lines.
Constraints :
1 <= T <= 100
1 <= n <= 10^6
Sample Input:
1
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <bits/stdc++.h>
using namespace std;

void print_combinations(int num,string out,vector<vector<char>> keys){
    // base case
    if(num==0||num==1){
        cout<<out<<" "<<endl;
        return;
    }
    //get last number in num
    int rem=num%10;
    //print all combinations by using all chars from rem's key mappings
    for(int i=0;i<keys[rem-2].size();i++){
        print_combinations(num/10,keys[rem-2][i]+out,keys);
    }
}

void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    vector<vector<char>> keys;
    keys.push_back({'a','b','c'}); //2nd key
    keys.push_back({'d','e','f'}); //3rd key
    keys.push_back({'g','h','i'}); //4th key
    keys.push_back({'j','k','l'}); //5th key
    keys.push_back({'m','n','o'}); //6th key
    keys.push_back({'p','q','r','s'}); //7th key
    keys.push_back({'t','u','v'}); //8th key
    keys.push_back({'w','x','y','z'}); //9th key
	string out;
    print_combinations(num,out,keys);
}
int main()
{

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        printKeypad(n);
    }
 
    return 0;
}