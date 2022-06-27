//Av34 >> Palindrome Partitioning Recursive(MCM)
#include<bits/stdc++.h>
using namespace std ; 

/*
            ***MCM steps***
1. find i,j
2. find right Base Condition 
3. find correct K loop scheme 
4. calculate Ans from temp answers 
*/

class Solution{
private:    
    //check Palindrome 
    bool isPalindrome(string &s, int i, int j)
    {
        while(i<=j)
        {
            if(s[i] != s[j])
                return false ;   
            i++;
            j--;
        }
        return true;
    }

    //Recursion : 
    int solveRec(string &s, int i, int j)
    {   //2. Base Condition 
        if(i>=j)                            //when string set is empty or sized 1
            return 0; 
            
        if(isPalindrome(s, i, j) == true)   //already palindrome NO need of partition 
            return 0 ; 
        
        int ans = INT_MAX ;     //min partition 
        //3. find correct K looop scheme  
        for(int k=i; k<=j-1; k++)
        {
            int tempAns = 1 + solveRec(s, i, k) + solveRec(s, k+1, j) ;     
            ans = min(ans , tempAns) ;
        }
        return ans ; 
    }
    
    //Memoisation :
    int solveMemo(string &s, int i, int j, vector<vector<int>> &dp)
    {   //2. Base Condition 
        if(i>=j)                            //when string set is empty or sized 1
            return 0; 
            
        if(isPalindrome(s, i, j) == true)   //already palindrome NO need of partition 
            return 0 ; 
        
        if(dp[i][j] != -1)
            return dp[i][j] ; 
        
        int ans = INT_MAX ;     //min partition 
        //3. find correct K looop scheme  
        for(int k=i; k<=j-1; k++)
        {
            int tempAns = 1 + solveMemo(s, i, k, dp) + solveMemo(s, k+1, j, dp) ;     
            ans = min(ans , tempAns) ;
        }
        return dp[i][j] = ans ; 
    }
public:
    int palindromicPartition(string str)
    {
        int n = str.length() ;
        // return solveRec( str, 0, str.length()-1 );  //1. find i,j
        
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1)) ; 
        return solveMemo(str , 0, n-1, dp) ; 
    }
};


int main(){
    
}


/*
gfg : https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1/#
leetcode : https://leetcode.com/problems/palindrome-partitioning-ii/
codestudio : https://leetcode.com/problems/palindrome-partitioning-ii/discuss/2152294/C%2B%2B-oror-DP-(Aditya-Verma)oror-Memoization-ororEasy
*/
