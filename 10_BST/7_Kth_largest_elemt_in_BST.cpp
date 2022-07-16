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

int kth_largest_elem(tree* root,  int &val, int &k){
    if(root == NULL) return -1;

    kth_largest_elem(root->left, val, k);
    
    k--;
    if(k == 0) val = root->data;

    kth_largest_elem(root->right, val, k);


}

int main(){
    tree* head = new tree(25);
    head->left = new tree(20);
    head->right = new tree(30);
    head->left->left = new tree(5);
    head->left->left->left = new tree(0);
    head->left->left->right = new tree(6);
    int a;
    int k = 3;
    kth_largest_elem(head, a, k);
    cout << a;
    return 0;
}