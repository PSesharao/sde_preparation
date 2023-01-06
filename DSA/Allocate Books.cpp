/*

https://www.interviewbit.com/problems/allocate-books/


understanding the question 

Input: A = [12, 34, 67, 90]
       B = 2

Let’s see all possible cases of how books can be allocated for each student.

12 | 34 67 90

12 34 | 67 90

12 34 67 | 90

the maximum of each case [191,157,113] and the minimum among them is 113 

let us imagine there are n books and n students 

then the maximum a student can get is one book per head , 
so that the minimizing that would be finding min of all n books 

let us imagine there are n books and 1 students 

then the maximum a student can get is all books , that's the only possible case 

so now our answer would lie in between these two extremes

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

// This will determine if any student does not get more than min_pages 
int isPossible(vector < int > & A, int pages, int no_of_students_present ) {

    int req_no_of_stu = 1 ;
    int pages_alloted_to_curr_stu = 0 ;
    for(int i=0 ; i<A.size() ; i++ ){
        int current_pages = A[i] ; 
        if(current_pages > pages ) 
            return false ; 
        if(pages_alloted_to_curr_stu + current_pages > pages ){
            // We need extra student here and alloting current pages to him 
            req_no_of_stu ++ ; 
            pages_alloted_to_curr_stu = current_pages ; 
        }else 
            pages_alloted_to_curr_stu += current_pages ; 
    }

    if(req_no_of_stu > no_of_students_present )
        return false ; 

    return true ; 
}

int Solution::books(vector<int> &A, int B) {
  if (B > A.size()) return -1;
  int low = A[0];
  int high = 0;
  //to find minimum value and sum of all pages
  for (int i = 0; i < A.size(); i++) {
    high = high + A[i];
    low = min(low, A[i]);
  }

  //binary search
  while (low <= high) {
    int mid = (low + high) >> 1;
    if (isPossible(A, mid, B)) {
        // since we are trying to minimize the answer here 
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  // just like anyother upperbound by the time low crosses high low should have bare minimum answer 
  return low;
}



int main() {
    init_code() ; 
    Solution sol ; 

    
}