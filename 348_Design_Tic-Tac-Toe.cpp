class TicTacToe {
public:
    /** Initialize your data structure here. */
    
        vector <vector <int> > board;
        int N;
    
    TicTacToe(int n) {
        
        board.resize(n);
        N=n;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)
                board[i].push_back(0);
        }
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    bool inboard(int row,int col){
        if(row>=0 && row<N && col>=0 && col<N)return true;
        else return false;
    }
    
    bool win(int stepx,int stepy,int row,int col,int player){
        
        int current_row=row+(stepx*(N-1)), current_col=col+(stepy*(N-1));
        
        while(!inboard(current_row,current_col)){
            current_row+=(stepx*(-1)); current_col+=(stepy*(-1));
        }
        
        int count=0;
        while(inboard(current_row,current_col)){
            
            if(board[current_row][current_col]==player)count++;
            else count=0;
            
            if(count==N)return true;
            current_row+=(stepx*(-1)); current_col+=(stepy*(-1));
        }
        return false;
        
    }
    
    int move(int row, int col, int player) {
        
        board[row][col]=player;
        if(win(-1,-1,row,col,player)||win(0,-1,row,col,player)||win(-1,0,row,col,player)||win(-1,1,row,col,player))
            return player;
        else 
            return 0;
        
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */