#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> a){
    int n = a.size();
    if(n==1)return true;

    bool single_case;
    if(a[n-1] >= a[n-2]) single_case = true;
    else single_case = false;

    a.pop_back();
    if(isSorted(a) and single_case) return true;
    else return false;
}

int main(){
    vector<int> a = {1,3,3,4};
    cout << isSorted(a);
}