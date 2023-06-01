/*
Sheldon always tells people, “When you have only one day to visit Los Angeles, make it a Train Day”. He loves spending time while travelling in trains and considers it a fun activity. Sheldon’s mom has come to visit him and he decides to take her out on a train tour of the city of Pasadena, along with his friend Howard. There are n train stations in the city. Howard knows how irritating Sheldon can be during a train ride. So, to keep him busy, Howard gives Sheldon a problem so interesting that he just cannot do anything else other than devote his entire mind to solving it. The problem goes like this. At the i-th station it's possible to buy only tickets to stations from i + 1 to ai (inclusive). No tickets are sold at the last station.
Let ρi, j be the minimum number of tickets one needs to buy in order to get from stations i to station j. Sheldon’s task is to compute the sum of all values ρi, j among all pairs 1 ≤ i < j ≤ n. As brilliant as he may be, he asked for your help.
Input Format:
First line of input will contain N number of trains 
Second line will contain N-1 space-separated integers denoting the values of ai
Output Format:
Print the answer as mentioned above
Constraints:
2 < = N <= 10^5
i + 1 <=arr[i] <= N
Sample Input 1:
7
2 7 5 7 6 7 
Sample Output 1:
29
*/


#include <iostream>
#include <stdio.h>
using namespace std;
#define MAX 100010
#define LL long long

LL ans;
int dp[MAX*4];
LL a[MAX];
int rr[MAX];
int q,u;

void build(int l,int r,int tt)
{
    if(l==r)
    {
        dp[tt]=rr[l];
        return ;
    }
    int mid=(l+r)/2;
    build(mid+1,r,tt*2+1);
    build(l,mid,tt*2);
    dp[tt]=max(dp[tt*2],dp[tt*2+1]);
}

void query(int l,int r,int tt,int x,int y)
{
    if(x==l&&y==r)
    {
        if(dp[tt]>q)
        {
            q=dp[tt];
            while(l!=r)
            {
                int mid=(l+r)/2;
                if(dp[tt*2]==q){ r=mid;tt=tt*2;}
                else {l=mid+1; tt=tt*2+1;}
            }
            u=l;
        }
        return ;
    }

    int mid=(l+r)/2;
    if(mid<x)
        query(mid+1,r,tt*2+1,x,y);
    else if(y<=mid)
        query(l,mid,tt*2,x,y);
    else
    {
        query(l,mid,tt*2,x,mid);
        query(mid+1,r,tt*2+1,mid+1,y);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&rr[i]);
    }
    rr[n]=n;
    build(1,n,1);
    for(int i=n-1;i>=1;i--)
    {
        q=0;
        query(1,n,1,i+1,rr[i]);
        a[i]=n-i+a[u]-(rr[i]-u);
        ans+=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}