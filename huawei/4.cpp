/**
 * @file 4.cpp
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
const int len=8;
string s;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    getline(cin,s);
    int groups=s.size()/8;
    rep(i,0,groups-1){
        rep(j,0,len-1) cout<<s[len*i+j];
        cout<<endl;
    }
    int remainder=s.size()%8;
    if(remainder){
        int start=s.size()-remainder;
        rep(i,start,s.size()-1) cout<<s[i];
        rep(i,1,8-remainder) cout<<'0';
    }
    return 0;
}