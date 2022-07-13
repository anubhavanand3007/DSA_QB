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

bool isBalanced(tree* head, int &height){
    if(head == NULL){
        height = 0;
        return true;
    }
    int left_height = 0, right_height =0;

    bool isRightBalanced = isBalanced(head->right, right_height);
    bool isLeftBalanced = isBalanced(head->left, left_height);

    height = max(left_height, right_height) + 1;

    if (abs(left_height-right_height) > 1)return false;
    else return true;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);
    head->right->left = new tree(5);

    int height=0;
    cout<<isBalanced(head,height);

    return 0;
}