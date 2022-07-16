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

bool SearchinBST(tree* root, int n){
    if(root == NULL) return false;

    if(root->data > n) return SearchinBST(root->left, n);
    if(root->data < n) return SearchinBST(root->right, n);
    if(root->data == n)return true;
}

tree* insert_in_BST(tree* root, int val){
    if(root == NULL){
        root = new tree(val);
        return root;
    }

    if(val > root->data){
        root->right = insert_in_BST(root->right, val);
    }
    else{
        root->left = insert_in_BST(root->left, val);
    }

    return root;
}

void inorder(tree* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int main(){
    int x;
    tree* root = NULL;
    cin >> x;
    while(x != -1){
        root = insert_in_BST(root, x);
        cin >> x;
    }
    
    inorder(root);

    cout << SearchinBST(root,1);

    return 0;
}