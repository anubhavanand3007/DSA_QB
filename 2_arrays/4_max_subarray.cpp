#include<bits/stdc++.h>
using namespace std;

// using kadane's algorithm
int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int cur = 0, ans = nums[0];
    for (int i = 0; i < n; i++)
    {
        cur += nums[i];
        ans = max(ans, cur);
        if (cur < 0)
            cur = 0;
    }
    return ans;
}

int solve(){
    vector<int> nums = {0,1,-1,-2,3,4,5,6};
    int ans = maxSubArray(nums);
    cout << ans;
}

int main(){
    solve();
    return 0;
}