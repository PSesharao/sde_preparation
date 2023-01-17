/*

https://www.codingninjas.com/codestudio/problems/615?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Here we should not worry about change in the order of the array 
as in merge sort
we will deep down into one element, compare two elements(calculate inversion counts) , 
and put it in a new array in sorted order.

i.e we are calculating inversion before sorting . 

*/


#include <bits/stdc++.h>
using namespace std;
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define MAX 200010

void init_code()
{
    fast_io;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


ll merge(int l , int mid , int r , ll *arr){
    ll inversion_count = 0LL ;  
    int left_array_size = mid-l+1 ; 
    int right_array_size = r-mid ; 

    ll left_array[left_array_size] ; 
    ll right_array[right_array_size] ; 

    int left_index , right_index , arr_index = l ;
    
    for(left_index = 0 ; left_index<left_array_size ; left_index++ )
        left_array[left_index] = arr[arr_index++] ; 

    for(right_index=0 ; right_index<right_array_size ; right_index++ )
        right_array[right_index] = arr[arr_index++] ; 

    left_index = 0 ; right_index =0 ; arr_index = l ; 

    while((left_index < left_array_size) and (right_index<right_array_size)){
        if( left_array[left_index] > right_array[right_index] ){
            inversion_count += left_array_size - left_index ; 
            arr[arr_index++] = right_array[right_index++] ; 
        }else{
            arr[arr_index++] = left_array[left_index++] ;
        }
    }

    while(left_index < left_array_size){
        arr[arr_index++] = left_array[left_index++] ;
    }

    while(right_index<right_array_size){
        arr[arr_index++] = right_array[right_index++] ; 
    }

    return inversion_count ; 
}

ll mergeSort(ll *arr , int l , int r  ){
    if(l<r){
        int mid = l+(r-l)/2 ; 
        ll leftAns = mergeSort(arr , l , mid ) ;
        ll rightAns = mergeSort(arr , mid+1 , r ) ;
        ll mergeAns = merge(l , mid , r , arr ) ;
        return leftAns + rightAns + mergeAns ;   
    }
    return 0LL ;
} 

long long getInversions(long long *arr, int n){
    return mergeSort(arr , 0 , n-1 ) ; 
}


int main() {
    init_code() ; 
    

    
}