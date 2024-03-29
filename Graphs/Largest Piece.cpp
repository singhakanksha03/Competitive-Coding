/*
Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Input Format :
First line will contain T(number of test cases), each test case follows as.
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Print the size of the biggest piece of '1's and no '0'sfor each test case in a newline.
Constraints:
1 <= T <= 10
1 <= N <= 1000
Sample Input :
1
2
11
01
Sample Output :
3
*/


#include<iostream>
#include<vector>
using namespace std;
#define NMAX 1000
char cake[NMAX][NMAX];

void dfs(char cake[NMAX][NMAX],int n,int &k,int i,int j){
    k++;
    cake[i][j]='0';
    
    if(i+1<n && cake[i+1][j]=='1')
        dfs(cake,n,k,i+1,j);
    if(i-1>=0 && cake[i-1][j]=='1')
        dfs(cake,n,k,i-1,j);
    if(j+1<n && cake[i][j+1]=='1')
        dfs(cake,n,k,i,j+1);
    if(j-1>=0 && cake[i][j-1]=='1')
        dfs(cake,n,k,i,j-1);
    
}

int solve(int n,char cake[NMAX][NMAX])
{
	// Write your code here .
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            
            if(cake[i][j]=='1'){
                int k1=0;
                dfs(cake,n,k1,i,j);
                ans=max(ans,k1);
            }
        }
    }
    return ans;
}



int main()
{
    int t;
    cin>>t;
    while(t--){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%s",cake[i]);
	}
	cout<<solve(n,cake)<<endl;
    }
}