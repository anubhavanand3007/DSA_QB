#include<bits/stdc++.h>
using namespace std;

class tree{
    public:    
        char data;
        tree* left;
        tree* right;

        tree(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

tree* BuildTree(string str, int start, int end){
    if(str.size() == 0 || start > end) return NULL;

    tree* head = new tree(str[start]);
    if(start == end) return head;
    start += 2;
    int curr = start;
    stack<char> st;
    while(curr<=end){
        if(str[curr] == '(')st.push('(');
        if(str[curr] == ')'){ 
            if(st.empty()){
                head->left = BuildTree(str,start,curr-1);
                break;
            }
            else st.pop();
        }
        curr++;
    }
    head->right = BuildTree(str,curr+2,end);

    return head;
}

void preorder1(tree* head){
    if( head == NULL )return;
    
    cout << head->data << ' ';
    preorder1(head->left);
    preorder1(head->right);
}

int main(){
    string input = "4(2(3)(1))(6(5))";
    tree* head = BuildTree(input,0,input.length()-1);

    preorder1(head);    

    return 0;
}