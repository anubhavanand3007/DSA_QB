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

bool isSameTree( tree* head1, tree* head2){
    if( head1 == NULL && head2 == NULL) return true;
    if( head1 == NULL || head2 == NULL) return false;

    bool is_left_same_tree = isSameTree(head1->left, head2->left);
    bool is_right_same_tree = isSameTree(head1->right, head2->right);

    if( head1->data == head2->data && is_left_same_tree && is_right_same_tree)return true;
    else return false;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    cout << isSameTree(head,head);

    return 0;
}
