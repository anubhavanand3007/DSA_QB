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

int sumtree(tree* head){
    if(head == NULL)return 0;

    int left_sum = sumtree(head->left);
    int right_sum = sumtree(head->right);
    
    int temp = head->data;
    head->data = left_sum + right_sum;

    return left_sum + right_sum + temp;
}

vector<int> level_order_traversal(tree* head){
    queue<tree*> q;
    q.push(head);
    vector<int> levelorder;
    while(!q.empty()){
        if(q.front()->left)q.push(q.front()->left);
        if(q.front()->right)q.push(q.front()->right);

        levelorder.push_back(q.front()->data);
        q.pop();
    }
    return levelorder;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    sumtree(head);
    vector<int> levelorder = level_order_traversal(head);
    for(auto i:levelorder) cout << i << ' ';

    return 0;
}