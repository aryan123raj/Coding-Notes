#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left =NULL;
        right=NULL;
    }

};
int heightofTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int ls=heightofTree(root->left);
    int rs=heightofTree(root->right);
    int height =max(ls,rs)+1;
    return height;
}
void PrintKthlevel(Node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    PrintKthlevel(root->left,k-1);
    PrintKthlevel(root->right,k-1);
    return;

}
void printAlllevels(Node* root){
    int H=heightofTree(root);
    if(root==NULL){
        return;
    }
    for(int i=1;i<=H;i++){
        PrintKthlevel(root,i);
        cout<<endl;
    }
}
void PrintPre(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<"  ";
    PrintPre(root->left);
    PrintPre(root->right);
}
void PrintIn(Node* root){
    if(root==NULL){
        return;
    }
    PrintIn(root->left);
    cout<<root->data<<" ";
    PrintIn(root->right);
}
void PrintPo(Node* root){
    if(root==NULL){
        return;
    }
    PrintPo(root->left);
    PrintPo(root->right);
    cout<<root->data<<" ";
}

Node* BuildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    Node* root=new Node(d);
    root->left=BuildTree();
    root->right=BuildTree();
    return root;

}
int main(){
    int data;
    Node *root= BuildTree();
    // PrintPre(root);
    // cout<<endl;
    // PrintIn(root);
    // cout<<endl;
    // PrintPo(root);
    // cout<<endl;
    // cout<<heightofTree(root);
    printAlllevels(root);
}