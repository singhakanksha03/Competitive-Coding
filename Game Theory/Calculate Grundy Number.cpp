/*
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. If the integer becomes 0, it is removed. The last player to move wins. Which player wins the game?
Input Format:
First line of input contains an integer T, representing the number of test cases.
Next T lines contain an integer n.
Constraints:
1 <= T <= 10^4
1 <= N <= 10^6
Output Format:
Print the Grundy Number(n) for each test case in a new line.
Sample Input 1:
1
10
Sample Output 1:
0

*/


#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        
    
    int n;
    cin>>n;
    int wins=0;
    int turn=0;
    while(n>0){
        turn=turn==1?0:1;
        if(n==0){
            break;
        }
        n-=n/2==0?n/2:n/3==0?n/3:n/6==0?n/6:0;
    }
    cout<<turn<<endl;
    }
}