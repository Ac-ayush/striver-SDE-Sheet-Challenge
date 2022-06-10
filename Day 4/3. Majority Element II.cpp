              //Majority Element//

#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size() ; 
    vector<int> ans ; 
    unordered_map<int,int> maj ; 
    
    for(auto i : arr)
    {
        maj[i]++ ;  
    }
    for(auto ele : maj)
    {
        if(ele.second > n/3)
            ans.push_back(ele.first) ; 
    }
    return ans ; 
}
//LINK : https://www.codingninjas.com/codestudio/problems/majority-element-ii_893027?topList=striver-sde-sheet-problems&leftPanelTab=0
