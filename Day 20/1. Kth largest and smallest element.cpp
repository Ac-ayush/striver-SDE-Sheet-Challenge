#include<bits/stdc++.h>
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
    sort(arr.begin() , arr.end()) ; 
    return {arr[k-1] , arr[n-k]} ; 
}
