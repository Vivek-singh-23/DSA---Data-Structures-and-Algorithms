#include<iostream>
#include<queue>
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

void buildfromleveorder(node* &root){
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data ;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node*temp = root;
        q.pop();

        cout<<"enter data for left of"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata != -1){
            temp->left = new node(leftdata);
            q.push(temp->left);
        }


        cout<<"enter data for right of"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata != -1){
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
        
    }

}

int main(){

    node*root = NULL;

    root = buildTree(root);

}