              //Remove Duplicates from Sorted Array//

int removeDuplicates(vector<int> &arr, int n) {
    
    int j=0 ;     //will store next unique elements at this index 
    
    for(int i=0 ; i<n-1; i++){
        if( arr[i] != arr[i+1] ){
            arr[j++] = arr[i] ; 
        }
    }
        
    //handle last element 
    arr[j++] = arr[n-1] ; 
    return j ;     // j is size of modified array 
}
