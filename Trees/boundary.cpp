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
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter the data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}


void tleft(node*root, vector<int> &ans){
    if(root == NULL){
        return ;
    }

    if(root->left == NULL && root->right == NULL){
        return;
    }

    ans.push_back(root->data);
    if(root->left){
        tleft(root->left, ans);
    }else{
        tleft(root->right,ans);
    }
}

void tleaf(node*root, vector<int> &ans){
    if(root == NULL){
        return;
    }

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
    }

    tleaf(root->left,ans);
    tleaf(root->right,ans);
}

void tright(node*root, vector<int> &ans){
    if(root == NULL){
        return;
    }


    if(root->right){
        tright(root->right, ans);
    }else{
        tright(root->left, ans);
    }

    ans.push_back(root->data);
}
vector<int> boundary(node*root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    ans.push_back(root->data);

    tleft(root->left,ans);

    tleaf(root->left,ans);
    tleaf(root->right,ans);

    tright(root->right,ans);
    
    return ans;

}

