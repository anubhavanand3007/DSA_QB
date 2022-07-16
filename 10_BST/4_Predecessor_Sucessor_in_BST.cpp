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

int predecessor(tree* root, int val){
    if( root == NULL) return -1;
    int max = INT_MIN;
    while(root->data != val){
        if(root->data > val)root = root->left;
        if(root->data < val)root = root->left;
    }
    root = root->left;
    if( root == NULL) return -1;
    while(root->right != NULL) root = root->right;

    return root->data;
}

int sucessor(tree* root, int val){
    if( root == NULL) return -1;
    int max = INT_MIN;
    while(root->data != val){
        if(root->data > val)root = root->left;
        if(root->data < val)root = root->left;
    }
    root = root->right;
    if( root == NULL) return -1;
    while(root->left != NULL) root = root->left;

    return root->data;
}

int main(){
    tree* head = new tree(25);
    head->left = new tree(8);
    head->right = new tree(30);
    head->left->left = new tree(1);
    head->left->left->left = new tree(0);
    head->left->left->right = new tree(6);

    cout << sucessor(head,25);

    return 0;
}