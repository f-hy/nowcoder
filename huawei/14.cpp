/**
 * @file 14.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-02-22
 * @version 0.1
 * @brief nowcoder practice
 * @gitee https://gitee.com/friendhy/nowcoder
 * @copyright Copyright (c) 2023
 */
#include<iostream>
#include<set>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
int n;
string s;
multiset<string> ms;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    rep(i,1,n){
        cin>>s;
        ms.insert(s);
    }
    for(auto &x:ms) cout<<x<<endl;
    return 0;
}