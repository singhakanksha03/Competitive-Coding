/*
King Leonidas of Sparta is preparing his men and country for a war against the Persian King Xerxes. He has N soldiers with him and he has arranged them in a line at The Hot Gates. Let us number them from 1 to N. Leonidas will fight Xerxes' army for Q days, and each day he can send only one of his men to fight.
For each warrior, we know 2 traits: Strength and Cowardice. These are given to us in a form of integer. Each day, Leonidas can choose his warrior from a range Li to Ri, and he will choose the warrior with maximum Strength value. If there is more than one warrior having the same maximum Strength value, he will choose the warrior with minimum Cowardice value. If there is still more than 1 warrior with the same maximum Strength value and same minimum Cowardice value, he chooses the one with lower index in line.
King Leonidas is ready to lay his life for Sparta. You, his right hand man, have to help him save Sparta by helping him choose a warrior for each day.
Input Format:
First line contains a single integer N, denoting the number of warriors Leonidas has. 
Second line contains N space separated integers, representing Strength of ith warrior. 
Third line contains N space separated integers, representing Cowardice of ith warrior
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Constraints:
1 ≤ N,Q ≤ 10^5
1 ≤ Ai,Bi ≤ 10^9
1 ≤ Li ≤ Ri
Output Format:
For each Li and Ri, print the index of the warrior that King Leonidas should choose.
Sample Input 1:
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output 1:
2
2
4
5

*/

#include<bits/stdc++.h>
using namespace std;
class warrior{
    public:
    int strength;
    int cowardice;
    int index;
};
void buildTree(warrior *arr,warrior *tree,int start,int end,int treeNode){
    if(start==end){
        tree[treeNode]=arr[start];
        return;
    }
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    warrior left=tree[2*treeNode];
    //cout<<left.strength;
    warrior right=tree[2*treeNode+1];
    if(left.strength>right.strength){
        tree[treeNode].strength=left.strength;
        tree[treeNode].cowardice=left.cowardice;
        tree[treeNode].index=left.index;
        
    }
    else if(right.strength>left.strength){
        tree[treeNode].strength=right.strength;
        tree[treeNode].cowardice=right.cowardice;
        tree[treeNode].index=right.index;
        
    }
    
    else{
        if(left.cowardice<right.cowardice){
            tree[treeNode].strength=left.strength;
        	tree[treeNode].cowardice=left.cowardice;
        	tree[treeNode].index=left.index;
        }
        else if(left.cowardice>right.cowardice){
            tree[treeNode].strength=right.strength;
        	tree[treeNode].cowardice=right.cowardice;
        	tree[treeNode].index=right.index;
        }
        else{
            if(left.index<right.index){
                tree[treeNode].strength=left.strength;
        		tree[treeNode].cowardice=left.cowardice;
        		tree[treeNode].index=left.index;
            }else{
                tree[treeNode].strength=right.strength;
        		tree[treeNode].cowardice=right.cowardice;
        		tree[treeNode].index=right.index;
            }
            
        }
    }
    return;
}

warrior get(warrior *tree,int start,int end,int treeNode,int left,int right){
    if(left>end || right<start){
        return {0,0,0};
    }
    else if(start>=left && end<=right){
        return tree[treeNode];
    }
    int mid=(start+end)/2;
    warrior ans1=get(tree,start,mid,2*treeNode,left,right);
    warrior ans2=get(tree,mid+1,end,2*treeNode+1,left,right);
    if(ans1.strength>ans2.strength){
        // tree[treeNode].strength=ans1.strength;
        // tree[treeNode].cowardice=ans1.cowardice;
        // tree[treeNode].index=ans1.index;
        return ans1;
        
    }
    else if(ans2.strength>ans1.strength){
        // tree[treeNode].strength=ans2.strength;
        // tree[treeNode].cowardice=ans2.cowardice;
        // tree[treeNode].index=ans2.index;
        return ans2;
        
    }
    
    else{
        if(ans1.cowardice<ans2.cowardice){
        	// tree[treeNode].strength=ans1.strength;
        	// tree[treeNode].cowardice=ans1.cowardice;
        	// tree[treeNode].index=ans1.index;
            return ans1;
        }
        else if(ans1.cowardice>ans2.cowardice){
        	// tree[treeNode].strength=ans2.strength;
        	// tree[treeNode].cowardice=ans2.cowardice;
        	// tree[treeNode].index=ans2.index;
            return ans2;
        }
        else{
            if(ans1.index<ans2.index){
        		// tree[treeNode].strength=ans1.strength;
        		// tree[treeNode].cowardice=ans1.cowardice;
        		// tree[treeNode].index=ans1.index;
                return ans1;
            }else{
        		// tree[treeNode].strength=ans2.strength;
        		// tree[treeNode].cowardice=ans2.cowardice;
        		// tree[treeNode].index=ans2.index;
                return ans2;
            }
            
        }
    }
    //return tree[treeNode];
    
}
int main(){
    int N;
    cin>>N;
    warrior *arr=new warrior[N];
    warrior *tree=new warrior[4*N];
    for(int i=0;i<N;i++){
        cin>>arr[i].strength;
        arr[i].index=i;
    }
    for(int i=0;i<N;i++){
        cin>>arr[i].cowardice;
    }
    // for(int i=0;i<N;i++){
    //     cout<<arr[i].strength<<arr[i].cowardice<<arr[i].index<<endl;
    // }
    buildTree(arr,tree,0,N-1,1);
    int Q;
    cin>>Q;
    while(Q--){
        int l,r;
        cin>>l>>r;
        cout<<get(tree,0,N-1,1,l-1,r-1).index+1<<endl;
    }
    // for(int i=0;i<3*N;i++){
    //     cout<<tree[i].strength<<tree[i].cowardice<<tree[i].index<<endl;
    // }
    return 0;
}