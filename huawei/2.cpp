/**
 * @file 2.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-02-21
 * @version 0.1
 * @brief nowcoder practice
 * @gitee https://gitee.com/friendhy/nowcoder
 * @copyright Copyright (c) 2023
 */
#include<iostream>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
string s;
char c;
int cnt;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    getline(cin,s);
    cin>>c;
    if(isalpha(c)){
        c=toupper(c);
        rep(i,0,s.size()-1) if(c==(isupper(s[i])?s[i]:toupper(s[i]))) ++cnt;
    }else rep(i,0,s.size()-1) if(c==s[i]) ++cnt;
    cout<<cnt;
    return 0;
}