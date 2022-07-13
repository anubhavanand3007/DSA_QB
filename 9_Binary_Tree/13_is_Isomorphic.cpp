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

bool isIsomorphic(tree* head1, tree* head2){
    if(head1 == NULL && head2 == NULL)return true;
    if(head1 == NULL || head2 == NULL)return false;

    bool is_RR_isomorphic = isIsomorphic(head1->right, head2->right);
    bool is_RL_isomorphic = isIsomorphic(head1->right, head2->left);
    bool is_LR_isomorphic = isIsomorphic(head1->left, head2->right);
    bool is_LL_isomorphic = isIsomorphic(head1->left, head2->left);

    if  (
            (
                (is_LL_isomorphic && is_RR_isomorphic) || 
                (is_RL_isomorphic && is_LR_isomorphic)
            ) && 
            head1->data == head2->data
        ) return true;
    else return false;
}

int main(){
    tree* head1 = new tree(1);
    head1->left = new tree(2);
    head1->right = new tree(3);
    head1->right->left = new tree(6);
    head1->left->left = new tree(4);
    head1->left->right = new tree(5);
    head1->left->right->left = new tree(7);
    head1->left->right->right = new tree(8);

    tree* head2 = new tree(1);
    head2->right = new tree(2);
    head2->left = new tree(3);
    head2->left->right = new tree(6);
    head2->right->left = new tree(4);
    head2->right->right = new tree(5);
    head2->right->right->left = new tree(8);
    head2->right->right->right = new tree(7);

    cout << isIsomorphic(head1,head2);

    return 0;
}