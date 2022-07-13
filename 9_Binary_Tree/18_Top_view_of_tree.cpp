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


vector<int> topview(tree* head){
    tree* curr = head;
    vector<int> topvieworder;
    stack<int> st;
    while(curr != NULL){
        st.push(curr->data);
        curr = curr->left;
    }
    while(!st.empty()){
        topvieworder.push_back(st.top());
        st.pop();
    }
        
    curr = head->right;

    while(curr != NULL){
        topvieworder.push_back(curr->data);
        curr = curr->right;
    }
    return topvieworder;
}

int main(){
    tree* head = new tree(1);
    head->left = new tree(2);
    head->right = new tree(3);
    head->right->right = new tree(0);
    head->left->left = new tree(4);
    head->left->left->left = new tree(5);
    head->left->left->right = new tree(6);

    for(auto i:topview(head)){
        cout << i << ' ';
    }

    return 0;
}