#include<vector>
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


node*buildtree(node*root ){
    cout<<"Enter the data "<<endl;
    int data ;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);

    cout<<"enter the data for left of"<<data<<endl;
    root->left = buildtree(root->left);

    cout<<"enter the data for left of"<<data<<endl;
    root->right = buildtree(root->right);

    return root;
}

void mapping(vector<int> in,map<int,int> &p){
    for(int i = 0 ;i< in.size(); i++){
        p[in[i]] = i;
    }
}

node*solve(vector<int> in, vector<int>pre,int size, int inStart, int inEnd, int index, map<int,int> &p){
    if(index >= size || inStart > inEnd){
        return NULL;
    }

    int element = pre[index];
    index++;
    node* root  = new node(element);
    int position = p[element];

    root->left = solve(in, pre, size, 0, position - 1, index, p);
    root->right = solve(in, pre, size , position + 1, size - 1,index, p  );
}

node* create(vector<int> in, vector<int> pre, int n){
    
    int index = 0;
    int inStart = 0;
    int inEnd = n-1;
    map<int,int> p;
    mapping(in, p);

    node* ans = solve(in, pre, n, inStart, inEnd, index, p);

    return ans;
}