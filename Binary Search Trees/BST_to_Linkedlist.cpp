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

node*flattenLL(node*root){
    vector<int> path;
    inorder(root, path);

    int n = path.size();

    node*first = new node(path[0]);
    node*curr = first;

    for(int i = 1;i<n;i++){
        node*temp = new node(path[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }   

    curr->left = NULL;
    curr->right = NULL;

    return first;
}