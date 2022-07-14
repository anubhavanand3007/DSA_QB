#include<bits/stdc++.h>
using namespace std;

class tree{
    public:    
        int data;
        tree* left;
        tree* right;

        tree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void bottomview_util(tree* head, int lat, int alt, vector<pair<int,int>> &hr){
    if(head == NULL)return;
    bottomview_util(head->left,lat-1,alt+1,hr);
    bottomview_util(head->right,lat+1,alt+1,hr);

    if(alt > hr[lat].second) hr[lat] = {head->data, alt};
}

vector<int> bottomview(tree* head){
    pair<int,int> a = {-1,-1};
    vector<pair<int,int>> hr;
    for(int i=0;i<100;i++)hr.push_back(a);
    vector<int> ans;
    bottomview_util(head, 50, 0, hr);
    
    for(auto i: hr){
        if(i!=a) ans.push_back(i.first);
    }

    return ans;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    for(auto i:bottomview(head)){
        cout << i << ' ';
    }

    return 0;
}