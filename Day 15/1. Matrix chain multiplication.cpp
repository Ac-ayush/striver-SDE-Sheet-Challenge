//Av33 >> Matrix Chain Multiplication (MCM)
#include<bits/stdc++.h> 
using namespace std ; 

/*     
            **MCM - Format**
1. find i,j
2. find right Base condition 
3. find k Loop scheme 
4. calculate ans from TempAns 
*/

class Solution{
    //SolveMCM recursion 
    int MCM(int arr[], int i, int j)
    {
        //2. Base Case
        if( i>=j)
            return 0; 
        
        int ans = INT_MAX ; 
        //3. find K loop scheme 
        for(int k=i ; k<=j-1 ; k++)
        {
            int tempAns = MCM(arr,i,k) + MCM(arr,k+1,j) + arr[i-1]*arr[k]*arr[j] ; 
            ans = min(ans , tempAns) ;      //4. ans from tempAns's
        }  
        return ans ;
    }
    
    //Memoisation 
    int MCM(int arr[], int i, int j, vector<vector<int>> &dp)
    {
        //2. Base Case
        if( i>=j)
            return 0; 
            
        if( dp[i][j] != -1)
            return dp[i][j]; 
        
        int ans = INT_MAX ; 
        //3. find K loop scheme 
        for(int k=i ; k<=j-1 ; k++)
        {
            int tempAns = MCM(arr,i,k,dp) + MCM(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j] ; 
            ans = min(ans , tempAns) ; 
        }  
        return dp[i][j] = ans ;
    }
    
public:
    int matrixMultiplication(int N, int arr[])
    {
        // return MCM( arr , 1 , N-1) ; 
        vector<vector<int>> dp(N+1 , vector<int>(N+1 , -1)) ; 
        return MCM( arr , 1 , N-1,dp) ;    //1. i=1 , j=n-1...
    }
};


int main(){
    
}


/*
gfg : https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
codeStudio : https://www.codingninjas.com/codestudio/problems/matrix-chain-multiplication_975344?topList=striver-sde-sheet-problems&leftPanelTab=1
*/
