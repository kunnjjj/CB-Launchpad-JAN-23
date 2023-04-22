#include<iostream>
using namespace std;

int board[1000][1000]={0};
char grid[1000][1000];

void printBoard(int board[1000][1000],int N,int M)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            cout<<board[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<"-----------------------"<<endl;
}

bool is_safe(int r,int c,int N,int M,char grid[1000][1000])
{
    return ((0<=r && r<N) && (0<=c && c<M) && grid[r][c]!='X');
    // if((0<=r && r<N) && (0<=c && c<M) && grid[r][c]!='X')
    // {
    //     return true;
    // }
    // else return false;
}

bool ratInMaze(int row,int col,int N,int M,int board[1000][1000],char grid[1000][1000])
{
    // true: yadi i can reach to cell (N-1,M-1) from (row,col)

    // cout<<"hello"<<endl;
    // return true;
    if(row==N-1 && col==M-1)
    {
        board[row][col]=1;
        printBoard(board,N,M);
        return false;
    }

    board[row][col]=1;

    // MOVE RIGHT
    if(is_safe(row,col+1,N,M,grid))
    {
        bool res=ratInMaze(row,col+1,N,M,board,grid);
        if(res==true)
        {
            return true;
        }
    }

    // MOVE DOWN
    if(is_safe(row+1,col,N,M,grid))
    {
        bool res=ratInMaze(row+1,col,N,M,board,grid);
        if(res==true)
        {
            return true;
        }
    }

    board[row][col]=0; // BACKTRACK
    return false;
}



int main()
{
    
    int N,M; cin>>N>>M;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++) cin>>grid[i][j];
    }
    ratInMaze(0,0,N,M,board,grid);
    return 0;
}