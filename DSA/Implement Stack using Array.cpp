/*

https://www.codingninjas.com/codestudio/problems/stack-implementation-using-array_3210209

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

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    
public:
    int *data;
    int nextIndex;
    int capacity;  

    Stack(int capacity) {
        // Write your code here.
        this->capacity = capacity;
        data = new int[capacity];
        nextIndex = 0;
        
    }

    void push(int element) {
        // Write your code here.
        if(nextIndex == capacity) {
            int *newData = new int[2 * capacity];
            for(int i = 0; i < capacity; i++) {
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
            /*cout << "Stack full " << endl;
            return;*/
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop() {
        if(isEmpty()) {
            //cout << "Stack is empty " << endl;
            return -1 ; 
        }
        nextIndex--;
        return data[nextIndex];
    }
    
    int top() {
        if(isEmpty()) {
            //cout << "Stack is empty " << endl;
            return -1 ; 
        }
        return data[nextIndex - 1];
    }
    
    int isEmpty() {
        return nextIndex == 0 ; 
    }
    
    int isFull() {
        return nextIndex == capacity ; 
    }
    
};


int main() {
    init_code() ; 
    Solution sol ; 

    
}