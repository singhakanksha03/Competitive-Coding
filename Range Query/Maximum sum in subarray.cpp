/*
You are given a sequence A[1], A[2], ..., A[N].
A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
Given M queries, write a program that outputs the results of these queries.
Input Format:
The first line of input contains an integer N.
In the second line contains N space separated integers.
The third line contains the integer M.
Next M lines contains 2 integers x and y.
Output Format:
For each query, print the answer in a new line.
Constraints:
1 <= N <= 10^5
1 < = Q <= 10^5
-10^4 <= arr[i] <= 10^4
Sample Input 1:
3 
-1 2 3 
1
1 2
Sample Output 1:
2
*/

#include<bits/stdc++.h>
using namespace std;
struct node{
    int sum;
    int maxSum;
    int bestPrefixSum;
    int bestSuffixSum;
};
void buildTree(int *arr,struct node *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode].sum=arr[start];
        tree[treeNode].maxSum=arr[start];
        tree[treeNode].bestPrefixSum=arr[start];
        tree[treeNode].bestSuffixSum=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    
    struct node left=tree[2*treeNode];
    struct node right=tree[2*treeNode+1];
    
    tree[treeNode].sum=left.sum+right.sum;
    tree[treeNode].maxSum=max(left.maxSum,
                              max(right.maxSum,
                                  max(left.sum+right.bestPrefixSum,
                                      max(left.bestSuffixSum+right.sum,left.bestSuffixSum+right.bestPrefixSum))));
    tree[treeNode].bestPrefixSum=max(left.bestPrefixSum,left.sum+right.bestPrefixSum);
    tree[treeNode].bestSuffixSum=max(right.bestSuffixSum,right.sum+left.bestSuffixSum);
}
struct node query(struct node *tree,int start,int end,int treeNode,int x,int y){
    if(start>y|| end<x){
        return {-100000, -100000, -100000, -100000};
    }
    else if(start>=x && end<=y){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    struct node ans1=query(tree,start,mid,2*treeNode,x,y);
    struct node ans2=query(tree,mid+1,end,2*treeNode+1,x,y);
    struct node ans;
    ans.sum=ans1.sum+ans2.sum;
    ans.maxSum=max(ans1.maxSum,max(ans2.maxSum,max(ans1.sum+ans2.bestPrefixSum,max(ans2.sum+ans1.bestSuffixSum,ans1.bestSuffixSum+ans2.bestPrefixSum))));
    ans.bestPrefixSum=max(ans1.bestPrefixSum,ans1.sum+ans2.bestPrefixSum);
    ans.bestSuffixSum=max(ans2.bestSuffixSum,ans2.sum+ans1.bestSuffixSum);
    return ans;
}
int main(){
    
    // write your code here
    int N;
    cin>>N;
    int *arr=new int[N];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    struct node *tree=new node[4*N];
    buildTree(arr,tree,0,N-1,1);
    int M;
    cin>>M;
    while(M--){
        int x,y;
        cin>>x>>y;
        struct node ans=query(tree,0,N-1,1,x-1,y-1);
        cout<<ans.maxSum<<endl;
    }
    
    // for(int i=0;i<4*N;i++){
    //     cout<<tree[i].sum<<" "<<tree[i].maxSum<<" "<<tree[i].bestPrefixSum<<" "<<tree[i].bestSuffixSum<<endl;
    // }
    return 0;
}