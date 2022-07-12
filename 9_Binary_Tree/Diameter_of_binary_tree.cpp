#include<iostream>
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

int diameter_of_tree(tree* head, int &diameter, int &height){
    if(head == NULL) {
        height = 0;
        return 0;
    }

    int lh = 0, rh = 0;

    diameter_of_tree(head->left, diameter, lh);
    diameter_of_tree(head->right, diameter, rh);

    height = max(rh,lh)+1;
}

int main(){
    tree* a = new tree(2);
    a->left = new tree(2);
    a->left->left = new tree(2);
    a->right = new tree(2);

    int height = 0;
    diameter_of_tree(a,height,height);
    cout << height;

    return 0;
}