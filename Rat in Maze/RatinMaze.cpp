#include<bits/stdc++.h>
using namespace std;

// Here we are checking whether mouse can travel on given path or there is a wall
bool isSafe(int** arr,int row,int col,int n){
    if(row<n && col<n && arr[row][col] == 1){
        return true;
    }
    return false;
}

// Here we are finding an escape path for mouse
bool travel(int** arr,int row,int col,int n,int** solArr){


    // If rat is able to reach at the last position of the matrix then he has escaped the maze and we return true
    if(row==n-1 && col == n-1){
        solArr[row][col] = 1;
        return true;
    }

    // Here we are checking first whether there is path or wall
    if(isSafe(arr,row,col,n)){
        solArr[row][col] = 1; // These is our assumption that mouse can escape out by following this path
        if(travel(arr,row+1,col,n,solArr)){ // We are moving forward to find forward path by taking previous assumption
            return true; // If mouse is able to reach out then we return true
        }
        // A mouse can travel in two directions only either forward or downward
        // Here we are checking for downward path
        if(travel(arr,row,col+1,n,solArr)){
            return true;
        }
        // BackTracking
        solArr[row][col] = 0; // Our assumption was wrong and mouse cannot escape out by following that path so we backtrack and reset our changes
        return false;
    }

    // After going through all the conditions if it is not able to escape out then unfortunately we cannot help him and he is trapped forever
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

int main(){

    int n;
  cout<<"Enter size of maze: ";
    cin>>n;
    int** arr = new int*[n];
    for(int i=0;i<n;i++){
      arr[i] = new int[n];
    }

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>arr[i][j];
      }
    }

    int** solArr = new int*[n];
    for(int i=0;i<n;i++){
      solArr[i] = new int[n];
      for(int j=0;j<n;j++){
        solArr[i][j] = 0;
      }
    }

    if(travel(arr, 0, 0,n,solArr)){
      cout<<"\n\n";
      cout<<"Path that rat can follow to escape maze..."<<endl;
      display(solArr,n);
    }
    else{
      cout<<"Cannot Solve"<<endl;
    }
    
    return 0;
}