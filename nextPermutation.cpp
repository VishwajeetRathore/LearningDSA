#include<iostream>
#include<vector>
using namespace std;

void nextPermu(vector<int>& A){
    int n=A.size();
    int pivot=-1;
    //finding pivot
    for (int i=n-2;i>=0;i--){
        if(A[i]<A[i+1]){
            pivot=i;
            break;
        }
    }
    //swapping Right Most Element (i.e. smallest num > pivot) with pivot 
    if(pivot >=0){
        for(int i=n-1;i>pivot;i--){
            if(A[i]>A[pivot]){
                swap(A[i],A[pivot]);
                break;
            }
        }
    }

    //reversing (pivot+1) to n-1
    int i=pivot+1;
    int j=n-1;
    while(i<j){
        swap(A[i++],A[j--]);
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
    vector<int> nums={23,6,12,7,5,3};
    vector<int> num2(nums);
    nums.erase(nums.begin());
    printArr(nums);
    nums.erase(nums.begin()+2);
    nums.insert(nums.begin()+1,50);
    // nextPermu(nums);
    printArr(nums);
    return 0;
}