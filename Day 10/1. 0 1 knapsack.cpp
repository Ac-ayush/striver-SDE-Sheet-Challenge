#include<bits/stdc++.h> 
 //Memoisation 
    int solveMemo(int W, vector<int> &wt, vector<int> &val, int n ,vector<vector<int>> &dp )
    {
        if(n<0 || W==0)return 0 ;  //agar bag khali he ya item hi nhi he to profit 0 hoga 
        
        if(dp[n][W] != -1)
            return dp[n][W]; 
        
        if( wt[n]<=W ){ //either I can put curr item into Bag or not (jisse bhi max result aa jaye )
            int putItem = val[n] + solveMemo( W-wt[n] , wt , val , n-1 ,dp);  //curr Item ko bag me dalne par 
            int notPut = solveMemo( W , wt , val , n-1, dp );
            
            return dp[n][W] = max(putItem , notPut) ; 
        }
        else if(wt[n] > W){
            return dp[n][W] = solveMemo( W , wt , val , n-1 ,dp ) ;
        }
    }

int maxProfit(vector<int> &val, vector<int> &wt, int n, int W)
{
    vector<vector<int>> dp(n+1 , vector<int>(W+1,-1) ) ; 
    return solveMemo( W, wt, val, n-1 , dp) ; 
}


/*
codeStudio : https://www.codingninjas.com/codestudio/problems/0-1-knapsack_1072980?topList=striver-sde-sheet-problems&leftPanelTab=1
recourses : Aditya Verma yt
*/
