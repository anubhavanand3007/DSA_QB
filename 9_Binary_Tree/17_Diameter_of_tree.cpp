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

int Diameter(tree* head, int &height){
    if(head == NULL){
        return 0;
        height = 0;
    }
    int left_height = 0, right_height = 0;
    int left_diameter = Diameter(head->left,left_height);
    int right_diameter = Diameter(head->right, right_diameter);

    height = max(left_height, right_height) + 1;

    return max(
        max(
            left_diameter, right_diameter
        ),
        left_height+right_height+1
    );
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->left->left = new tree(6);

    int height = 0;

    cout << Diameter(head,height);

    return 0;
}