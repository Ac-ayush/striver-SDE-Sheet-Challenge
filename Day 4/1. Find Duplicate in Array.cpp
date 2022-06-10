                  //duplicate in array (Numbers--> 1 - N-1)

#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
    unordered_map<int,int> dup;    //this will store no of occuring corresponding to digit
    for(auto i : arr)
    {
        dup[i]++ ; 
        if(dup[i] == 2) 
            return i ; 
    }
}
