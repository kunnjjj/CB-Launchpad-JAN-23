#include<iostream>
using namespace std;


bool isSafeToPlaceQueen(int row,int col,int board[10][10],int N)
{
    // true: i can place queen
    // false: i cannot place queen at (row,col)
    
    // vertical
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }

    // left diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1) return false;
    }

    // right diagonal
    for(int i=row-1,j=col+1;i>=0 && j<N;i--,j++)
    {
        if(board[i][j]==1) return false;
    }
    return true;
}

void printBoard(int board[10][10],int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==1)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<"- ";
            }
        }
        cout<<endl;
    }
    cout<<"----------------"<<endl;
}

int cnt=0;
bool nQueen(int board[10][10],int row,int N)
{
    // can i place queen on the given row and all further row
    // true  : i was able to place queens row....(N-1) 
    // false : i was not able to place queens
    if(row==N)
    {
        cnt++;
        printBoard(board,N);
        return false;
    }

    for(int col=0;col<N;col++)
    {
        if(isSafeToPlaceQueen(row,col,board,N))
        {
            board[row][col]=1;
            bool res=nQueen(board,row+1,N);
            if(res==true)
            {
                return true;
            }
            board[row][col]=0; // BACKTRACK
        }   
    }

    return false;
}

int main()
{

    cout<<"edited"<<endl;
    int board[10][10]={0};
    int N; cin>>N;
    nQueen(board,0,N);
    cout<<cnt<<endl;

    return 0;
}