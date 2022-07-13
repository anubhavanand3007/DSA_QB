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

bool isSubtree_util(tree* head1, tree* head2){
    if(head1 == NULL && head2 == NULL) return true;
    bool is_left_subtree = isSubtree_util(head1->left, head2->left);
    bool is_right_subtree = isSubtree_util(head1->right, head2->right);

    if(is_left_subtree && is_right_subtree && head1->data==head2->data) return true;
    else return false;
}

bool isSubtree(tree* head1, tree* head2){
    if(head2 = NULL) return false;
    if(head1 == NULL && head2 !=NULL)return false;
    if(head1->data == head2->data){
        if(isSubtree_util(head1, head2)) return true;
    }
    
    return isSubtree(head1->left, head2) ||  isSubtree(head1->right, head2);
}



int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    cout<< isSubtree(head,head->left->left->right);

    return 0;
}