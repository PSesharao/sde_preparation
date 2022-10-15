/*

https://www.interviewbit.com/problems/maximum-sum-combinations/

1)Sort both arrays array A and array B.

2)Create a max heap i.e priority_queue in C++ to store the sum combinations 
along with the indices of elements from both arrays A and B which make up the sum. 
Heap is ordered by the sum.

3)Initialize the heap with the maximum possible sum combination i.e 
(A[N – 1] + B[N – 1] where N is the size of array) and with the 
indices of elements from both arrays (N – 1, N – 1). The tuple inside max heap will be 
(A[N-1] + B[N – 1], N – 1, N – 1).
 Heap is ordered by first value i.e sum of both elements.

4)Pop the heap to get the current largest sum and along with the indices of the element that 
make up the sum. Let the tuple be (sum, i, j).

5)Next insert (A[i – 1] + B[j], i – 1, j) and (A[i] + B[j – 1], i, j – 1) into the max heap but 
make sure that the pair of indices i.e (i – 1, j) and (i, j – 1) are not 
already present in the max heap. To check this we can use set in C++.

6)Go back to 4 until K times.

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
    public : 
    int sum ; 
    int indexA ; 
    int indexB ; 

    Triplet(    int sum , int indexA , int indexB  ) {
        this->sum = sum ; 
        this->indexA = indexA ; 
        this->indexB = indexB ; 
    }
};

class Comp{
    public:
    bool operator ()    (Triplet &a, Triplet &b)  {
    return a.sum<b.sum; // max heap
    }
};

vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int N = A.size(); 
    vector<int> res(C) ; 
    priority_queue<Triplet ,vector<Triplet> , Comp > pq ; 
    set<pair<int, int> > indices_set; 
    Triplet t(A[N - 1] + B[N - 1] , N-1 , N-1 ) ; 
    pq.push(t) ; 
    indices_set.insert({N-1 , N-1}) ; 
    int counter = 0 ; 
    while(counter < C ) {
        Triplet top_t = pq.top() ; 
        pq.pop() ; 
        res[counter++] = top_t.sum ; 
        int curr_A_index = top_t.indexA ; 
        int curr_B_index = top_t.indexB ; 
        int next_sum ; 

        if(curr_A_index-1 >=0 and indices_set.count({curr_A_index-1 , curr_B_index })== 0 ){
            next_sum = A[curr_A_index-1] + B[curr_B_index] ; 
            indices_set.insert({curr_A_index-1 , curr_B_index }) ; 
            Triplet next_t (next_sum , curr_A_index-1 , curr_B_index ) ; 
            pq.push(next_t) ; 
        }

        if(curr_B_index-1 >=0 and indices_set.count({curr_A_index , curr_B_index-1 })== 0 ){
            next_sum = A[curr_A_index] + B[curr_B_index-1] ; 
            indices_set.insert({curr_A_index , curr_B_index-1 }) ; 
            Triplet next_t (next_sum , curr_A_index , curr_B_index-1 ) ; 
            pq.push(next_t) ; 
        } 
    }
    return res ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}