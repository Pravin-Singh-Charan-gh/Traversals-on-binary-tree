#include <iostream>
#include <queue>
#include <stack>
#include <climits>
using namespace std;
class Node{
 public:
 int data;
 Node*left;
 Node*right;
 Node(int d){
  data=d;
  left=right=NULL;
 }
 Node(){
  left=right=NULL;
 }
};
Node*createTREE( Node*root ){ 
 int data;
 cout<<"Enter data : ";
 cin>>data;
 if(data==-1)return NULL;
 root=new Node(data);
 cout<<"Enter data for left node of "<<data<<" :\n";
 root->left=createTREE(root->left);
 cout<<"Enter data for right node of "<<data<<" :\n";
 root->right=createTREE(root->right);
 
 return root;
}
void levelORDER(Node*root){
 queue<Node*>q;
 q.push(root);
 q.push(NULL);
 while(!q.empty()){
  Node*temp=q.front();
  q.pop();
  if(temp==NULL){
  cout<<endl;
  if(!q.empty())
  q.push(NULL);
  }
  else{
  cout<<temp->data<<" ";
  if(temp->left)
  q.push(temp->left);
  if(temp->right)
  q.push(temp->right);
  }
 }
}
void reverseLevelOrder(Node*root){
    deque<Node*>q;
    
}
void InorderTraversal(Node*root){
    if(root->left==NULL && root->right==NULL){
        cout<<root->data<<" ";
        return;
    }
    if(root->left)
    InorderTraversal(root->left);
    cout<<root->data<<" ";
    if(root->right)
    InorderTraversal(root->right);
}
void InorderLOOP(Node*root){
	stack<Node*>s;
//	s.push(root);
	while(!s.empty()){
		if(s.top()->left==NULL && s.top()->right==NULL){
			cout<<s.top()->data<<" ";
			s.pop();
			if(!s.empty()){
				Node*t=s.top();
				s.pop();
				cout<<t->data<<" ";
				if(t->right)s.push(t->right);
			}
		}
		else if(s.top()->left==NULL && s.top()->right!=NULL){
		       	Node*t=s.top();
				s.pop();
				cout<<t->data<<" ";
				s.push(t->right);
		}
		//if(!s.empty())
		if( s.empty()!=true && s.top()->left)s.push(s.top()->left);
	}
}
void preorderLOOP(Node*root){
    if(!root)return;
    stack<Node*>s;
    s.push(root);
    while(!s.empty()){
        Node*t=s.top();
        s.pop();
        cout<<t->data<<" ";
        if(t->right)s.push(t->right);
        if(t->left)s.push(t->left);
    }
}

void PostorderLOOP(Node*root){
    if(!root)return;
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        Node*t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left)s1.push(t->left);
        if(t->right)s1.push(t->right);
    }
    while(!s2.empty()){
        cout<<s2.top()->data<<" ";
        s2.pop();
    }
}
int main(){
 Node*root=NULL;
 root=createTREE(root);
 PostorderLOOP(root);
 return 0;
}
