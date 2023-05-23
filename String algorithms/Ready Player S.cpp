/*
OASIS is a virtual reality created by the legendary James Halliday. After Halliday's death, a pre-recorded message left by him announced a game, which would grant the ownership and control of the OASIS to the first player who finds the Golden Easter Egg within it.
Shivali, an OASIS player, is obsessed with the game and finding the Easter Egg. But she has to fight the IOI clan, who wants to control OASIS for evil purposes. Both of them gather troops of different types and form a big army to fight each other.
IOI has N troops of lowercase letters forming a huge army. Shivali has an army of length M.
She will win, if the first k troops she takes from her army, can kill any of the k consecutive troops of the IOI army.
Remember a troop of type 'a' can only kill a troop of type 'a'.
You have to find how many times she can win.
Input Format:
The first line of input contains N, M and k, space separated.
Next two lines contains the string of troops of length N and M respectively in lowercase letters.
Constraints:
1 <= N, M <= 10^6
1 <= K <= M
Output Format:
Output the number of wins she is going to take at the end of the day. Print -1 if she can't win.
Sample Input 1:
3 2 1
bbb
bb
Sample Output 1:
3
*/

#include <iostream>
using namespace std;
 
void computeLPSArray(string pat, int M,
                                 int lps[])
{
     
    // Length of the previous longest
    // prefix suffix
    int len = 0;
    int i = 1;
    lps[0] = 0; // lps[0] is always 0
 
    // The loop calculates lps[i] for
    // i = 1 to M-1
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
             
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0)
            {
                len = lps[len - 1];
 
                // Also, note that we do not
                // increment i here
            }
            else // if (len == 0)
            {
                lps[i] = len;
                i++;
            }
        }
    }
}
 
int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
 
    // Create lps[] that will hold the longest
    // prefix suffix values for pattern
    int lps[M];
    int j = 0; // index for pat[]
 
    // Preprocess the pattern (calculate lps[]
    // array)
    computeLPSArray(pat, M, lps);
 
    int i = 0; // index for txt[]
    int res = 0;
    int next_i = 0;
 
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
             
            // When we find pattern first time,
            // we iterate again to check if there
            // exists more pattern
            j = lps[j - 1];
            res++;
        }
 
        // Mismatch after j matches
        else if (i < N && pat[j] != txt[i])
        {
             
            // Do not match lps[0..lps[j-1]]
            // characters, they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    if(res==0){
        return -1
    }
    return res;
}
 
// Driver code
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k>m){
        cout<<-1<<endl;
    }
    
    string txt ,pat;
    cin>>txt>>pat;
    string temp=pat.substr(0,k);
    int ans = KMPSearch(temp, txt);
     
    cout << ans<<endl;
     
    return 0;
}