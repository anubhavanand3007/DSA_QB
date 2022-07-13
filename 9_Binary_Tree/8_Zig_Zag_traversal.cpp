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

vector<int> zig_zag_traversal(tree* head){
    queue<tree*> q;
    q.push(head);

    stack<int> st;
    queue<int> que;
    
    vector<int> zigziaorder;
    bool evenlevel = false;

    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            if(q.front()->left)q.push(q.front()->left);
            if(q.front()->right)q.push(q.front()->right);

            if(evenlevel)st.push(q.front()->data);
            else que.push(q.front()->data);

            q.pop();
        }
        while(!st.empty()){
            zigziaorder.push_back(st.top());
            st.pop();
        }
        while(!que.empty()){
            zigziaorder.push_back(que.front());
            que.pop();
        }

        if(evenlevel == true) evenlevel = false;
        else evenlevel = true;
    }

    return zigziaorder;
}

int main(){
    tree* head = new tree(7);
    head->left = new tree(9);
    head->right = new tree(7);
    head->left->left = new tree(8);
    head->left->right = new tree(8);
    head->right->left = new tree(6);
    head->left->left->left = new tree(10);
    head->left->left->right = new tree(9);

    vector<int> zigzagorder = zig_zag_traversal(head);
    for(auto item:zigzagorder)cout << item << "  ";

    return 0;
}