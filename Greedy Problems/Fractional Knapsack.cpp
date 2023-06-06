/*
You are given weights and values of N items. You have to select and put these selected items in a knapsack of capacity W. Select the items in such a way that selected items give the maximum total value possible with given capacity of the knapsack.
Note: You are allowed to break the items in parts.
Input Format:
The first line of input contains two space separated integers, that denote the value of N and W.
Each of the following N lines contains two space separated integers, that denote value and weight, respectively, of the N items.    
Constraints:
1 <= N = 2*10^5
1 <= W <= 10^9
1 <= value, weight <= 10^5
Time Limit: 1 sec
Output Format:
Print the maximum total value upto six decimal places.
Sample Input 1:
4 22
6 4
6 4
4 4
4 4
Sample Output 1:
20.000000
Explanation:
The total weight of all the items is 16 units, which is less than the total capacity of knapsack, i.e 22 units. Hence, we will add all the items in the knapsack and total value will be 20 units.
*/

#include<bits/stdc++.h>
using namespace std;
struct item{
    int value;
    int weight;
};
bool helperSort(struct item i1,struct item i2){
    double d1=(double)i1.value/(double)i1.weight;
    double d2=(double)i2.value/(double)i2.weight;
    return d1>d2;
}
int main(){
    int N,W;
    double amount=0.0;
    cin>>N>>W;
    vector<struct item> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i].value>>A[i].weight;
    }
    sort(A.begin(),A.end(),helperSort);
    
    for(int i=0;i<N;i++){
        if(A[i].weight<=W){
            W-=A[i].weight;
            amount+=(double)A[i].value;
        }
        else{
            amount+=((double)W/(double)A[i].weight)*A[i].value;
			break;
        }
    }
    cout<<fixed<<setprecision(6)<<amount;
    
    return 0;
}


// bool sortfinish(const pair<int,int> &a,
//               const pair<int,int> &b)
// {
//     double r1=(double)a.first/a.second;
//     double r2=(double)b.first/b.second;
//     return r1>r2;
// }
// int main()
// {
//    int n;
//    cin>>n;
//     double W;
//     cin>>W;
//    vector<pair<double,double>> arr(n);
//    for(int i=0;i<n;i++){
//     cin>>arr.at(i).first;
//        cin>>arr.at(i).second;
//    }
  
//    sort(arr.begin(), arr.end(), sortfinish);
//    double ans=0;
//     double curWeight = 0; 
//     double finalvalue = 0;
// 	for(int i=0;i<n;i++){
//     if(curWeight+arr.at(i).second <=W){
//         curWeight+=arr.at(i).second;
//         finalvalue+=arr.at(i).first;
//     }
//     else{
//         double remain = W - curWeight;
//             finalvalue += arr.at(i).first
//                           * ((double)remain
//                              / (double)arr.at(i).second);
//             break;
//     }
//    }
  
  
//    cout<<fixed<<setprecision(6)<<finalvalue;
//    return 0;
// }