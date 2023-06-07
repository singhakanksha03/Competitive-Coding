/*Harshit knows through his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format:
First line of input contians an integer T, representing the number of test cases.
Next T lines contains two space-separated integers: S,D
Constraints:
1 <= T <= 1000
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Output Format
The output contains a single integer denoting the winning lottery number
Sample Input 1:
1
9 2
Sample Output 1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/


#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int s,d,i=0,sum=0;
        cin>>s>>d;
        vector<int> arr(d);
        sum=s-1;
        arr[i]=1;
        i=d-1;
        while(i>0){
            if(i==0){
                arr[i]+=sum;
            }
            else if(sum>9){
                arr[i]=9;
                sum-=9;
            }
            else if(sum<=9){
                arr[i]+=sum;
                sum=0;
            }
            i--;
        }
        arr[i]=sum+1;
        
        for(int i=0;i<d;i++){
            cout<<arr[i];
        }
        cout<<endl;
        
    }
}