/*

https://www.codingninjas.com/codestudio/problems/1062658?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website
https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Initial Thought Process:-
Say if you have two meetings, one which gets over early and another which gets over late. 
Which one should we choose?  If our meeting lasts longer the room stays occupied and we 
lose our time. On the other hand, if we choose a meeting that finishes early we can accommodate 
more meetings. Hence we should choose meetings that end early and utilize the remaining time for 
more meetings.

the first meeting can always be performed. 

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

class Meeting{
public : 
    int start_time ; 
    int end_time ; 
    int meeting_number ;

Meeting(int start_time , int end_time ,  int meeting_number ) {
    this->start_time = start_time ;
    this->end_time = end_time ; 
    this->meeting_number = meeting_number ; 
}

};


bool comp(Meeting &m1 , Meeting &m2) {
    if(m1.end_time == m2.end_time)
        return m1.meeting_number < m2.meeting_number ; 
    return m1.end_time < m2.end_time ; 
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    vector<int> res ; 
    int n = start.size() ; 
    if(n == 0 )
        return res ; 
    vector<Meeting> meeting(n) ; 
    for(int i=0 ; i<n ; i++ ){
        Meeting m = Meeting(start[i] , end[i] , i+1 ) ; 
        meeting[i] = m ; 
    }

    sort(meeting.begin() , meeting.end() , comp ) ; 

    // first meet always happens 
    int last_end_time = meeting[0].end_time ; 
    res.emplace_back( meeting[0].meeting_number ) ;  
    for(int i=1 ; i<n ; i++){
        int current_starting_point = meeting[i].start_time ; 
        if(current_starting_point > last_end_time ){
            res.emplace_back(meeting[i].meeting_number ) ;
            last_end_time =  meeting[i].end_time ; 
        }
    }

    return res ; 
}

int main() {
    init_code() ; 
    Solution sol ; 

    
}