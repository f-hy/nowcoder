#include<iostream>
namespace search{
}
template<typename T>
int binarySearch(T nums[],int len,T key){
    int l=0,r=len-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(nums[m]==key) return m;
        else if(nums[m]>key) r=m-1;
        else l=m+1;
    }
    return -1;
}
template<typename T>
int binarySearchl(T nums[],int len,T key){
    if(nums[0]>key||nums[len-1]<key) return -1;
    int l=0,r=len-1;
    while(l<r){
        int m=l+(r-l)/2;
        if(nums[m]>=key) r=m;
        else l=m+1;
    }
    return l;
}