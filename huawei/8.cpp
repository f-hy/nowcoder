/**
 * @file 8.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-02-22
 * @version 0.1
 * @brief nowcoder practice
 * @gitee https://gitee.com/friendhy/nowcoder
 * @copyright Copyright (c) 2023
 */
#include<iostream>
#include<map>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
int n;
map<int,int> res;
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n;
    int idx,val;
    rep(i,1,n){
        cin>>idx>>val;
        if(!res.count(idx)) res[idx]=val;
        else res[idx]+=val;
    }
    for(auto &x:res){
        cout<<x.first<<' '<<x.second<<endl;
    }
    return 0;
}