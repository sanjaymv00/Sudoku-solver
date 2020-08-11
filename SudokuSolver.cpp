#include<iostream>
#include<cmath>
using namespace std;

const int N=9;                       //works for any NxN, where N is a perfect square
const int sqrtN=sqrt(N);

void printgrid(int grid[N][N]){      //prints the NxN grid
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


//checks if the given number can be assigned to a currently empty cell
//by checking uniqueness in it's row, column, and subgrid
bool isValid(int grid[N][N],int row,int col,int num){
    for(int j=0;j<N;j++){                       //check row
        if(grid[row][j]==num){
            return false;
        }
    }
    for(int i=0;i<N;i++){                       //check column
        if(grid[i][col]==num){
            return false;
        }
    }
    int boxrow=row/sqrtN;
    int boxcol=col/sqrtN;
    for(int p=0;p<sqrtN;p++){                       //check box
        for(int q=0;q<sqrtN;q++){
            if(grid[sqrtN*boxrow+p][sqrtN*boxcol+q]==num){
                return false;
            }
        }
    }
    return true;

}


//finds next empty cell returns false if not found
bool nextEmptycell(int grid[N][N],int& row, int& col){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(grid[i][j]==0){
                row=i;
                col=j;
                break;
            }
        }
        if(j!=N){                   //if found, break out of the loop
            break;
        }
    }
    if(i!=N&&j!=N){                 //if found, return true
        return true;
    }
    return false;                   //else false
}

//takes a partially filled grid, and tries to solve it
bool solveSudoku(int grid[N][N]){
    int row,col;
    if(!nextEmptycell(grid,row,col)){        //if no empty cell left, return true
        return true;
    }
    int num;
    for(num=1;num<N+1;num++){
        if(isValid(grid,row,col,num)){       //Assign a valid number to the next Empty cell
            grid[row][col]=num;
            if(!solveSudoku(grid)){          //solve the revised grid. If unable to solve,
                grid[row][col]=0;            //reassign the cell to 0
                continue;                    //and try a different number
            }
            else{break;}
        }
    }
    if(num==N+1){                            //if no combination worked, return false
        return false;
    }
    return true;                             //otherwise true

}

int main(){
    /*int grid[N][N] = { { 0, 3, 0, 7, 0, 8, 0, 9, 0 },
                       { 4, 6, 0, 0, 0, 0, 0, 2, 7 },
                       { 2, 0, 0, 0, 0, 0, 0, 0, 3 },
                       { 0, 0, 0, 2, 0, 4, 0, 0, 0 },
                       { 0, 4, 0, 5, 1, 9, 0, 8, 0 },
                       { 0, 0, 0, 6, 0, 7, 0, 0, 0 },
                       { 5, 0, 0, 0, 0, 0, 0, 0, 9 },
                       { 9, 8, 0, 0, 0, 0, 0, 3, 6 },
                       { 0, 1, 0, 9, 0, 6, 0, 5, 0 } };
    */
    /*int grid[N][N]={{1,0,3,0},
                    {0,0,2,1},
                    {0,1,0,2},
                    {2,4,0,0}};
    */
    printgrid(grid);
    cout<<endl;
    if(solveSudoku(grid)){
        printgrid(grid);
    }
    else{"Solution doesn't exist";}


return 0;
}
