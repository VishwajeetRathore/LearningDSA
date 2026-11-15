#include<iostream>
#include<vector>
using namespace std;

void sortArr(vector<int>& A,vector<int>& B,int m,int n){
    int i=m-1 , j=n-1 , idx=m+n-1;
    while(idx>=0){
        if(A[i]>=B[j]){
            A[idx]=A[i];
            idx--;
            i--;
        }else{
            A[idx]=B[j];
            idx--;
            j--;
        }
    }
}

void printArr(vector<int> & nums){
    cout<<"Array is : ";
    for (int val : nums){
        cout<<val<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> A={4,5,6,0,0,0};
    vector<int> B={1,2,3};

    printArr(A);
    printArr(B);
    sortArr(A,B,3,3);
    printArr(A);
    
    return 0;
}