//leetcode 5/7/22 : Longest Consecutive Sequence
#include<bits/stdc++.h> 
using namespace std ; 

                        //Approach 2//
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> s(arr, arr+N) ; 
        int ans = 0 , curr; 
        for(int i=0 ; i<N ; i++)
        {
            if(s.find(arr[i]-1) == s.end())
            {
                curr = 1 ; 
                while(s.find(curr + arr[i]) != s.end())
                    curr++ ; 
                    
                ans = max(ans , curr) ; 
            }
        }
        return ans;
    }
};

/*
                    //Approach 1//
    int findLongestConseqSubseq(int nums[], int N)
    {
        if(N<=1) return N ;
        
        sort(nums, nums+N);
        int maxSeq=1, count=1;
        for(int i=1; i<N; i++){
            if(nums[i]-nums[i-1] == 1) count++;
            else{
                if(nums[i] != nums[i-1]){ //if not duplicates elements 
                    maxSeq = max(maxSeq, count);
                    count=1;
                }
            }
        }
        maxSeq = max(maxSeq , count);
        return maxSeq;

    }
};  */


int main(){
    
}
/*
leetcode : https://leetcode.com/problems/longest-consecutive-sequence/
gfg : https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1#
codeStudio : https://www.codingninjas.com/codestudio/problems/longest-consecutive-sequence_759408?topList=striver-sde-sheet-problems&leftPanelTab=0
*/
