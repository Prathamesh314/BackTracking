#include<bits/stdc++.h>
using namespace std;

// This function checks whether the position is safe for queen or not
bool isSafe(int** arr,int row,int col,int n){

    // Here we check vertically
    for(int i=0;i<row;i++){
        if(arr[i][col] == 1){
            return false; // If queen is present in the same column then we return false
        }
    }

    int x = row;
    int y = col;

    // Here we are traversing diagonally left in upward direction because below this position all the rows will be 0 so we only need to check upwards
    // So we have to decrement row and column to traverse diagonally in left
    while(x>=0 && y>=0){
        if(arr[x][y] == 1){
            return false; // If queen is present in it's digonally left direction then we return false
        }
        x--;
        y--;
    }

    int x1 = row;
    int y1 = col;
    
    // Here we are traversing diagonally right in upward direction because of same logic as in left movement
    // So we have to decrement rows and increment columns
    while(x1>=0 && y1<n){
        if(arr[x1][y1] == 1){
            return false; // If queen is present in it's diagonally right direction then we return false
        }
        x1--;
        y1++;
    }

    // If all the above conditions doesnot satisfy it means we have placed queen at hers correct position and return true
    return true;

}

// These function tells us whether we can solve a sudoku or not
bool solve(int** arr,int row,int n){

    if(row == n){
        return true; // This means we have placed all n queens without any trouble so we return true
    }

    // Here we are trying to find correct position by assuming any position and try to solve it
    for(int col=0;col<n;col++){
        if(isSafe(arr,row,col,n)){ // If the position is safe then we can place our queen 
            arr[row][col] = 1;
            if(solve(arr,row+1,n)){ // If our assumed position is correct then the queens will be placed at their correct positions and problem is solved
                return true;
            }
            // Back tracking
            arr[row][col] = 0; // If our assumed position is not correct then we backtrack and reset the position and try for another position
        }
    }


    // If after doing all this we are unable to place queens at their position then we return false
    return false;
}

void display(int** arr,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            arr[i][j] = 0;
        }
    }
    if(solve(arr,0,n)){
        display(arr,n);
    }
    else{
        cout<<"Cannot Solve"<<endl;
    }
    return 0;
}