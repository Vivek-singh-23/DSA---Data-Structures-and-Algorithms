#include<vector>
#include<queue>
#include<map>
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

    void solve(node*root, vector<int>& ans, int lvl){
        if(root == NULL){
            return ;
        }

        if(lvl == ans.size()){
            ans.push_back(root->data);
        }

        solve(root->left,ans, lvl+1);
        solve(root->right,ans, lvl+1);
    }

vector<int> left_view(node*root){
    vector<int>ans;

    if(root == NULL) {
        return ans;

    }
    int lvl = 0;
    solve(root,ans,lvl);
    return ans;
}