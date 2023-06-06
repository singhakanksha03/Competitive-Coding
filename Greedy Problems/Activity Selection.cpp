/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input Format
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity. 
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Output Format
Output one integer, the maximum number of activities that can be performed
Sample Input 1
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output 1
4
Explanation:
The four activities will be done at following time intervals:
1. 1 2
2. 3 4
3. 5 7
4. 8 9
*/


#include<bits/stdc++.h>
using namespace std;
// struct pair{
//     int start;
//     int finish;
// };
bool helperSort(pair<int,int> p1,pair<int,int> p2){
    return p1.second<p2.second;
}
int main(){
    
    // write your code here
    int n,fin,count;
    cin>>n;
    vector<pair<int,int>> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i].first>>A[i].second;
    }
    sort(A.begin(),A.end(),helperSort);
    fin=A[0].second;
    count=1;;
    for(int i=1;i<n;i++){
        //cout<<A[i].first<<" ";
        //cout<<fin;
        if(fin<=A[i].first){
            fin=A[i].second;
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}