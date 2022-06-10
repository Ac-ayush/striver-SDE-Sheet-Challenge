            //Median in two sorted Array(HARD)//
//----> also see-> gfg & leetcode 

double median(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size()  , n = nums2.size() ; 
        
        vector<int> v(m+n) ; ;
        
        int i=0 , j=0 , k=0 ; 
        
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j] )
            {
                v[k++] = nums1[i++] ; 
            }
            else{
                v[k++] = nums2[j++] ;
            }
        }
        
        while( i<m){
            v[k++] = nums1[i++] ; 
        }
        
        while(j<n){
            v[k++] = nums2[j++] ; 
        }
        
        int s = v.size() ;      //ans array size m+n
        
        if( s%2 == 0 ){
            return double((v[s/2] + v[s/2-1])/2.0) ; 
        }
        
        return double(v[s/2]) ;
}
