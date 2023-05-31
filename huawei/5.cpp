/**
 * @file 5.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-02-22
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
const int del=16;
string s;
int ans;
int val(char c){
    if(isdigit(c)) return c-'0';
    else if (isupper(c)) return 10+c-'A';
    else return 10+c-'a';
}
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>s;
    rep(i,2,s.size()-1){
        ans*=del;
        ans+=val(s[i]);
    }
    cout<<ans;
    return 0;
}