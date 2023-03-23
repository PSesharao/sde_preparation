/*

https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

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

// Recursion 

int ninjaTraining1( int day , int lastDayActivity ,  int n, vector<vector<int>> &points){
    
    if(day == n-1 ) {
        int maxActivity = 0 ; 
        for(int activity =0 ; activity <=2 ; activity++ ){
            if(activity != lastDayActivity )
                maxActivity = max(maxActivity , points[day][activity] ) ; 
        }
        return maxActivity ; 
    }

    int maxAns = 0  ; 
    for(int activity =0 ; activity <= 2 ; activity++ ){
        if(activity != lastDayActivity ){
            int curr_ans = points[day][activity] + ninjaTraining1(day+1 , activity , n , points ) ; 
            maxAns = max( maxAns , curr_ans ) ; 
        }
    }

    return maxAns ; 
}


int ninjaTraining1(int n, vector<vector<int>> &points){
    return ninjaTraining1(0 , 3 , n , points ) ; 
}



// Memoization 

int ninjaTraining2( int day , int lastDayActivity ,  int n, vector<vector<int>> &points 
    , vector<vector<int>> &dp ){
    
    if(dp[day][lastDayActivity] !=-1 )
        return dp[day][lastDayActivity] ; 

    if(day == n-1 ) {
        int maxActivity = 0 ; 
        for(int activity =0 ; activity <=2 ; activity++ ){
            if(activity != lastDayActivity )
                maxActivity = max(maxActivity , points[day][activity] ) ; 
        }
        return dp[day][lastDayActivity] = maxActivity ; 
    }

    int maxAns = 0  ; 
    for(int activity =0 ; activity <= 2 ; activity++ ){
        if(activity != lastDayActivity ){
            int curr_ans = points[day][activity] + ninjaTraining2(day+1 , activity , n , points ,dp  ) ; 
            maxAns = max( maxAns , curr_ans ) ; 
        }
    }

    return dp[day][lastDayActivity] = maxAns ; 
}


int ninjaTraining2(int n, vector<vector<int>> &points){
    vector<vector<int>> dp( n , vector<int>(4 , -1 ) ) ; 
    return ninjaTraining2(0 , 3 , n , points , dp ) ; 
}

// Tabulation

int ninjaTraining3( int n, vector<vector<int>> &points 
    , vector<vector<int>> &dp ){
    

    for(int lastDayActivity=3 ; lastDayActivity>=0 ; lastDayActivity-- ){

        int maxActivity = 0 ; 
        for(int activity =0 ; activity <=2 ; activity++ ){
            if(activity != lastDayActivity )
                maxActivity = max(maxActivity , points[n-1][activity] ) ; 
        }

        dp[n-1][lastDayActivity] = maxActivity ; 
    }


    for(int day = n-2 ; day>=0 ; day -- )
        for(int lastDayActivity=3 ; lastDayActivity>=0 ; lastDayActivity-- ){

        int maxAns = 0  ; 
        for(int activity =0 ; activity <= 2 ; activity++ ){
            if(activity != lastDayActivity ){
                int curr_ans = points[day][activity] + dp[day+1][activity] ; // ninjaTraining2(day+1 , activity , n , points ,dp  ) ; 
                maxAns = max( maxAns , curr_ans ) ; 
            }
        }

        dp[day][lastDayActivity] = maxAns ; 

    }

    return dp[0][3] ; // This is the initial call we were using to call in the recursive solution
}


int ninjaTraining3(int n, vector<vector<int>> &points){
    vector<vector<int>> dp( n , vector<int>(4 , -1 ) ) ; 
    return ninjaTraining3( n , points , dp ) ; 
}



int main() {
    init_code() ; 
    //Solution3 sol ; 
    vector<vector<int>> 
    points = { {10 , 40 , 70} , {20, 50, 80} ,  {30 ,60 ,90} } ; 
    cout <<  ninjaTraining3(3 , points ) ; 
    return 0 ; 
}