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

void bottom_traversal(tree* head, vector<int> &boundaryorder){
    if(head == NULL) return;
    
    if(head->left == NULL && head->right == NULL){
        boundaryorder.push_back(head->data);
        return;
    }

    bottom_traversal(head->left, boundaryorder);
    bottom_traversal(head->right, boundaryorder);
}

void right_traversal( tree* head, vector<int> &boundaryorder){
    if(head == NULL) return;

    right_traversal(head->right,boundaryorder);

    boundaryorder.push_back(head->data);
}

vector<int> Boundary_traversal(tree* head){
    //left tree traversal
    vector<int> boundaryorder;
    tree* curr = head;
    while(curr != NULL){
        boundaryorder.push_back(curr->data);
        curr = curr->left;
    }
    boundaryorder.pop_back();

    //bottom traversal
    bottom_traversal(head, boundaryorder);
    boundaryorder.pop_back();


    //right tree traversal
    right_traversal(head,boundaryorder);
    boundaryorder.pop_back();
    
    return boundaryorder;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    for(auto item: Boundary_traversal(head)){
        cout << item << ' ';
    }

    return 0;
}
