bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    for(int i=0 ; i<m ; i++)
    {
        if(mat[i][n-1] >= target )//agar kisi row ka last elemenet target se bada ho  usi row me target ko dundo   
        {
            for(int j=n-1 ; j>=0 ; j--)
            {
                if(mat[i][j] == target) 
                    return true ;
            }
        }
    }
    return false ;
}
