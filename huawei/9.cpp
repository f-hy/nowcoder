/**
 * @file 9.cpp
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
int n;
bool get[10];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    int cur;
    while(n){
        cur=n%10;
        n/=10;
        if(!get[cur]){
            cout<<cur;
            get[cur]=true;
        }
    }
    return 0;
}