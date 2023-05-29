/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
First line will contain T(number of test case), each test case follows as.
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0, for each test case in a new line
Constraints :
1 <= T <= 10
1 <= N <= 1000
1 <= M <= 1000
Sample Input :
1
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1
*/


#include <iostream>
#include <vector>
using namespace std;

int dfs_traversal(vector<vector<char>> &board,int n,int m,int curr_n,int curr_m,int **visited,int curr_el){
    if(curr_el>=11){
        return 1;
    }
    visited[curr_n][curr_m]=1;
    string cn="CODINGNINJA";
    int ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,ans7=0,ans8=0;
    while(1){
        // cout<<1<<endl;
        // check top
        if(curr_n-1>=0){
            if(board[curr_n-1][curr_m]==cn[curr_el]&&visited[curr_n-1][curr_m]==0){
                // cout<<cn[curr_el]<<endl;
                ans1=dfs_traversal(board,n,m,curr_n-1,curr_m,visited,curr_el+1);
            }
        }
        if(ans1==1) break;
        // check bottom
        if(curr_n+1<n){
            if(board[curr_n+1][curr_m]==cn[curr_el]&&visited[curr_n+1][curr_m]==0){
                // cout<<cn[curr_el]<<endl;
                ans2=dfs_traversal(board,n,m,curr_n+1,curr_m,visited,curr_el+1);
            }
        }
        if(ans2==1) break;
        // check right
        if(curr_m+1<m){
            if(board[curr_n][curr_m+1]==cn[curr_el]&&visited[curr_n][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans3=dfs_traversal(board,n,m,curr_n,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans3==1) break;
        // check left
        if(curr_m-1>=0){
            if(board[curr_n][curr_m-1]==cn[curr_el]&&visited[curr_n][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans4=dfs_traversal(board,n,m,curr_n,curr_m-1,visited,curr_el+1);
            }
        }
        if(ans4==1) break;
        // check diagonals
        // top right
        if(curr_m+1<m&&curr_n-1>=0){
            if(board[curr_n-1][curr_m+1]==cn[curr_el]&&visited[curr_n-1][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans5=dfs_traversal(board,n,m,curr_n-1,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans5==1) break;
        // top left
        if(curr_m-1>=0&&curr_n-1>=0){
            if(board[curr_n-1][curr_m-1]==cn[curr_el]&&visited[curr_n-1][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans6=dfs_traversal(board,n,m,curr_n-1,curr_m-1,visited,curr_el+1);
            }
        }
        if(ans6==1) break;
        // bottom right
        if(curr_m+1<m&&curr_n+1<n){
            if(board[curr_n+1][curr_m+1]==cn[curr_el]&&visited[curr_n+1][curr_m+1]==0){
                // cout<<cn[curr_el]<<endl;
                ans7=dfs_traversal(board,n,m,curr_n+1,curr_m+1,visited,curr_el+1);
            }
        }
        if(ans7==1) break;
        // bottom left
        if(curr_m-1>=0&&curr_n+1<n){
            if(board[curr_n+1][curr_m-1]==cn[curr_el]&&visited[curr_n+1][curr_m-1]==0){
                // cout<<cn[curr_el]<<endl;
                ans8=dfs_traversal(board,n,m,curr_n+1,curr_m-1,visited,curr_el+1);
            }
        }
        // if(ans8==1) break;
        break;
    }
    visited[curr_n][curr_m]=0;
    if(ans1==1||ans2==1||ans3==1||ans4==1||ans5==1||ans6==1||ans7==1||ans8==1){
        return 1;
    }
    return 0;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int **visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m]{};
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='C'){
                visited[i][j]=1;
                int ans=dfs_traversal(board,n,m,i,j,visited,1);
                if(ans==1){
                    return 1;
                }
                visited[i][j]=0;
            }
            // for(int x=0;x<n;x++){
            //     for(int y=0;y<m;y++){
            //         visited[x][y]=0;
            //     }
            // }
        }
    }
    return 0;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        
    
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);
    cout<<endl;
    }
    
}