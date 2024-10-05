#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;


    node(int d){
        this->data = d;
        this->right = NULL;
        this->left = NULL;
    }    
};

node* buildTree(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    node* root = new node(data);

    cout<<"Enter the data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


int main(){

}