//Av14 >> ROD CUTTING PROBLEM (Unbounded Knapsack)
#include<bits/stdc++.h> 
using namespace std ; 

class Solution{
    //recursion 
    int solveRec(int price[] , int len[] , int rod , int n )    //rod in ROD Length , and n is index
    {
        if(n==0 || rod==0)
            return 0; 
            
        if(len[n-1] <= rod){
            int ans = max(price[n-1]+solveRec(price , len , rod-len[n-1] , n) , 
                            solveRec(price , len , rod , n-1)) ; 
            return ans ; 
        }
        else{
            return solveRec(price , len , rod , n-1) ; 
        }
    }
    
    //Memoisation 
    int solveMemo(int price[] , int len[] , int rod , int n , vector<vector<int>> &dp)    //rod in ROD Length , and n is index
    {
        if(n==0 || rod==0)
            return 0; 
        
        if(dp[n][rod] != -1)
            return dp[n][rod] ; 
         
        if(len[n-1] <= rod){
            dp[n][rod] = max(price[n-1]+solveMemo(price , len , rod-len[n-1] , n ,dp) , 
                            solveMemo(price , len , rod , n-1 ,dp)) ; 
            return dp[n][rod] ; 
        }
        else{
            return dp[n][rod] = solveMemo(price , len , rod , n-1 ,dp) ; 
        }
    }
    
    
    //Tabulation 
    int solveTabu(int price[] , int len[] , int rod , int n)
    {
        int dp[n+1][rod+1] ; 
        //initialisation 
        for(int i=0 ; i<=n ; i++)
            for(int j=0 ; j<=rod ; j++)
            {
                if(i==0 || j==0)
                    dp[i][j] = 0 ; 
            }
        
        for(int i=1 ; i<=n ; ++i)
            for(int j=1 ; j<=rod ; ++j)
            {
                if(len[i-1] <= j){
                    dp[i][j] = max( price[i-1]+ dp[i][j-len[i-1]] , dp[i-1][j] ) ;
                }
                else{
                    dp[i][j] = dp[i-1][j]  ; 
                }
            }
            
        return dp[n][rod] ; 
        
    }
    
    
  public:
    int cutRod(int price[], int n) {
        int length[n] ;    //length array 
        
        for(int i=0 ; i<n ; i++)
            length[i] = i+1 ;
        
        // return solveRec( price , length , n , n ) ; //n = Rod Length , n = index 
        
        // vector<vector<int>> dp(n+1 , vector<int>(n+1,-1)) ; 
        // return solveMemo( price , length , n , n , dp) ; 
        
        return solveTabu( price , length , n , n) ;
    }
};

int main(){
    
}

/*
gfg : https://practice.geeksforgeeks.org/problems/rod-cutting0840/1/
COdeStudio : https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?topList=striver-sde-sheet-problems&leftPanelTab=1
*/
