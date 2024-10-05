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

void solve(node*root,int k,int &count,vector<int> path){
    if(root == NULL){
        return ;
    }

    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int size = path.size();
    int sum = 0;
    for(int i= size - 1 ;i >=0 ;i--){
        sum += path[i];
        if(sum == k){
            count++;
        }
    }

    path.pop_back();
}

int kpath(node*root,int k){
    if(root == NULL){
        return 0;
    }

    vector<int> path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}

