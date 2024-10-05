#include<queue>
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

vector<int> zigzag(node*root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<node*> q;
    q.push(root);

    bool ltor = true;
    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i=0; i<size ; i++){
            node*temp = q.front();
            q.pop();

            if(ltor){
                ans[i] = temp->data;
            }else{
                ans[size - i -1] = temp->data;
            }
        }
        ltor = !ltor;

        for(auto i:ans){
            result.push_back(i);
        }
    }
    return result;


}

int main() {
    node* root = NULL;
    root = buildTree(root);
    vector<int> zigzagTraversal = zigzag(root);

    cout << "Zigzag Traversal: ";
    for (int i = 0; i < zigzagTraversal.size(); ++i) {
        cout << zigzagTraversal[i] << " ";
    }
    cout << endl;

    return 0;
}
