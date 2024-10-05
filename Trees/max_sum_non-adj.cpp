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



pair<int,int> solve(node*root){
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> leftAns = solve(root->left);
        pair<int,int> rightAns = solve(root->right);
        
        pair<int,int > ans;
        ans.first = root->data + leftAns.second + rightAns.second ;
        ans.second = max(leftAns.first,leftAns.second) + max(rightAns.first,rightAns.second) ;
        
        return ans;
    }
int getMaxSum(node *root) 
    {
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }