/*
You are given two integers N and i. You need to clear all bits from MSB to ith bit (start i from right to left) and return the updated N.
Counting of bits starts from 0 from right to left.
Input Format :
First line of input will contain T(number of test cases), each test case follows as.
Line1: contain two space-separated integers N and i.
Output Format :
Updated N for each test case in a newline.
Constraints:
1 <= T <= 10^5
1 <= N <= 10^9
1 <= i <= 30
Sample Input 1 :
1
15 2
Sample Output 1 :
3
*/


#include<bits/stdc++.h>
using namespace std;

int clearAllBits(int n, int i){
    
    int mask_initiator=(1<<(i));
    mask_initiator=mask_initiator-1;
    int mask=mask_initiator;
    return (mask&n);
}
int main(){
    
    // write your code here
     int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n>>i;
        cout<<clearAllBits(n,i)<<endl;
    }
    return 0;
}