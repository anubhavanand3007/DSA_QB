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

void mirror(tree* head){
    if(head == NULL) return;

    tree* temp = head->left;
    head->left = head->right;
    head->right = temp;

    mirror(head->left);
    mirror(head->right);

}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    return 0;
}