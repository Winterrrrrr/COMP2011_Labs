#include <stdlib.h>
#include <iostream>
using namespace std;
const int MAX_HEIGHT=6;
const int MAX_WIDTH=6;
int ans = 0;


void find(int board[][MAX_HEIGHT],int xx,int yy,int x, int y)
{
    if(xx==x+1)    
    {
        ans++;
        return;
    }
    if(board[xx][yy]==1)     
    {
        if(yy==y) 
            find(board,xx+1,1,x,y);
        else
            find(board,xx,yy+1,x,y);
    }
    if(board[xx][yy]==0)    
    {
        if(yy<y && board[xx][yy+1]==0)             
        {
            board[xx][yy]=1;
            board[xx][yy+1]=1;
            if(yy+1==y) 
                find(board,xx+1,1,x,y);
            else
                find(board,xx,yy+2,x,y);
            board[xx][yy+1]=0;
            board[xx][yy]=0;
        }
        if(xx<x && board[xx+1][yy]==0)                   
        {
            board[xx+1][yy]=1;
            board[xx][yy]=1;
            
            if(yy==y) 
                find(board,xx+1,1,x,y);
            else
                find(board,xx,yy+1,x,y);
            board[xx+1][yy]=0;
            board[xx][yy]=0;
        }
    }
}

bool findUncoveredGrid(int board[][MAX_WIDTH], int height, int width, int& r_id, int& c_id){
    // to be completed
    //

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            if(board[i][j]==0){
                r_id=i;
                c_id=j;
                // cout << "Something " << r_id << " " << c_id << endl;
                return true;
            }
        }
    }
    return false; 
}




int numberLayout(int board[][MAX_WIDTH], int height, int width){
    int result=0;
   
    
    //printLayout(board, height, width, result);
    /*if (!findUncoveredGrid(board, height, width, r_id, c_id)) {
        return 1;
    }*/
    /*if (!findUncoveredGrid(board, height, width, r_id, c_id)) {
        return 1;
    } else {

        if (r_id + 1 < height) {
            board[r_id][c_id] = 1;
            board[r_id + 1][c_id] = 1;
            result += numberLayout(board, height, width);
            board[r_id][c_id] = 0;
            board[r_id + 1][c_id] = 0;
           
        }
        if (c_id + 1 < width) {
            board[r_id][c_id] = 1;
            board[r_id][c_id + 1] = 1;
            result += numberLayout(board, height, width);
            board[r_id][c_id] = 0;
            board[r_id][c_id + 1] = 0;
           
        }
    }*/
    find(board,1,1,width,height);
    result = ans;
    return result;
}


int main(){
    int width, height;
    int board[10][6] = { 0 };

    // enter the height (number of rows)
    do{
    cout << "Please enter the height [1, " << MAX_HEIGHT << "]:" << endl;
    cin >> height;
    }
    while((height < 1)||(height > MAX_HEIGHT));

    // enter the width (number of columns)
    do{
    cout << "Please enter the width [1, " << MAX_WIDTH << "]:" << endl;
    cin >> width;
    }while((width < 1)||(width > MAX_WIDTH));

    cout << "The number of layouts is " << numberLayout(board, height, width) << "." << endl;

    return 0;
}