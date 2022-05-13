#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n=nums.size(), curr= -1;
    
    for(int i=0;i<n-1;i++) if(nums[i] < nums[i+1])curr = i;
    
    
    if(curr == -1){
        sort(nums.begin(),nums.end());
    }
    else {
        
        int min_num=nums[curr+1],index;
        for(int i=curr+1;i<n;i++){
            if(min_num>nums[i]){
                min_num = nums[i];
                index = i;
            }
        }
        
        int temp = nums[curr];
        nums[curr] = nums[index];
        nums[index] = temp;

        sort(nums.begin()+curr+1,nums.end());
    }
}

int solve(){
    int x,y,z;cin>>x>>y>>z;
    vector<int> nums = {x,y,z};
    nextPermutation(nums);
    for(int i:nums){
        cout << i << ' ';
    }
}

int main(){
    solve();
    return 0;
}