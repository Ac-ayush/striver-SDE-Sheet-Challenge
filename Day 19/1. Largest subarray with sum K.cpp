#include <bits/stdc++.h> 

int LongestSubsetWithZeroSum(vector < int > arr) {
    int N = arr.size() ; 
    unordered_map<long , int> m ;       //(sum , index)
    int ans = 0 ;
    int sum = 0 ; 
    m[0] = -1;   
    for(int i=0 ; i<N ; i++)
    {
        sum += arr[i] ; 
        if(m.find(sum) != m.end()){         //agar map me (sum-k) ki value already he means uske baad wale index se curr index tak ka sum K ke equal hoga 
            ans = max(ans , i-m[sum]) ; 
        }
        if(m.find(sum)==m.end()){   //agar sum phle nhi aaya to entry ana do 
            m[sum] = i ; 
        }
    }
    return ans ;

}
