/*
You are given an array of integet of size N and Q queries in form of (l, r). You are supposed to find the maximum value of array between index l and r (both inclusive)
Input Format:
First line of input contain an integer N (number of elements in the array)
Second line contain N space-separated integers denoting the elements of the array
Third line contain an integer Q (number of queries to be processed)
Next Q line contain two space-separated integers denoting l and r.
Output Format:
For each test case print the output in newline.
Constraints:
1 <= N <= 10^4
1 <= Q <= 10^6
1 <= arr[i] <= 10^9
0 <= l <= r < N
Sample Input:
5
1 2 3 5 4
2 
0 1
3 4
Sample Output:
2
5

*/

#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    tree[treeNode]=max(tree[2*treeNode],tree[2*treeNode+1]);
    
}

int get(int *tree,int start,int end,int treeNode,int left,int right){
    if(left>end || right<start){
        return 0;
    }
    else if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    int ans1=get(tree,start,mid,2*treeNode,left,right);
    int ans2=get(tree,mid+1,end,2*treeNode+1,left,right);
    return max(ans1,ans2);
}
int main(){
    
    // write your code here
    int N,Q;
    cin>>N;
    int *arr=new int[N];
    int *tree=new int[4*N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    buildTree(arr,tree,0,N-1,1);
    // for(int i=0;i<4*N;i++){
    //     cout<<tree[i]<<endl;
    // }
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<get(tree,0,N-1,1,l,r)<<endl;;
    }
    
    return 0;
}