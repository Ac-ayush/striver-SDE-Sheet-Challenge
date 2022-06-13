    
                      //Is Valid Sudoku//
  bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size() ; 
        for(int row=0 ; row<n ; row++)
        {
            for(int col=0 ; col<n ; col++)
            {
                if( board[row][col] != '.')
                {
                    int val =  board[row][col] ; 
                    //check curr value will be present in same ROW/Col/Box
                    for(int k=0 ; k<9 ; k++)
                    {
                        if(k!=row && board[k][col] == val)
                            return false ; 
                        
                        if(k!=col && board[row][k] == val)
                            return false ; 
                        
                        int bRow = (3*(row/3) + k/3) , bCol =(3*(col/3)+k%3) ; 
                        if(bRow!=row && bCol!=col && board[bRow][bCol] == val)
                            return false ; 
                    }
                }
            }
        }
        return true ; 
  }
