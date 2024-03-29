/*
You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format:
First line of input will contain T(number of test cases), each test case follows as. 
A single line containing two space-separated integers N and i.
Output Format:
Updated N for each test case in new line.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
1 <= i <= 30
Sample Input 1 :
1
4 1
Sample Output 1 :
6
Sample Input 2 :
1
4 4
Sample Output 2 :
20
*/


#include<bits/stdc++.h>
using namespace std;

int turnOnIthBit(int n, int i){
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(n&(1<<i))
	{
		return n;
	}
	else
	return n + (1 << i);
}

int main(){
    
    
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n>>i;
        cout<<turnOnIthBit(n,i)<<endl;
    }
    return 0;
}