#include<bits/stdc++.h>
using namespace std;

void TowerofHanoi(int n, char s, char a, char d){
    if(n==1){
        cout << s << "->" << d << '\n';
        return;
    }

    TowerofHanoi(n-1,s, d, a);
    cout << s << "->" << d << '\n';

    TowerofHanoi(n-1,a, s, d);
}

int main(){
    cout << "";
    int n=3;
    TowerofHanoi(n,'s','a','d');
    return 0;
}