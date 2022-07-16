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

int min_in_BST(tree* root){
    if(root == NULL) return -1;
    while(root->left!=NULL) root = root->left;
    return root->data;
}

int main(){
    tree* head = new tree(25);
    head->left = new tree(2);
    head->right = new tree(30);
    head->left->left = new tree(1);
    head->left->left->left = new tree(0);
    head->left->left->right = new tree(6);

    cout << min_in_BST(head);

    return 0;
}