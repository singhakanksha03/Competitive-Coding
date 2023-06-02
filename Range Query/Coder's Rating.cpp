/*
Some of the more elite (and not-so-elite) coders around take part in a certain unnamed programming contest. In said contest, there are multiple types of competitions. Here, we consider the Open and High School competition types. For each type, each competitor receives a rating, an integer between 1 and 100000, inclusive. A coder's rating is based upon his or her level of performance in matches and is calculated using a complicated formula which, thankfully, you will not be asked to implement.
Although the Open and High School ratings for a coder who has participated in both competition types lately are usually close, this is not always the case. In particular, High School matches are more about speed, since many coders are able to solve all the problems, whereas Open matches require more thinking and there is a steeper curve in terms of problem difficulty.
Problem Statement
You are given N coders (1 ≤ N ≤ 300000), conveniently numbered from 1 to N. Each of these coders participates in both High School and Open matches. For each coder, you are also given an Open rating Ai and a High School rating Hi. Coder i is said to be better than coder j if and only if both of coder i's ratings are greater than or equal to coder j's corresponding ratings, with at least one being greater. For each coder i, determine how many coders coder i is better than.
Input Format
On the first line of input is a single integer N, as described above. N lines then follow. Line i+1 contains two space-separated integers, Ai and Hi.
Output Format
 Line i should contain the number of coders that coder i is better than.
Sample Input 1:
8
1798 1832
862 700
1075 1089
1568 1557
2575 1984
1033 950
1656 1649
1014 1473
Sample Output 1:
6
0
2
4
7
1
5
1
Explanation
1st code is better than 2nd, 3rd, 4th, 5th, 6th and 7th coder.
Hence he is better than 6 coders.

*/


#include<bits/stdc++.h>
using namespace std;
struct coder
{
	int x,y,index;
};
int bit[100001];
void update(int y){
	for(;y<=100000;y+= y&(-y)){
		bit[y]++;
	}
}
int query(int y){
	int value = 0;
	for(;y>0;y-= y&(-y)){
		value += bit[y];
	}
	return value;
}
bool operator < (coder A, coder B){
	if(A.x == B.x){
		return A.y < B.y;
	}
	return A.x < B.x;
}
int main(){
	int n;
	cin >> n;
	coder arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i].x >> arr[i].y;
		arr[i].index = i;
    }
	sort(arr,arr+n);
	int ans[n];
	for(int i=0;i<n;){
		int endIndex = i;
		while(endIndex <n && arr[endIndex].x == arr[i].x && arr[endIndex].y== arr[i].y){
			endIndex++;
		}
	// query
		for(int j=i;j<endIndex;j++){
			ans[arr[j].index] = query(arr[j].y);
		}
		for(int j=i;j<endIndex;j++){
			update(arr[j].y);
		}
		i = endIndex;
		// update
	}
	for(int i=0;i<n;i++){
		cout << ans[i] <<endl;
	}
	return 0;
}