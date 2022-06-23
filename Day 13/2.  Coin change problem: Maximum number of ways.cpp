//Av15 >> Coin change problem: Maximum number of ways   (unbounded knapsack)
#include<bits/stdc++.h> 
using namespace std ; 

/*
This problem is Sum of Two problem concepts :  
        --> Count number of subsets for given Sum 
        --> unbounded knapsack 
*/

class Solution {
    long long int solveMemo(int coins[], int sum, int n ,vector<vector<long long int>> &dp)
    {
        if( sum == 0 ) return 1 ; 
        if( n<0 ) return 0 ;
        
        if(dp[n][sum] != -1)
            return dp[n][sum] ;
        
        if( coins[n]<= sum )
        {
            dp[n][sum] = (solveMemo(coins , sum-coins[n] , n , dp) + solveMemo(coins , sum , n-1 , dp) ) ; //it will give True ans
            return dp[n][sum] ; 
        }
        else{
            return dp[n][sum] = solveMemo(coins , sum , n-1 ,dp) ; 
        }
    }
    
    
    //Tabulation 
    //Tabulation 
    long long int solveTabu(int coins[], int sum , int n)
    {
        long long int dp[n+1][sum+1] ; 
        
        //Initialisation of 1st ROW & COL 
        for(int i=0 ; i<=n ; i++)   
            for(int j=0 ; j<= sum ; j++)    //TO avoide GFG element 0 wala case using j=0  
            {
                if(i==0)
                    dp[i][j] = false ; 
                if(j==0)
                    dp[i][j] = true ; 
            }
        
        for(int i=1 ; i<=n ; i++)       //arr size 
        {
            for(int j=0 ; j<=sum ; j++) //sum 
            {
                if(coins[i-1] <= j)
                    dp[i][j] = ( dp[i][j-coins[i-1]] + dp[i-1][j]) ; 
                else
                    dp[i][j]  = (dp[i-1][j]) ;
            }
        }
        return dp[n][sum] ; 
    }
    
  public:
    long long int count(int S[], int m, int n) {
        
        // vector<vector<long long int>>dp(m+1,vector<long long int>(n+1,-1)) ; 
        // return solveMemo( S , n, m-1 ,dp) ; //m is index , and n is SUM here 
        
        return solveTabu(S , n , m) ; 
    }
};


int main(){
    
}

/*
gfg : https://practice.geeksforgeeks.org/problems/coin-change2448/1#
CodeStudio : https://www.codingninjas.com/codestudio/problems/ways-to-make-coin-change_630471?topList=striver-sde-sheet-problems&leftPanelTab=0
leetcode : https://leetcode.com/problems/coin-change-2/submissions/
*/
