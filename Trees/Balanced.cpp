#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL; 
    }    
};

node* buildTree(node*root){
    cout<<"enter data for root node"<<endl;
    int data;
    cin>>data;

   

    if(data == -1){
        return NULL;
    }
    root = new node(data);

    cout<<"enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

pair<bool,int> balanced(node*root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool ,int> left = balanced(root->left);
    pair<bool ,int> right = balanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int> ans;
    ans.second = max(left.second , right.second) + 1; 
    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }

    return ans;
}

void print(pair<bool,int> &ans){
    cout<< ans.first;
}

int main(){

    node*root = NULL;
    root = buildTree(root);

    pair<bool,int> res = balanced(root);
    print (res);    

}
// 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1