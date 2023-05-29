/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bore and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Assume input to be 0-indexed based.
Input Format :
Line 1 : Two integers N and M, the number of rows and columns of the board
Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.
Output Format :
Return 1 if there is a cycle else return 0
Constraints :
2 ≤ N, M ≤ 400
Sample Input :
3 4
AAAA
ABCA
AAAA
Sample Output :
1
*/

#include <iostream>
#include <vector>
using namespace std;

int dfs_search(vector<vector<char>> &board,int n,int m,int i,int j,int **visited,char current_char){
    visited[i][j]=1;
    // base case
    // check if any 2 directions from current are visited - means path found
    int count=0;
    // up
    if(i-1>=0){
        if(visited[i-1][j]==1){
            count++;
        }
    }
    // down
    if(i+1<n){
        if(visited[i+1][j]==1){
            count++;
        }
    }
    // left
    if(j-1>=0){
        if(visited[i][j-1]==1){
            count++;
        }
    }
    // right
    if(j+1<m){
        if(visited[i][j+1]==1){
            count++;
        }
    }
    if(count>=2){
        return 1;
    }
    // ---------------------------------------------------------------------------------
    // find next routes

    int ans=0;
    while(1){
        // check top
        if(i-1>=0){
            if(board[i-1][j]==current_char&&visited[i-1][j]==0){
                ans=dfs_search(board,n,m,i-1,j,visited,current_char);
            }
        }
        if(ans==1) break;
        // check bottom
        if(i+1<n){
            if(board[i+1][j]==current_char&&visited[i+1][j]==0){
                ans=dfs_search(board,n,m,i+1,j,visited,current_char);
            }
        }
        if(ans==1) break;
        // check left
        if(j-1>=0){
            if(board[i][j-1]==current_char&&visited[i][j-1]==0){
                ans=dfs_search(board,n,m,i,j-1,visited,current_char);
            }
        }
        if(ans==1) break;
        // check right
        if(j+1<m){
            if(board[i][j+1]==current_char&&visited[i][j+1]==0){
                ans=dfs_search(board,n,m,i,j+1,visited,current_char);
            }
        }
        if(ans==1) break;
        break;
    }
    visited[i][j]=0;
    return ans;
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    int **visited=new int*[n];
    for(int i=0;i<n;i++){
        visited[i]=new int[m];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char current=board[i][j];
            int result=dfs_search(board,n,m,i,j,visited,current);
            if(result==1){
                return true;
            }
            // for(int i=0;i<n;i++){
            //     for(int j=0;j<m;j++){
            //         visited[i][j]=0;
            //     }
            // }
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasCycle(board, n, m));
}