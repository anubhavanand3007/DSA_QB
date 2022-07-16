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

int LCAinBST(tree* root, int n1, int n2){
    if(root == NULL)return -1;

    if( (n1 < root->data && n2 > root->data) || (n1 > root->data && n2 < root->data)) return root->data;
    else if(n1 < root->data && n2 < root->data)LCAinBST(root->left, n1, n2);
    else LCAinBST(root->right,n1,n2);
}

int main(){
    tree* head = new tree(25);
    head->left = new tree(2);
    head->right = new tree(30);
    head->left->left = new tree(1);
    head->left->left->left = new tree(0);
    head->left->left->right = new tree(6);

    cout << LCAinBST(head,6,30);

    return 0;
}