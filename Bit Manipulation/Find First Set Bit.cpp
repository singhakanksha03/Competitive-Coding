/*
You are given an integer N. You need to return an integer M, in which only one bit is set which at the position of a lowest set bit of N (from right to left).
Input Format :
The first line of input will contain T(number of the test case), each test case follows as.
The only line of each test case contains an integer N.
Output Format:
Integer M for each test case in a new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
Sample Input 1 :
1
7
Sample Output 1 :
1
Sample Input 2 :
1
12
Sample Output 2 :
4

*/

#include<bits/stdc++.h>
using namespace std;

int returnFirstSetBit(int n)
{
    if(n==0)
    {
        return 0;
    }
    int i=0;
    while((n&(1<<i))==0)
    {
        i++;
    }
    return n&(1<<i);
}

int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<returnFirstSetBit(n)<<endl;
    }
    return 0;
}