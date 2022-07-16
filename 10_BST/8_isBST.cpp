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

bool isBST (tree* root, int lowerlimit, int upperlimit) {
    if(root == NULL) return true;

    bool current_val_condition = root-> data < upperlimit && root->data > lowerlimit;
    bool is_left_tree_BST = isBST(root->left, lowerlimit, root->data);
    bool is_right_tree_BST = isBST(root->right, root->data, upperlimit);

    return is_left_tree_BST && is_right_tree_BST && current_val_condition;
}

int main(){
    tree* head = new tree(25);
    head->left = new tree(20);
    head->right = new tree(30);
    head->left->left = new tree(5);
    head->left->left->left = new tree(4);
    head->left->left->right = new tree(6);

    cout << isBST(head, INT_MIN, INT_MAX);

    return 0;
}