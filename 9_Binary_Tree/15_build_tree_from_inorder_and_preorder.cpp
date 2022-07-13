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

int search(vector<int> inorder, int str, int end, int value){
    for(int i=str;i<=end;i++){
        if(inorder[i] == value){
            return i;
        }
    }
}

tree* buildTree(vector<int> preorder, vector<int>inorder, int &idx, int str, int end){
    if(str>end) return NULL;
    
    int curr = search(inorder, str, end, preorder[idx]);
    tree* head = new tree(preorder[idx]);
    idx++;

    head->left = buildTree(preorder, inorder, idx, str, curr-1);
    head->right = buildTree(preorder, inorder, idx, curr+1, end);

    return head;
}

void preorder1(tree* head){
    if( head == NULL )return;
    
    cout << head->data << ' ';
    preorder1(head->left);
    preorder1(head->right);
}

int main(){
    vector<int> preorder = {3,9,20,15,7}, inorder = {9,3,15,20,7};
    int idx = 0;
    tree* head = buildTree(preorder,inorder,idx,0,4);
    preorder1(head);
    return 0;
}