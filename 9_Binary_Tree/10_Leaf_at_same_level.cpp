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

void isLeafatSameLevel_util(tree* head, int &count, int height, int level){
    if(head == NULL){
        if(level == height+1){
            count++;
        }
        return;
    }

    isLeafatSameLevel_util(head->left, count, height, level+1);
    isLeafatSameLevel_util(head->right, count, height, level+1);
}

int height_of_tree(tree* head){
    if(head == NULL)return 0;
    return max(height_of_tree(head->left), height_of_tree(head->right)) + 1;
}

int isLeafatSameLevel(tree* head){
    int height = height_of_tree(head);
    
    int count = 0;
    isLeafatSameLevel_util(head, count, height, 1);

    if(count == pow(2,height))return true;
    else return false;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->right = new tree(2);
    head->right->left = new tree(3);    
    head->left->left = new tree(2);
    head->right->left->right = new tree(3);



    cout << isLeafatSameLevel(head);


    return 0;
}