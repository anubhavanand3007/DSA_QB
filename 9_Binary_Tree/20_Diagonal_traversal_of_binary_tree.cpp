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
void diagonal_util(tree* head, int lat, int alt, vector<vector<int>> &data){
    if(head == NULL) return;

    data[lat+alt].push_back(head->data);
    diagonal_util(head->left, lat-1, alt+1, data);
    diagonal_util(head->right,lat+1, alt+1, data);

}

vector<vector<int>> diagonal(tree* head){
    vector<vector<int>> data(100);
    vector<vector<int>> ans;
    diagonal_util(head, 50, 0, data);

    int idx = 0;
    for(auto items: data){
        if(items.size() != 0){
            ans.push_back(vector<int>(0));
            for(auto item: items) ans[idx].push_back(item);
            idx++;
        }
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

    for(auto items: diagonal(head)){
        for(auto item: items) cout << item << ' ';
        cout << '\n';
    }

    return 0;
}