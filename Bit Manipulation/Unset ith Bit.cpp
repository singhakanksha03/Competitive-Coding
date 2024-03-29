/*
You are given two integers N and i. You need to make ith bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format:
First line of input contains T(number of test cases), each test case follows as. 
Two integers N and i (separated by space)
Output Format :
Updated N for each test case in new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
1 <= i < 30
Sample Input 1 :
1
7 2
Sample Output 1 :
3
Sample Input 2 :
1
12 1
Sample Output 2 :
12
*/

#include<bits/stdc++.h>
using namespace std;

int turnOffIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n&(1<<i))
    {
        return (n&~(1<<i));
    }
    else
    {
        return n;
    }
}

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n>>i;
        cout<<turnOffIthBit(n,i)<<endl;
    }
    return 0;
}