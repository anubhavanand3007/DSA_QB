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

vector<int> reverse_level_order_traversal(tree* head){
    vector<tree*> levelorder;
    levelorder.push_back(head);

    for(int i=0; i < levelorder.size(); i++){
        if(levelorder[i]->right != NULL) levelorder.push_back(levelorder[i]->right);
        if(levelorder[i]->left != NULL) levelorder.push_back(levelorder[i]->left);
    }

    vector<int> reverse_level_order;

    for(int i=levelorder.size()-1; i>=0; i--){
        reverse_level_order.push_back(levelorder[i]->data);
    }

    return reverse_level_order;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    vector<int> reverse_level_order = reverse_level_order_traversal(head);
    for(auto i: reverse_level_order){
        cout << i << ' ';
    }

    return 0;
}