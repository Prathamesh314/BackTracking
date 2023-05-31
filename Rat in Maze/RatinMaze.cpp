#include<bits/stdc++.h>
using namespace std;

bool isSafe(int** arr,int row,int col,int n){
    if(row<n && col<n && arr[row][col] == 1){
        return true;
    }
    return false;
}

bool travel(int** arr,int row,int col,int n,int** solArr){

    if(row==n-1 && col == n-1){
        solArr[row][col] = 1;
        return true;
    }

    if(isSafe(arr,row,col,n)){
        solArr[row][col] = 1;
        if(travel(arr,row+1,col,n,solArr)){
            return true;
        }
        if(travel(arr,row,col+1,n,solArr)){
            return true;
        }
        solArr[row][col] = 0;
        return false;
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