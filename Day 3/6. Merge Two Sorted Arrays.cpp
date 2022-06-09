                  //Merge Two Sorted Array//
#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {

    int i = m-1 ; 
    int j = n-1 ; 
    int k = m+n-1 ; 
    while(k>=0)
    {
        if(arr1[i]>arr2[j])
        {
            arr1[k] = arr1[i]; 
            i-- ;  
        }
        else{
            arr1[k] = arr2[j]; 
            j-- ; 
        }
        k-- ; 
    }
    return arr1 ; 
}
