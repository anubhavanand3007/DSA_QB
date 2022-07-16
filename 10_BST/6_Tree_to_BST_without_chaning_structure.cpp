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

void inorder_traversal(tree* root, vector<int> &inorder) {
    if(root == NULL) return;

    inorder_traversal(root->left, inorder);
    inorder.push_back(root->data);
    inorder_traversal(root->right, inorder);
}

void inorder_to_tree(tree* root, vector<int> inorder) {
    if (root == NULL)return;
    static int idx=0;

    inorder_to_tree(root->left, inorder);
    root->data = inorder[idx];
    idx++;
    inorder_to_tree(root->right, inorder);
    
}

void inorder_traversal1(tree* root) {
    if(root == NULL) return;

    inorder_traversal1(root->left);
    cout << root->data << ' ';
    inorder_traversal1(root->right);
}

void treetoBST(tree* root) {
    vector<int> inorder;
    inorder_traversal(root, inorder);
    sort(inorder.begin(), inorder.end());

    inorder_to_tree(root, inorder);
}

int main(){
    tree* head = new tree(2);
    head->left = new tree(25);
    head->right = new tree(30);
    head->left->left = new tree(0);
    head->left->left->left = new tree(1);
    head->left->left->right = new tree(6);

    treetoBST(head);
    inorder_traversal1(head);

    return 0;
}