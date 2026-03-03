/*


https://practice.geeksforgeeks.org/problems/word-ladder-ii/1

https://leetcode.com/problems/word-ladder-ii/

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



class Solution1 {
public:
    vector<vector<string>> findSequences(string beginWord, 
        string endWord, vector<string>& wordList) {

        queue<vector<string>> Q ; 
        unordered_set<string> visited ; 

        for(auto str : wordList )
            visited.insert(str) ; 

        Q.push({beginWord}) ; 
        visited.erase(beginWord) ;

        vector<vector<string>> ans ;          
        int level =1 ; 

        bool foundSeq = false ;  

        while(! Q.empty()){

            int levelSize = Q.size() ; 

            vector<string> transformed_visited ; 
			
			// we are dealing level wise 
            while(levelSize -- ){

                vector<string> seq = Q.front() ; 
                Q.pop() ; 
                string curr_word = seq.back() ; 
				
				// If the desired seq is found , we will have to find all other sequences 
				// ending with endWord at the present level only otherwise the sequence length will increase 
				// and we dont want such answers.
				
                if(curr_word == endWord ){

                    foundSeq = true ; 
                    ans.push_back(seq) ; 

                }else{

                    for( int i=0 ; i<curr_word.size() ; i++ ){

                        string transformed_word = curr_word ; 

                        for(char ch='a' ; ch <='z' ; ch++){
                            transformed_word[i] = ch ; 

                            if(visited.count(transformed_word) > 0 ){
                                
                                vector<string> trans_seq = seq ; 
                                trans_seq.push_back(transformed_word) ; 
                                Q.push(trans_seq) ; 
								// we are storing the current level trasformed words at one place 
								// we should only erase them after completing the level 
                                transformed_visited.push_back(transformed_word) ;

                            }
                        }
                    }                    

                }

            }


            if(foundSeq)
                return ans ; 
			
			// erasing last level visted words at once after the completion of 
			// the level
			
            for(auto word : transformed_visited ){
                visited.erase(word) ;
            }
			
			level ++ ; 

        }

        return ans ; 

    }
};


bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}



int main() {

    init_code() ; 
    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";
    Solution1 obj;
    vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
    
    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else
    {
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}