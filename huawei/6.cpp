/**
 * @file 6.cpp
 * @author Friendy (friend0@qq.com)
 * @date 2023-02-22
 * @version 0.1
 * @brief nowcoder practice
 * @gitee https://gitee.com/friendhy/nowcoder
 * @copyright Copyright (c) 2023
 */
#include<iostream>
#include<cmath>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define file(x) freopen(#x ".in", "r", stdin); freopen(#x ".out", "w", stdout);
#define rep(i,s,t) for(int i=s;i<=t;i++)
#define dwn(i,s,t) for(int i=s;i>=t;i--)
#define ite(it,s,e) for(auto it=s;it!=e;++it)
bool is_prime(int n){
    if(n<2) return false;
    rep(i,2,floor(sqrt(n)+0.5)) if(n%i==0) return false;
    return true;
}
void print_prime_factors(int n){
    if(n<2) return;
    int start=2;
    while(n>1){
        if(is_prime(n)){
            cout<<n;
            return;
        }
        if(n%start) ++start;
        else{
            n/=start;
            cout<<start<<' ';
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    // file(data);
    int n;
    cin>>n;
    print_prime_factors(n);
    return 0;
}