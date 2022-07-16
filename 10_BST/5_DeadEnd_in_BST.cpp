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

int isDeadEnd(tree* root, int lowerlimit, int upperlimit){
    if( root == NULL) return false;
    if( upperlimit - lowerlimit == 2) return true;

    int isDeadEnd_in_right_subtree = isDeadEnd(root->right, root->data, upperlimit);
    int isDeadEnd_in_left_subtree = isDeadEnd(root->left, lowerlimit, root->data);

    if( isDeadEnd_in_right_subtree || isDeadEnd_in_left_subtree) {
        return true;
    }
    else return false;;
}

int main(){
    tree* head = new tree(8);
    head->left = new tree(7);
    head->right = new tree(10);
    head->left->left = new tree(2);
    // head->right->left = new tree(9);
    head->right->right = new tree(13);

    tree* head2 = new tree(8);
    head2->left = new tree(5);
    head2->right = new tree(9);
    head2->left->left = new tree(2);
    head2->left->right = new tree(7);
    //head2->left->left->left = new tree(1);

    cout << isDeadEnd(head2, 0, INT_MAX);

    return 0;
}