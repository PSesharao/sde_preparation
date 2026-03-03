/*

https://www.codingninjas.com/codestudio/problems/2099908?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

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

class Queue {

    int *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Queue() {
        // Implement the Constructor
        capacity = 10 ; 
        data = new int[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return size == 0; 
    }

    void enqueue(int element ) {
        // Implement the enqueue() function
        if(size == capacity) {
            int *newData = new int[2 * capacity];
            int j = 0;
            // copying in order of insertion
            for(int i = firstIndex; i < capacity; i++) {
                newData[j] = data[i];
                j++;
            }
            // copying the circular elements in front 
            for(int i = 0; i < firstIndex; i++) {
                newData[j] = data[i];
                j++;
            }

            delete [] data;
            data = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity *= 2;
            //cout << "Queue Full ! " << endl;
            // return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity ;
        if(firstIndex == -1) {
            firstIndex = 0;
        }
        size++;
    }

    int dequeue() {
        // Implement the dequeue() function

        if(isEmpty()) {
            
            return -1;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;
        // This is for circular insertion 
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    int front() {
        // Implement the front() function
        if (isEmpty())
        {
            return -1 ;
            // 0 is generic type for all templates for NULL
        }
        return data[firstIndex];
    }

} ;


int main() {
    init_code() ; 
    Solution sol ; 

    
}