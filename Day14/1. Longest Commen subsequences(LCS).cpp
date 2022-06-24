//Av20 >> longest common subsequence (LCS)
#include<bits/stdc+++.h> 
using namespace std ; 

//longest common subsequence
class Solution
{
    private: 
    //Recirsion : last index se process krege 
    int solveRec(string &x , string &y , int n, int m)
    {
        if(n==0 || m==0)    //agar kisi ek string ka size bhi 0 he to subsequence 0 banege  
            return 0 ; 
            
        if(x[n-1] == y[m-1])    //when both element are same 
            return 1 + solveRec( x, y , n-1 , m-1) ;     //+1 for curr elements 
        else{
            int ans = max( solveRec( x, y , n , m-1) , solveRec( x, y , n-1 , m) ) ; 
            return ans ; 
        }
    }
    
    
    //Memoisation : pass by reference for avoid TLE
    int solveMemo(string &x , string &y , int n, int m ,vector<vector<int>> &dp)
    {
        if(n==0 || m==0)    //agar kisi ek string ka size bhi 0 he to subsequence 0 banege  
            return 0 ; 
            
        if(dp[n][m] != -1)
            return dp[n][m] ; 
        
        if(x[n-1] == y[m-1]){    //when both element are same 
            dp[n][m] = 1 + solveMemo( x, y , n-1 , m-1 ,dp) ;     //+1 for curr elements 
            return dp[n][m] ; 
        }
        else{
            dp[n][m] = max( solveMemo( x, y , n , m-1 , dp) , solveMemo( x, y , n-1 , m ,dp) ) ; 
            return dp[n][m] ; 
        }
    }
    
    //Top-down --> Tabulation 
    int solveTabu(string &x , string &y , int n, int m)
    {
        
        int dp[n+1][m+1] ; 
        
        //initialization 
        for(int i=0 ; i<=n ; i++)
        for(int j=0 ; j<=m ; j++)
            if(i==0 || j==0)
                dp[i][j] = 0 ; 
                
        for(int i=1 ;i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
        {
            if(x[i-1] == y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1] ; 
            }
            else{
                dp[i][j] = max(dp[i][j-1] , dp[i-1][j] ) ; 
            }
        }
        return dp[n][m] ; 
    }
    
    
    
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        // return solveRec( s1, s2, x ,y) ; 
        
        // vector<vector<int>> dp(x+1 , vector<int>(y+1 , -1)) ; 
        // return solveMemo( s1, s2, x ,y , dp) ; 
        
        return solveTabu( s1, s2, x, y) ; 
    }
};


int main(){
    
}

/*
gfg : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1#
leetcode : https://leetcode.com/problems/longest-common-subsequence/submissions/
codeStudio : https://www.codingninjas.com/codestudio/problems/longest-common-subsequence_624879?topList=striver-sde-sheet-problems&leftPanelTab=1
*/
