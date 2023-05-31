#include<bits/stdc++.h>
using namespace std;

// int arr[4][4] = {
//     {0,0,0,0},
//     {0,0,0,0},
//     {0,0,0,0},
//     {0,0,0,0}
// };

bool isSafe(int** arr,int row,int col,int n){

    for(int i=0;i<row;i++){
        if(arr[i][col] == 1){
            return false;
        }
    }

    int x = row;
    int y = col;

    while(x>=0 && y>=0){
        if(arr[x][y] == 1){
            return false;
        }
        x--;
        y--;
    }

    int x1 = row;
    int y1 = col;
    while(x1>=0 && y1<n){
        if(arr[x1][y1] == 1){
            return false;
        }
        x1--;
        y1++;
    }

    return true;

}

bool solve(int** arr,int row,int n){

    if(row == n){
        return true;
    }

    for(int col=0;col<n;col++){
        if(isSafe(arr,row,col,n)){
            arr[row][col] = 1;
            if(solve(arr,row+1,n)){
                return true;
            }
            arr[row][col] = 0;
        }
    }

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