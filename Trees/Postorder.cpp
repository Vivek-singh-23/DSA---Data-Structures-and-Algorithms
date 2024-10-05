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
    cout<<"enter the data"<<" ";
    int data ;
    cin>>data;

    root = new node(data);

    if(data == -1 ){
        return NULL;
    }

    cout<<"enter data for left of"<<data<<endl;
    root->left = buildTree(root->left);

    cout<<"enter data for right of"<<data<<endl;
    root->right = buildTree(root->right);

    return root;


}

void Postorder(node*root){
    if(root == NULL){
        return ;
    }
    
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";

}

int main(){
    node*root = NULL;
    root = buildTree(root);

    Postorder(root);
    // 1 3 7 -1 -1  11 -1 -1 5 17 -1 -1 -1

}