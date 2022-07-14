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



bool lowest_common_ancestor(tree* head, int n1, int n2, tree* &ancestor){
    if(head == NULL)return false;
    if(head->data == n1 || head->data == n2) return true;

    if(lowest_common_ancestor(head->left,n1,n2,ancestor) && lowest_common_ancestor(head->right,n1,n2,ancestor))
    ancestor = head;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    tree* a;
    lowest_common_ancestor(head,5,6,a);
    cout << a->data;

    return 0;
}