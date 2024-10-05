#include<iostream>
#include<vector>
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

node* Insert(node*&root, int d){
    
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(root->data > d){
        root->left = Insert(root->left, d);
    }

    
    if(root->data < d){
        root->right = Insert(root->right, d);
    }

    return root;


}

void Input(node*&root){
    
    int data;
    cin>>data;

    while(data != -1){
        root = Insert(root, data);
        cin>>data;
    }
}


void inorder(node* root,vector<int>&path){
    if(root == NULL){
        return;
    }

    inorder(root->left, path);
    path.push_back(root->data);
    inorder(root->right, path);

}

void solve(node*root){
    vector<int> path;
    inorder(root, path);
    balanced(0, path.size() - 1, path );

}

node*balanced(int s, int e, vector<int> &path){
    
    int mid = (s + e) / 2;
    node*root = new node(path[mid]);
    root->left = balanced(s, mid - 1, path);
    root->right = balanced(mid + 1, e, path);

    return root;
}