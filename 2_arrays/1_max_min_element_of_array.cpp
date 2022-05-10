#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> arr){
    int max_num = arr[0], min_num = arr[0];
    for(int i=0;i<arr.size();i++){
        max_num = max(arr[i],max_num);
        min_num = min(arr[i],min_num);
    }
    cout << max_num << ' ' << min_num;
}

int main(){
    vector<int> arr;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    solve(arr);
    return 0;
}