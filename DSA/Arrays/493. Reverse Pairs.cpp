/*

https://leetcode.com/problems/reverse-pairs/

Time Complexity : O( N log N ) + O (N) + O (N)   

Reason : O(N) – Merge operation , O(N) – counting operation 
( at each iteration of i , j doesn’t start from 0 . Both of them move linearly )


The inner loop increments right_index as long as left_array[left_index] > 2LL * right_array[right_index], meaning as long as the current element from the left subarray is greater than twice the current element from the right subarray. When this condition is no longer true, it means that right_index represents the count of reverse pairs for the current element in the left subarray, which is added to the overall count.

Example : 

[3 , 4 , 11 ] [1 , 4, 5] 

first pass 
(3 , 1 ) 

2nd pass 
(4 , 1)

3rd pass

(11 ,1 ) (11 , 4) (11 , 5)
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

ll merge(int l , int mid , int r , vector<int>& arr){
    ll inversion_count = 0LL ;  

    // Commented this counting here 

    // int j= mid+1 ; 
    // for(int i=l ; i<=mid ; i++){
    //     while( j<=r and arr[i]>2LL*arr[j] )
    //         j++ ;
    //     inversion_count += (j - (mid+1)) ; 
    // }
    
    

    int left_array_size = mid-l+1 ; 
    int right_array_size = r-mid ; 

    ll left_array[left_array_size] ; 
    ll right_array[right_array_size] ; 

    int left_index =0 , right_index = 0 , arr_index = l ;


    
    for(left_index = 0 ; left_index<left_array_size ; left_index++ )
        left_array[left_index] = arr[arr_index++] ; 

    for(right_index=0 ; right_index<right_array_size ; right_index++ )
        right_array[right_index] = arr[arr_index++] ; 

    left_index = 0 ; right_index =0 ; arr_index = l ; 

    // calculating the inversion count O(n) operation

    for(left_index =0 ; left_index < left_array_size ; left_index ++ ){
        while((right_index < right_array_size) and (left_array[left_index] > 2LL * right_array[right_index]) )
            right_index ++ ; 
        inversion_count += (right_index) ; 
    }


    // merging part    
    left_index = 0 ; right_index =0 ; arr_index = l ;     

    while((left_index < left_array_size) and (right_index<right_array_size)){
        if( left_array[left_index] > right_array[right_index] ){
            
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

ll mergeSort( vector<int>& arr, int l , int r  ){
    if(l<r){
        int mid = l+(r-l)/2 ; 
        ll leftAns = mergeSort(arr , l , mid ) ;
        ll rightAns = mergeSort(arr , mid+1 , r ) ;
        ll mergeAns = merge(l , mid , r , arr ) ;
        return leftAns + rightAns + mergeAns ;   
    }
    return 0LL ;
}

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums , 0 , nums.size()-1) ; 
    }
};

int main() {
    init_code() ; 
    Solution sol ; 

    
}