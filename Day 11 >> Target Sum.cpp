#define MOD 1000000007
class Solution {
    //Recursion 
    int solveRec(vector<int> &arr, int sum , int n ,vector<vector<int>> &dp)   //n from last index 
    {
        if( sum == 0 ) return 1 ; 
        if( n<0 ) return 0 ;
        
        if(dp[n][sum] != -1)
            return dp[n][sum] ;
        
        if( arr[n]<= sum )
        {
            dp[n][sum] = (solveRec(arr , sum-arr[n] , n-1 , dp) + solveRec(arr , sum , n-1 , dp) ) ; //it will give True ans
            return dp[n][sum] ; 
        }
        else{
            return dp[n][sum] = solveRec(arr , sum , n-1 ,dp) ; 
        }
    }
    
    
    //Tabulation 
    int solveTabu(vector<int> &arr, int sum , int n)
    {
        int dp[n+1][sum+1] ; 
        
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
                if(arr[i-1] <= j)
                    dp[i][j] = (dp[i-1][j-arr[i-1]] + dp[i-1][j])%MOD ; 
                else
                    dp[i][j]  = (dp[i-1][j])%MOD ;
            }
        }
        return dp[n][sum] ; 
    }
    
    
  public:
    int findTargetSumWays(vector<int>&arr ,int target) {
        int n = arr.size() ;
        //for edge case of zeroes 
        int zeros=0;
        for(int i=0;i<n;i++)
        {
           if(arr[i]==0)
           zeros++;
        }
        
        int arrSum = 0 ;
        for(int i=0 ; i<n ; i++)
            arrSum += arr[i] ; 

        if(target > arrSum || (arrSum + target)%2 == 1 || arrSum+target<0) return 0;    //some edges to be covered 

        //sum of Subset 1 
        int sum = (target + arrSum)/2 ; 

        vector<vector<int>> dp(n+1, vector<int>(sum+1 , -1) ) ; 
        int ans = solveRec( arr , sum , n-1 , dp ) ;
        
        if( ans == 0 || ans ==1)
        {
            return pow(2,zeros)*ans ; 
        }
        
        return ans ; 
        // return solveTabu( arr , sum , n ) ;
    }
};


/*
gfg (IMP) : https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1#
Leetcode : https://leetcode.com/problems/target-sum/submissions/
codeStudio : https://www.codingninjas.com/codestudio/problems/target-sum_4127362?topList=striver-sde-sheet-problems&leftPanelTab=0 
*/
