#include<bits/stdc++.h>
//Que : Find Minimum Number Of Coins

int findMinimumCoins(int amount) 
{
    vector<int> coins{1,2,5,10,20,50,100,500,1000} ;     
    int i=8 ; 
    int cnt = 0 ; 
    
    while( amount != 0 )
    {
        if(coins[i]>amount){
            i-- ;
        }
        else{
            amount -= coins[i] ; 
            cnt++ ; 
        }
    }
    return cnt ; 
}#include<bits/stdc++.h>
//Que : Find Minimum Number Of Coins

int findMinimumCoins(int amount) 
{
    vector<int> coins{1,2,5,10,20,50,100,500,1000} ;     
    int i=8 ; 
    int cnt = 0 ; 
    
    while( amount != 0 )
    {
        if(coins[i]>amount){
            i-- ;
        }
        else{
            amount -= coins[i] ; 
            cnt++ ; 
        }
    }
    return cnt ; 
}
