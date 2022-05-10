#include<bits/stdc++.h>
using namespace std;


vector<int> solve(vector<int> str){
    for(int i=0;i<str.size()/2;i++){
        int temp = str[i];
        str[i] = str[str.size()-i-1];
        str[str.size()-i-1] = temp;
    }
    return str;
}

int main(){
    vector<int> arr;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    arr = solve(arr);
    for(auto i: arr){
        cout << i << ' ';
    }
    return 0;
}