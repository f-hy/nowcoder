#include<iostream>
namespace sorts{
    template<typename T>
    void swap(T &a,T &b){
        T t=a;
        a=b;
        b=t;
    }
    template<typename T>
    void swap(T arr[],int i,int j){
        T t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;
    }
}
template<typename T>
void bubbleSort(T arr[], int len){
    for(int i=0;i<len;++i)
        for(int j=0;j<len-1-i;++j)
            if(arr[j]>arr[j+1])
                sorts::swap(arr[j],arr[j+1]);
}
template<typename T>
void selectionSort(T arr[],int len){
    for(int i=0;i<len-1;++i){
        int minIndex=i;
        for(int j=i+1;j<len;++j)
            if(arr[j]<arr[minIndex])
                minIndex=j;
        sorts::swap(arr[i],arr[minIndex]);
    }
}
template<typename T>
void insertionSort(T arr[],int len){
    //
}
/**
 * @brief 左小右大，arr[start]在j
 * 
 * @tparam T 
 * @param arr the array
 * @param start start position
 * @param tail end position
 * @return int the position of arr[i]
 */
template<typename T>
T partition(T arr[],int start,int tail){
    int i=start,j=tail+1;
    while(true){
        while(arr[++i]<arr[start]&&i<tail);
        while(arr[--j]>arr[start]&&j>start);
        if(i>=j) break;//可能j<=i，此时i左边的数小于start的，j右边的数大于start的
        sorts::swap(arr,i,j);
    }
    sorts::swap(arr,start,j);//j要指向比start小的数或其本身，故swap j
    return j;
}
/**
 * @brief https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
 * 
 * @tparam T 
 * @param arr 
 * @param k 
 * @param len 
 * @return T 
 */
template<typename T>
T findKthLargest(T arr[],int k,int len){
    k=len-k;
    int l=0,r=len-1;
    while(l<r){
        int j=partition(arr,l,r);
        if(j==k) break;
        else if(j<k) l=j+1;
        else r=j-1;
    }
    return arr[k];
}



