//Modular Exponentiation --> (A^B)%C.......

              //Binary Exponantiation, Iterative (LogN)//
long long modularExponentiation(long long a, long long b, long long m){
    long long ans = 1; 
    
    while( b>0 ){
        if(b&1){
            ans = (ans*a)%m ;
        }
         a = (a*a)%m ; 
        b >>= 1 ;
    }
    return ans; 
}


/*                //Binary Exponantiation, Recursion (LogN)//
int modularExponentiation(int a, int b, int m){
    if( b == 0) return 1 ; 
    
    long long res = modularExponentiation(a, b/2 , m) ;         //to reduce Time Complexity 
    if(b&1){        //if b(power) is Odd
        return (a*((res*res)%m))%m; 
    }
    else{
        return (res*res)%m ; 
    }
}
*/

/*
                //TC- O(N)--> TLE//
int modularExponentiation(int x, int n, int m) {
	long long  ans = 1 ; 
    for(int i=0 ; i<n ; i++)
    {
        ans *= x ; 
        ans %= m ; 
    }
    return ans ; 
}
*/
