/*


https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#
https://www.codingninjas.com/codestudio/problems/job-sequencing-problem_1169460?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website

Approach:  The strategy to maximize profit should be to pick up jobs that offer higher profits. 
Hence we should sort the jobs in descending order of profit. Now say if a job has a deadline of 4 
we can perform it anytime between day 1-4, but it is preferable to perform the job on its last 
day. This leaves enough empty slots on the previous days to perform other jobs.

Time Complexity: O(N log N) + O(N*M).

O(N log N ) for sorting the jobs in decreasing order of profit. O(N*M) since we are 
iterating through all N jobs and for every job we are checking from the last deadline, 
say M deadlines in the worst case.

Space Complexity: O(M) for an array that keeps track on which day which job is performed 
if M is the maximum deadline available.

Follow up : to solve this question in O(NlogN)

Refer :
https://www.spoj.com/problems/CLFLARR/ 

to follow the same .

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
bool comp(vector<int> &v1 , vector<int> &v2 ){
    return v1[1] > v2[1] ; 
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size() ; 
    int max_profit = 0 ; 
    if(n == 0 )
        return max_profit ; 
    sort(jobs.begin() , jobs.end()  , comp ) ; 

    int max_deadline = 0 ; 
    for(int i=0 ; i<n ; i++){
        max_deadline = max(jobs[i][0] , max_deadline ) ; 
    }

    vector<int> deadline_allot(max_deadline+1 , -1 ) ;

    for(int i=0 ; i<n ; i++){
        int deadline = jobs[i][0] ;
        int profit =  jobs[i][1] ;

        bool is_alloted = false ; 
        for(int j=deadline ; j>=1 ; j-- ){
            if(deadline_allot[j] ==-1 )
            {
                deadline_allot[j] = i ; 
                is_alloted = true ; 
                break ; 
            }
        }
        if(is_alloted )
            max_profit += profit ; 
    }

    return max_profit ; 

}


int main() {
    init_code() ; 
    Solution sol ; 

    
}