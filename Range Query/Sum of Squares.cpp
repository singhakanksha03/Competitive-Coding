/*
Segment trees are extremely useful. In particular "Lazy Propagation" (i.e. see here, for example) allows one to compute sums over a range in O(lg(n)), and update ranges in O(lg(n)) as well. In this problem you will compute something much harder:
The sum of squares over a range with range updates of 2 types:
1) increment in a range
2) set all numbers the same in a range.
There will be T test cases in the input file. First line of the input contains two positive integers, N and Q.
The next line contains N integers, each at most 1000. Each of the next Q lines starts with a number, which indicates the type of operation:
2 st nd -- return the sum of the squares of the numbers with indices in [st, nd] {i.e., from st to nd inclusive} (1 <= st <= nd <= N).

1 st nd x -- add "x" to all numbers with indices in [st, nd] (1 <= st <= nd <= N, and 1 <= x <= 1,000).

0 st nd x -- set all numbers with indices in [st, nd] to "x" (1 <= st <= nd <= N, and 1 <= x <= 1,000).
Input Format:
First line of input will contain T(number of test case), each test case follows as.
Line 1: contain two space-separated integers denoting the value of N and Q respectively
Line 2: contain N space-separated integers denoting th value of array elements
Next Q line contain the space separated value for queries as defined as above.
Constraints:
1 <= T <= 10
1 <= N <= 10000
1 <= arr[i] <= 1000
1 <= Q <= 10000
Output Format:
For each test case, print the answer in new line for query of type 2
Sample Input 1:
2
4 5
1 2 3 4
2 1 4
0 3 4 1
2 1 4
1 3 4 1
2 1 4
1 1
1
2 1 1
Sample Output 1:
30
7
13
1

*/


#include<bits/stdc++.h>
using namespace std;
int t,n,q;
const int mxn=(1e5)+6;
int a[mxn];
long long st[mxn*4];
long long su[mxn*4];
long long laz[mxn*4][2];

void build(int p,int l,int r)
{
    if(l==r)st[p]=(a[l]*a[l]),su[p]=a[l];
    else
    {
        int m=(l+r)/2;
        st[p*2]=0;
        st[p*2+1]=0;
        build(p*2,l,m);
        build(p*2+1,m+1,r);
        st[p]=st[p*2]+st[p*2+1];
        su[p]=su[p*2]+su[p*2+1];
    }
}
//laz[p][0]: set query
//laz[p][1]: add query
void pros(int p,int l,int r)
{
    if(laz[p][0]!=0)
    {
        st[p]=(laz[p][0]*laz[p][0])*((r-l)+1);
        su[p]=laz[p][0]*((r-l)+1);
        if(l!=r)
        {
            laz[p*2][0]=laz[p][0];
            laz[p*2][1]=0;
            laz[p*2+1][0]=laz[p][0];
            laz[p*2+1][1]=0;
        }
        laz[p][0]=0;
    }
    if(laz[p][1]!=0)
    {
        st[p]=(st[p]+(2*laz[p][1]*su[p])+(laz[p][1]*laz[p][1]*(r-l+1)));
        su[p]=(su[p]+(laz[p][1]*(r-l+1)));
        if(l!=r)
        {
            if(laz[p*2][0]!=0)
                laz[p*2][0]+=laz[p][1];
            else
                laz[p*2][1]+=laz[p][1];
            
            if(laz[p*2+1][0]!=0)
                laz[p*2+1][0]+=laz[p][1];
            else
                laz[p*2+1][1]+=laz[p][1];
        }
        laz[p][1]=0;
    }
}

void update(int p,int l,int r,int i,int j,int xx)
{
    pros(p,l,r);
    if(r<i||l>j)return;
    if(l>=i&&r<=j)
    {
        laz[p][1]+=xx;
        pros(p,l,r);
        return;
    }
    int m=(l+r)/2;
    update(p*2,l,m,i,j,xx);
    update(p*2+1,m+1,r,i,j,xx);
    st[p]=st[p*2]+st[p*2+1];
    su[p]=su[p*2]+su[p*2+1];
}

void change(int p,int l,int r,int i,int j,int xx)
{
    pros(p,l,r);
    if(r<i||l>j)return;
    if(l>=i&&r<=j)
    {
        laz[p][0]=xx;
        pros(p,l,r);
        return;
    }
    int m=(l+r)/2;
    change(p*2,l,m,i,j,xx);
    change(p*2+1,m+1,r,i,j,xx);
    st[p]=st[p*2]+st[p*2+1];
    su[p]=su[p*2]+su[p*2+1];
}

long long rsq(int p,int l,int r,int i,int j)
{
    pros(p,l,r);
    if(r<i||l>j)return 0;
    if(l>=i&&r<=j)return st[p];
    int m=(l+r)/2;
    return rsq(p*2,l,m,i,j)+rsq(p*2+1,m+1,r,i,j);
}

int main()
{
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        st[1]=0;
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        build(1,0,n-1);
        //printf("Case %d:\n",test);
        int l,r,ty,xx;
        while(q--)
        {
            scanf("%d%d%d",&ty,&l,&r);
            if(ty==0)
            {
                scanf("%d",&xx);
                change(1,0,n-1,l-1,r-1,xx);
            }
            else if(ty==1)
            {
                scanf("%d",&xx);
                update(1,0,n-1,l-1,r-1,xx);
            }
            else printf("%lld\n",rsq(1,0,n-1,l-1,r-1));
        }
    }
    return 0;
}