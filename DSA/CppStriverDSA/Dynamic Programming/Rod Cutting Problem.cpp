/*

https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

*/


// Recursion 
class Solution1{
  public:

    int cutRod( int ind , int price[], int n , int len ) {

        if(ind == n ){
            if(len == 0 )
                return 0 ;

            return -INF ;  
        }

        int take = -INF ; 
        if( len - (ind+1) >=0 )
            take = price[ind] + cutRod(ind , price , n , len - (ind+1) ) ; 

        int notTake = cutRod(ind+1 , price , n , len ) ; 

        return max(take , notTake ) ; 

    }


    int cutRod(int price[], int n) {
       return cutRod(0 , price , n , n ) ; 
    }


};



// Memoization 
class Solution2{
  public:

    int cutRod( int ind , int price[], int n , int len , vector<vector<int>> &dp) {

        if(dp[ind][len] != -1 )
            return dp[ind][len] ;

        if(ind == n ){
            if(len == 0 )
                return dp[ind][len] = 0 ;

            return dp[ind][len] = -INF ;  
        }

        int take = -INF ; 
        if( len - (ind+1) >=0 )
            take = price[ind] + cutRod(ind , price , n , len - (ind+1) , dp ) ; 

        int notTake = cutRod(ind+1 , price , n , len , dp ) ; 

        return dp[ind][len] = max(take , notTake ) ; 

    }


    int cutRod(int price[], int n) {

        int len = n ; 
        vector<vector<int>> dp( n+1 , vector<int>( len+1 , -1 ) ) ; 
        return cutRod(0 , price , n , len , dp ) ; 
    }


};


// Tabulation
class Solution3{
  public:

    int cutRod(  int price[], int n , int L , vector<vector<int>> &dp ) {


        for(int len=0 ; len<=L ; len++ ){

            if(len == 0 )
                 dp[n][len] = 0 ;
            else   
                 dp[n][len] = -INF ;  
        }


        for(int ind=n-1 ; ind>=0 ; ind-- )
            for(int len=0 ; len<=L ; len++ ){

                int take = -INF ; 
                if( len - (ind+1) >=0 )
                    take = price[ind] +  dp[ind][len - (ind+1)] ; // cutRod(ind , price , n , len - (ind+1) , dp ) ; 

                int notTake =  dp[ind+1][len] ;// cutRod(ind+1 , price , n , len , dp  ) ; 

                dp[ind][len] = max(take , notTake ) ;   

            }
        return dp[0][L] ; 
    }


    int cutRod(int price[], int n) {

        int len = n ; 
        vector<vector<int>> dp( n+1 , vector<int>( len+1 , -1 ) ) ; 
        return cutRod( price , n , len , dp ) ; 
    }


};


int main() {
    init_code() ; 
    Solution3 sol ; 
    int price[] = {3, 5, 8, 9, 10, 17, 17, 20} ;  
    cout << sol.cutRod( price , 8 ) ; 
    return 0 ; 
}