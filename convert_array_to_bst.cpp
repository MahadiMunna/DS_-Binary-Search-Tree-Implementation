#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
        int val;
        Node* left;
        Node* right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* convert(int a[],int n,int l,int r){
    if(l>r) return NULL;
    int mid=(l+r)/2;
    Node* root = new Node(a[mid]);
    Node* leftRoot = convert(a,n,l,mid-1);
    Node* rightRoot = convert(a,n,mid+1,r);
    root->left=leftRoot;
    root->right=rightRoot;
    return root;

}
void print(Node* root){
    if(root==NULL){
        cout<<"No Tree"<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f=q.front();
        q.pop();
        cout<<f->val<<" ";
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
}
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    Node* root = convert(arr,n,0,n-1);
    print(root);
    return 0;
}