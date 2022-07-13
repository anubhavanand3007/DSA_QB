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

vector<int> left_view(tree* head){
    queue<tree*> q;
    q.push(head);
    vector<int> leftview;

    while(!q.empty()){
        int curr_size = q.size();

        leftview.push_back(q.front()->data);
        while(curr_size--){
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);
            q.pop();
        }
    }

    return leftview;
}


int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);
    head->left->left->right->right = new tree(7);

    vector<int> leftview = left_view(head);
    for( auto i:leftview)cout << i << ' ';

    return 0;
}