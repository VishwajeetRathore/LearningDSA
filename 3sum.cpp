#include <iostream>
#include <vector>
using namespace std;

class Solution{
public :
    vector <vector <int>> threeSum(vector<int>& nums){
        int len=nums.size();
        cout<<len;
        return {};
    }

};

int main(){
    vector<int> numList={-1,0,1,2,-1,-4,3};

    Solution sol;
    sol.threeSum(numList);

    return 0;
}

