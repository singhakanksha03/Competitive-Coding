/*

Raymond “Red” Reddington is an international criminal hunted by the police forces of many countries. Recently, a joint Task Force, with the sole purpose of capturing Reddington, is launched, led by Agent Donald Ressler.
Red has managed to elude all the forces because he is always one step ahead. Before Ressler can catch him, Red manages to capture Ressler for interrogation.
Red is a huge fan of the game scrabble, and has created many modified versions of the game. He will let Ressler go, if he is able to solve one such version of the game.
The premise is quite simple. Ressler is given a string S which contains only digits. He needs to count the number of substrings of S, which are palindromes. There are some additional rules to be followed. Red explains them as follows -
Ressler needs to count the number of substrings of S, which are palindromes without leading zeros and can be divided by 3 without a remainder.
A string is a palindrome without leading zeros if it reads the same backward as forward and doesn't start with the symbol '0'.
Ressler should consider string "0" as a palindrome without leading zeros.
You need to help Agent Ressler.
Input Format:
The first and only line of input contains string S.
Constraints:
1 <= |S| <= 10^5
0 <= S[i] <= 9
Output Format:
Print the answer obtained.
Sample Input 1:
10686
Sample Output 1:
3
Explanation:
The three palindromic substrings are: 0, 6, 6.


*/


 
#include <bits/stdc++.h>
// #include <functional>
// #include <numeric>
// #include <iostream>
// #include <cstdio>
// #include <cmath>
// #include <cstdlib>
// #include <ctime>
// #include <cstring>
// #include <cassert>
// #include <vector>
// #include <list>
// #include <map>
// #include <set>
// #include <deque>
// #include <queue>
// #include <bitset>
// #include <sstream>
 
using namespace std;
 
#define fore(i, l, r) for(int i = (l); i < (r); ++i)
#define forn(i, n) fore(i, 0, n)
#define fori(i, l, r) fore(i, l, (r) + 1)
#define sz(v) int((v).size())
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
 
#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif
 
typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;
 
template<typename T> T abs(T a) { return a < 0 ? -a : a; }
template<typename T> T sqr(T a) { return a*a; }
 
const int INF = (int)1e9;
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;
 
/*
    This is just to check correctness of input
 
*/
void ensure(bool value){
    if(!value){
        fprintf(stderr, "Assertion failed");
        throw;
    }
}
void ensure(bool value, string message){
    if(!value){
        fprintf(stderr, "Assertion failed. Message = %s", message.c_str());
        throw;
    }
}
int readInt(int l, int r){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int in range [%d, %d], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int in range [%d, %d], but found %d!", l, r, x);
        throw;
    }
    return x;
}
int readInt(int l, int r, string name){
    int x;
    if(scanf("%d", &x) != 1){
        fprintf(stderr, "Expected int %s in range [%d, %d], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected int %s in range [%d, %d], but found %d!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
li readLong(li l, li r){
    li x;
    if(scanf(LLD, &x) != 1){
        fprintf(stderr, "Expected long long in range ["LLD", "LLD"], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected long long in range ["LLD", "LLD"], but found "LLD"!", l, r, x);
        throw;
    }
    return x;
}
li readLong(li l, li r, string name){
    li x;
    if(scanf(LLD, &x) != 1){
        fprintf(stderr, "Expected long long %s in range ["LLD", "LLD"], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x && x <= r)){
        fprintf(stderr, "Expected long long %s in range ["LLD", "LLD"], but found "LLD"!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
const ld __EPS__ = 1e-15;
ld readDouble(double l, double r){
    double x;
    if(scanf("%lf", &x) != 1){
        fprintf(stderr, "Expected double in range [%lf, %lf], but haven't found!", l, r);
        throw;
    }
    if(!(l <= x + __EPS__ && x <= r + __EPS__)){
        fprintf(stderr, "Expected double in range [%lf, %lf], but found %lf!", l, r, x);
        throw;
    }
    return x;
}
ld readDouble(double l, double r, string name){
    double x;
    if(scanf("%lf", &x) != 1){
        fprintf(stderr, "Expected double %s in range [%lf, %lf], but haven't found!", name.c_str(), l, r);
        throw;
    }
    if(!(l <= x + __EPS__ && x <= r + __EPS__)){
        fprintf(stderr, "Expected double %s in range [%lf, %lf], but found %lf!", name.c_str(), l, r, x);
        throw;
    }
    return x;
}
const int __MAXBUF__ = (int)1e7;
char __buf__[__MAXBUF__];
string readString(char lfc, char rgc, int lfn, int rgn){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "String contains incorrect characters");
    return ans;
}
string readString(string pat, int lfn, int rgn){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "String contains incorrect characters");
    return ans;
}
string readString(char lfc, char rgc, int lfn, int rgn, string name){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string " + name + ", haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String " + name + " have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "String " + name + " contains incorrect characters");
    return ans;
}
string readString(string pat, int lfn, int rgn, string name){
    ensure(scanf(" %s ", __buf__) == 1, "Expected string " + name + ", haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "String " + name + " have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "String " + name + " contains incorrect characters");
    return ans;
}
string readLine(char lfc, char rgc, int lfn, int rgn){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "Line have incorrect length");
    forn(i, sz(ans))
        ensure(lfc <= ans[i] && ans[i] <= rgc, "Line contains incorrect characters");
    return ans;
}
string readLine(string pat, int lfn, int rgn){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    ensure(lfn <= sz(ans) && sz(ans) <= rgn, "Line have incorrect length");
    forn(i, sz(ans))
        ensure(find(all(pat), ans[i]) != pat.end(), "Line contains incorrect characters");
    return ans;
}
string readLine(){
    ensure(gets(__buf__) != NULL, "Line expected, haven't found");
    string ans = __buf__;
    return ans;
}
char readChar(){
    char c;
    ensure(scanf(" %c ", &c) == 1, "Non-whitespace character expected");
    return c;
}
char readWChar(){
    int ans = getchar();
    ensure(ans != EOF, "Character expected");
    return (char)ans;
}
 
const int MOD = 3;
const int NMAX = 1e7;
 
int z[NMAX], sm[NMAX][MOD], pf[NMAX];
 
inline int cnt_pf(int lf, int rg, int val){
    if(lf > rg)
        return 0;
    return sm[rg][val] - (lf == 0 ? 0 : sm[lf - 1][val]);
}
 
int main(){
#ifdef ssu1
    assert(freopen("input.txt", "rt", stdin));
    //assert(freopen("output.txt", "wt", stdout));
#endif
 
    string s = readLine('0', '9', 1, 1000000);
 
    forn(i, sz(s)){
        pf[i] = (s[i] - '0') % 3;
        if(i > 0){
            pf[i] = (pf[i] + pf[i - 1]) % 3;
            memcpy(sm[i], sm[i - 1], sizeof(int) * 3);
        }
        if(!(i + 1 < sz(s) && s[i + 1] == '0'))
            sm[i][pf[i]]++;
    }
 
    li ans = 0;
 
    memset(z, 0, sizeof z);
    int l = 0, r = -1;
    forn(i, sz(s)){
        z[i] = (i <= r ? min(r - i + 1, z[l + (r - i)]) : 0);
        while(i - z[i] >= 0 && i + z[i] < sz(s) && s[i - z[i]] == s[i + z[i]])
            z[i]++;
 
        int curd = (s[i] - '0') % 3;
        int want = ((3 - curd) * 2 + curd) % 3;
        int lf = i - z[i] + 1;
 
        ans += cnt_pf(max(0, lf - 1), i - 1, (pf[i] - want + 3) % 3);
        if(lf == 0 && s[0] != '0' && pf[i] == want)
            ans++;
        if(s[i] == '0')
            ans++;
 
        if(i + z[i] - 1 >= r)
            l = i - z[i] + 1, r = i + z[i] - 1;
    }
 
    memset(z, 0, sizeof z);
    l = 0, r = -1;
    fore(i, 1, sz(s)){
        z[i] = (i <= r ? min(r - i + 1, z[l + (r - i) + 1]) : 0);
        while(i - z[i] - 1 >= 0 && i + z[i] < sz(s) && s[i - z[i] - 1] == s[i + z[i]])
            z[i]++;
 
        if(z[i] > 0){
            int want = 0, lf = i - z[i];
            ans += cnt_pf(max(0, lf - 1), i - 2, (pf[i - 1] - want + 3) % 3);
            if(lf == 0 && s[0] != '0' && pf[i - 1] == want)
                ans++;
        }
 
        if(r < i + z[i] - 1)
            l = i - z[i], r = i + z[i] - 1;
    }
    cout << ans << endl;
    return 0;
} 