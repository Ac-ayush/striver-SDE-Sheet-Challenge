//Av07 >> Subset Sum Problem    (Knapsack Varient)
#include<bits/stdc++.h> 
using namespace std ; 

/*
Approach--> last index se start kerte he 
            //agar element Sum se chota he 
            --> to hamre pass 2 choices he
                1. curr element ko subset me add krna he.
                2. curr element ko subset me add Nhi krna he.
                (inn dono choices se jiska ans true aayega use hi true3 )
            //agar element Sum se bada he 
            --> to curr element ko subset me add nhi karege aout next element ke liye process kro
*/

class Solution{   
    //Recursion 
    bool solveRec(vector<int> &arr, int sum , int n )   //n from last index 
    {
        if( sum == 0 ) return true ; 
        if( n<0 ) return false ; 
        
        if( arr[n]<= sum )
        {
            bool ans = (solveRec(arr , sum-arr[n] , n-1) || solveRec(arr , sum , n-1) ) ; //it will give True ans
            return ans ; 
        }
        else{
            return solveRec(arr , sum , n-1) ; 
        }
    }
    
    //Memoisation
    int solveMemo(vector<int> &arr, int sum , int n  , vector<vector<int>> &dp)   //n from last index 
    {
        if( sum == 0 ) return 1 ; 
        if( n<0 ) return 0 ; 
        
        if( dp[n][sum] != -1)
            return dp[n][sum] ; 
        
        if( arr[n]<= sum )
        {
            dp[n][sum] = ( solveMemo(arr , sum-arr[n] , n-1 , dp) || solveMemo(arr , sum , n-1 , dp) ) ;
            return dp[n][sum] ; 
        }
        else{
            dp[n][sum] = solveMemo(arr , sum , n-1 , dp) ; 
            return dp[n][sum] ; 
        }
    }
    
    //Tabulation 
    int solveTabu(vector<int>arr, int sum , int n)
    {
        int dp[n+1][sum+1] ; 
        
        //Initialisation of 1st ROW & COL 
        for(int i=0 ; i<=n ; i++)   
            for(int j=0 ; j<= sum ; j++)
            {
                if(i==0)
                    dp[i][j] = false ; 
                if(j==0)
                    dp[i][j] = true ; 
            }
        
        for(int i=1 ; i<=n ; i++)       //arr size 
        {
            for(int j=1 ; j<=sum ; j++) //sum 
            {
                if(arr[i-1] <= j)
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j] ; 
                else
                    dp[i][j]  = dp[i-1][j] ;
            }
        }
        return dp[n][sum] ; 
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // return solveRec( arr , sum , arr.size()-1 ) ; 
        
        // vector<vector<int>> dp(arr.size()+1, vector<int>(sum+1 , -1) ) ; 
        // return solveMemo( arr , sum , arr.size()-1 , dp ) ; 
        
        return solveTabu( arr , sum , arr.size() ) ; 
    }
    
int main(){
    
}


/*
gfg : https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/#
codeStudio : https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?topList=striver-sde-sheet-problems&leftPanelTab=1
*/
