        //Majority Elements//

#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    unordered_map<int,int> maj ;     //it will store No. of Occcuring of digit
    for(int i=0 ; i<n ; i++)
    {
        maj[arr[i]]++ ; 
        if( maj[arr[i]] > n/2 ) 
            return arr[i] ; 
    }
    return -1 ; 
}

//link : https://www.codingninjas.com/codestudio/problem-lists/striver-sde-sheet-problems?filter_tag_list=%7B%22PracticeTopic%22:%5B%22Arrays%22%5D%7D&page=1#progressWrapper
