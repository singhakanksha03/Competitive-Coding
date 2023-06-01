/*
Dwight is always bragging about how amazing he is at solving complicated problems with much ease. Jim got tired of this and gave him an interesting problem to solve.
Jim gave Dwight a sequence of integers a1, a2, ..., an and q queries x1, x2, ..., xq on it. For each query xi Dwight has to count the number of pairs (l, r) such that 1 ≤ l ≤ r ≤ n and GCD(al, al + 1, ..., ar) = xi. Dwight is feeling out of his depth here and asked you to be his Secret Assistant to the Regional Manager. Your first task is to help him solve the problem. Are you up to it?
Input Format:
First line of input contains an integer N, representing the number of elements in the sequence.
Second line contains N space-separated integers denoting the elements of the sequence.
Third line of input contains an integer Q, representing the number of queries.
Next Q line contains an integer X.
Constraints:
1 < = N <= 10^4
1 <= arr[i] <= 10^9
1 <= Q <= 10^4
1 <= X <= 10^9 
Output Format:
For each query, print the answer in a new line.
Sample Input:
2
8 12 
3
8
12
4
Sample Output:
1
1
1
*/


#include<map>
#include<cstdio>
#include<algorithm>
#define N 110000
#include<iostream>
#define ll long long
using namespace std;
map<int,ll>::iterator it;
map<int,ll> mm[2],ans;
inline char gc(){
    static char now[1<<16],*S,*T;
    if (T==S){T=(S=now)+fread(now,1,1<<16,stdin);if (T==S) return EOF;}
    return *S++;
}
inline int read(){
    int x=0,f=1;char ch=gc();
    while(ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=gc();}
    while(ch<='9'&&ch>='0') x=x*10+ch-'0',ch=gc();
    return x*f;
}
inline int gcd(int x,int y){
    if (!y) return x;else return gcd(y,x%y);
}
int n,m,a[N];
int main(){
    //freopen("cf475d.in","r",stdin);
    cin>>n;
    for (int i=1;i<=n;++i) 
        cin>>a[i];
	int now=1,pre=0;
    for (int i=n;i;--i){
        mm[now].clear();mm[now][a[i]]=1;ans[a[i]]++;
        for (it=mm[pre].begin();it!=mm[pre].end();++it){
            int x=gcd(a[i],(*it).first);mm[now][x]+=(*it).second;ans[x]+=(*it).second;
        }
        now^=1;pre^=1;
    }
    cin>>m;
    for (int i=1;i<=m;++i){
        int x;
        cin>>x;
        cout<<ans[x]<<endl;
    }
    return 0;
}