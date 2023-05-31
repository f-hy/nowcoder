/**
 * @file 16.cpp
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
const int maxm=60;
const int maxv=2*10000;
int n,m;
pair<int,int> vh[maxm],vs[maxm];//number value satisfaction
int cntvh;
int f[2][maxv];
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    cin>>n>>m;
    int v,p,q;
    rep(i,1,m){
        cin>>v>>p>>q;
        if(!q) vh[i]={v,v*p};
        else{
            vh[q].second+=(v*p);
            vh[q].first+=v;
        }
    }
    rep(i,1,m) if(vh[i].second) vs[++cntvh]=vh[i];
    rep(i,1,cntvh) rep(j,1,maxv){
        f[i&1][j]=f[(i-1)&1][j];
        if(j>=vs[i].second) f[i&1][j]=max(f[(i-1)&1][j],f[(i-1)&1][j-vs[i].second]+c[i]);
    }
    return 0;
}