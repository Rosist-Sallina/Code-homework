#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#define LL long long

using namespace std;
int l, r, len, bj;
string s;
int pd(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
int main()
{
    getline(cin, s);
    len = s.length();
    if (len == 0) { printf("1"); return 0; }
    l = 0; r = len - 1;
    while (l <= r)
    {
        while (!pd(s[l]) && l < len - 1)++l;
        while (!pd(s[r]) && r)--r;
        if (l >= len - 1 || r < 0)break;
        //		cout<<l<<" "<<r<<" "<<int('A')<<" "<<int('a')<<endl;
        if (s[l] == s[r] || abs(s[l] - s[r]) == 32) { ++l; --r; }
        else { bj = 1; break; }
    }
    printf(bj ? "0" : "1");
    return 0;
}
