#include<vector>
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


node*buildTree(node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"Entere the data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Entere the data for right of "<<data<<endl;
    root->right = buildTree(root->right);


    return root;
}

void solve(node*root,int k,int n1,vector<int>&path){
    if(root == NULL ){
        return;
    }

    path.push_back(root->data);
    if(root->data == n1){
        return;
    }

    solve(root->left,k,n1,path);

    if(path.back() != n1 ){
        solve(root->right,k,n1,path);
    }

    if(path.back() != n1 ){
        path.pop_back();
    }
}

int ancestor(node*root,int k,int n1){
    if(root == NULL){
        return -1;
    }

    vector<int> path;
    solve(root,k,n1,path);

    if(path.size() <= k){
        return -1;
    }

    return path[path.size() - 1 - k];
}