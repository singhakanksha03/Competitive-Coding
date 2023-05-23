/*

You are given an string S and a test string T. You have to find whether string S is a substring of the string T.
Input Format:
First line of input will contain an integer T, representing the number of test cases
Each test case is as follows:
Line 1: contains the string S.
Line 2: contains the string T.
Constraints:
1 <= T <= 100
1 <= |S|, |T| <= 10^5
Output Format:
For each test case print "Yes" if S is present in T or "No" otherwise.
Sample Input 1:
2
ye
wnpnzijdi
ao
jaoalc
Sample Output 1:
No
Yes

*/


#include <iostream>
using namespace std;
int *getLPS(string pattern)
{
    int n = pattern.length();
    int *lps = new int[n];
    lps[0] = 0;
    int i = 1;
    int j = 0;
    while (i < n)
    {
        if (pattern[i] == pattern[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
int findKMP(string text, string pattern)
{
    int *lps = getLPS(pattern);
    int patternLen = pattern.length();
    int textLen = text.length();
    int i = 0, j = 0;
    while (i < textLen && j < patternLen)
    {
        if(text[i]==pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return j==patternLen?i-j:-1;
}
int findString(string S, string T)
{
    //making string from the character arrays.
    string text="";
    string pattern="";
    if(S.length()>T.length()){
        return findKMP(S, T);
    }
    else{
        return findKMP(T, S);
    }
    // for(int i=0; S[i]!='\0'; i++)
    // {
    //     text+=S[i];
    // }
    // for(int i=0; T[i]!='\0'; i++)
    // {
    //     pattern+=T[i];
    // }
    
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        //cout<<findString(s1,s2);
        if(findString(s1,s2)!=-1){
            cout<<"Yes"<<endl;;
        }else{
            cout<<"No"<<endl;
        }
    }
}