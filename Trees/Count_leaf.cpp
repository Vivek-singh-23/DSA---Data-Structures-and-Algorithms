#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node*left;
        node*right;
    
    node(int d){
        this->data = d;
        node*left = NULL;
        node*right = NULL;
    }    
};

node* buildTree(node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


int count(node*&root, int &cnt){
    if(root == NULL){
        return 0;
    }
    
    count(root->left,cnt);
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }
    count(root->right,cnt);
    return cnt;
}

// 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1


int main(){

    node*root = NULL;
    root = buildTree(root);
    int cnt = 0;
    cout<<count(root,cnt)<<endl;
}