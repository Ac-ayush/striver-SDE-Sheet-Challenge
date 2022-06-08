#include <bits/stdc++.h> 

void setZeros(vector<vector<int>> &matrix)
{   int n = matrix.size() ; 
    int m = matrix[0].size() ; 
    
 //create Dummy arrays for storing data of zeros 
     vector<int> row(n, -1) ; 
     vector<int> col(m, -1) ; 
 
    for(int i= 0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] == 0){    //if 0 found at any index in matrix 
                row[i] = 0 ;         //mark 0 for that row of Dummy array 
                col[j] = 0 ;         //mark 0 for that Col of dummy Array
            }
        }
    }
 
 //now check if Row or Col of DummyArray is zero , put 0 in that complete Row && Col of matrix 
 
 for(int i=0 ; i<n ; i++){
     for(int j=0 ; j<m ; j++){
         if(row[i]==0 || col[j] == 0)
             matrix[i][j] = 0 ; 
     }
 }
}
