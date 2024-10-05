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

    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"enter data for left of "<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

pair<bool,int> sumTree(node*root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = sumTree(root->left);
    pair<bool,int> rightAns = sumTree(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool sum = (root->data == leftAns.second + rightAns.second) ;

    pair<bool,int> ans ;
    if(left && right && sum){
        ans.first = true;
        ans.second = root->data + leftAns.second + rightAns.second;
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
    pair<bool,int> res = sumTree(root);
    print (res);

}