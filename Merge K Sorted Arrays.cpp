/*

https://www.codingninjas.com/codestudio/problems/merge-k-sorted-arrays_975379
https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1

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

class Triplet{
    public:
    int element;
    int arrayIndex;
    int elementIndex;

    Triplet(int element ,
     int arrayIndex , int elementIndex) : element(element) , arrayIndex(arrayIndex) , 
     elementIndex(elementIndex)
     {}
};

class Comp{
    public:
    bool operator ()    (Triplet a, Triplet b)  {
    return a.element>b.element;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&input, int k)
{
    // min priority queue
    priority_queue <Triplet, vector<Triplet>, Comp > pq;
    
    vector<int> output ;

    // first we are inserting all first elements of k  arrays 
    for(int i=0; i<k ; i++){
        Triplet t(input[i][0] , i , 0) ;
        pq.push(t) ;
    }
    // then removing them one by one to add into another 
    // vector , which ever element is removed ,from that array 
    // we should take next index and push to the pq 
    while(!pq.empty()){
        Triplet temp = pq.top() ;
        pq.pop() ;

        output.push_back(temp.element); 
        int arrayIndex = temp.arrayIndex ;
        int elementIndex = temp.elementIndex ;

        if(elementIndex+1 < input[arrayIndex].size())
        {
            Triplet t(input[arrayIndex][(elementIndex+1)] , arrayIndex , elementIndex+1) ;
            pq.push(t) ;
        } 
    }
    return output ;
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}