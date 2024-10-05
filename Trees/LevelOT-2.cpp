// space efficient solution

#include<vector>
#include<queue>
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

    cout<<"Enter data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}


vector<vector<int>> Level(node*root){
    vector<vector<int>> output;
    if(root == NULL){
        return output;
    }
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int vecsize = q.size();
        vector<int> inner(vecsize);

        for(int i = 0; i < vecsize ; i++){
            node*temp = q.front();
            q.pop();

            inner[i] = temp->data;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        output.push_back(inner);
    }
    return output;
}

