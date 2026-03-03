/*

https://www.codingninjas.com/codestudio/problems/min-heap_4691801?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

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

class PriorityQueue {
    
    vector<int> pq ;
    public:
    PriorityQueue() {
        
    }

    void insert(int element) {
        pq.push_back(element) ;
        int childIndex = getSize()-1;
        int parentIndex ;
        while(childIndex!=0){
            parentIndex = (childIndex-1)/2 ;
            if(pq[childIndex] < pq[parentIndex])
                pq[childIndex] = (pq[childIndex]+ pq[parentIndex])-
            (pq[parentIndex]=pq[childIndex]) ;
            else
                break ;
            childIndex = parentIndex ;
        }
    }

    int getMin() {
        if(isEmpty())
            return INT_MIN ;
        return pq[0] ;
    }

    int removeMin() {
        if(isEmpty())
            return INT_MIN ;

        int delEl = pq[0] ;
        int size = getSize() ;

        pq[0] = pq[size-1] ;

        pq.pop_back() ;
        size-- ;
        int minChildIndex , parentIndex , leftChildIndex , rightChildIndex; 

        parentIndex = 0 ;
        while(true){
            leftChildIndex = 2*parentIndex+1 ;
            rightChildIndex = leftChildIndex+1 ;
            // checking if childs exists
            if(leftChildIndex < size){
                if(rightChildIndex < size) // checking if right child exists
                    minChildIndex = pq[leftChildIndex] < pq[rightChildIndex] ?
                leftChildIndex : rightChildIndex ;
                // we need to take min among left and right childs
                else
                    minChildIndex = leftChildIndex ;

                if(pq[parentIndex] > pq[minChildIndex])
                    pq[parentIndex] = (pq[parentIndex]+pq[minChildIndex])-
                (pq[minChildIndex]=pq[parentIndex]) ;
                else
                    break ;
                parentIndex = minChildIndex ;
            }
            else
                break ;
        }

        return delEl ;
    }

    int getSize() { 
        return pq.size() ;
    }

    bool isEmpty() {
        return getSize() == 0 ;
    }
};

vector<int> minHeap(int N, vector<vector<int>>& Q) {
    
    PriorityQueue min_heap ; 
    vector<int> res ; 
    for(int q = 0 ; q<N ; q++ ){
        vector<int> query = Q[q] ; 
        if(query[0] == 0 ){
            min_heap.insert(query[1]) ; 
        }else {
            //cout << min_heap.removeMin() << endl  ; 
            res.push_back(min_heap.removeMin()) ; 
        }
    }
    return res ; 
}


int main() {
    init_code() ; 
    Solution sol ; 

    
}