    int getPivotIndex( int arr[] , int s , int e)
    {
        int mid = s +(e-s)/2 ; 
        while(s<e)
        {
            if(arr[mid] >= arr[0]){  //means right part me pivot search kro
                s = mid+1 ; 
            }
            else{
                e = mid ; 
            }
            mid = s +(e-s)/2 ; 
        }
        return s ; 
    }
    
    
    int binarySearch( int arr[] , int s , int e ,int key)
    {
        int mid = s + (e-s)/2 ; 
        while(s<=e)
        {
            if(arr[mid] == key){
                return mid ; 
            }
            if(arr[mid] > key){
                e = mid-1 ; 
            }
            else{
                s = mid+1 ; 
            }
            mid = s + (e-s)/2 ; 
        }
        
        return -1 ; 
    }
    
int search(int* arr, int n, int key) {
    int s = 0 ,  e = n-1 ;     
    int pivot = getPivotIndex(arr , s ,e) ;

    if( arr[pivot] <= key && key <= arr[e]){
        return binarySearch(arr, pivot, e, key);
    }
    else{
        return binarySearch(arr, s, pivot-1, key);
    }
}
