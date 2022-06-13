                    //PASCAL's TRIANGLE //

vector<vector<int>> printPascal(int numRows) {
        vector<vector<int>> r(numRows) ; 
    
        for(int i=0 ; i<numRows ; i++)
        {
            r[i].resize(i+1) ;        //har ROW me no of elements is equal to row number(last index (i,i)
            r[i][0] = r[i][i] = 1 ;   //har row ka first aur last index 1 he 

            for(int j=1 ; j<i ; j++){        //j<i bcz in each Row no. of elements equal to Row number && j=1 bcz 1st element hamesha '1' hoga 
                 r[i][j] = r[i-1][j-1] + r[i-1][j] ; 
            }
        }
        return r ;
    }
};
