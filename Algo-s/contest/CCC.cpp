#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
struct Node{
  int val;
  Node *next,*prev;
  int cn;
  
  Node(int x){
    next=nullptr;
    prev = nullptr;
    val = x;
    
  }
};
struct LinkedList{
public:
  int count;
  Node *head,*tail;
  LinkedList(){
    head=tail=nullptr;
    count=0;
  }
  void cnt(int x){
    int cn=0;
    Node  *cur = head;
    while(cur){
      if(cur->val==x){
        cn++;
      }
      cur=cur->next;
    }
    cout<<cn<<endl;
  }
  void getNth(int x){
    int v=0;
    int c=0;
    Node *cur = head;
    if(count==0){
      cout<<-1<<endl;
      return;
    }
    while(cur){
      
      if(v==x){
        c++;
        cout<<cur->val<<endl;  
      }
      v++;
      cur=cur->next;      
    }
    if(c==0){
      cout<<-1<<endl;
      return;
    }
    
  }
  
  void insertFirst(int x){
    count++;
    Node *node = new Node(x);
  
    if(head==nullptr){
      head=node;
      tail=node;
      return;
    }else{
      head->prev=node;
      node->next=head;
      head=node;
    }
    
  }
  void insertLast(int x){
    count++;
    Node *node = new Node(x);
    
    if(tail==nullptr){
      tail=node;
      head=node;
      return;
    }
    else{
      tail->next=node;
      node->prev=tail;
      tail=node;
    }
    
  }
  void deleteFirst(){
    head = head->next;
    count--;
    if(head!=nullptr){
      head->prev = nullptr;
    }
    else{
      tail = nullptr;
    }
  }
  void deleteLast(){
    tail= tail->prev;
    count--;
    if(tail!=nullptr){
      tail->next = nullptr;
    }
    else{
      head = nullptr;
    }
  }
  void del(int x){
    count--;
    Node *cur = head;
    while(cur && cur->val!=x){
      cur=cur->next;
    }
    if(!cur)return;
    if(cur==head){
      deleteFirst();
    }
    else if(cur==tail){
      deleteLast();
    }
    else{
      cur->next->prev=cur->prev;
      cur->prev->next=cur->next;
    }
  }
  void print(){
    Node *cur = head;
    while(cur){
      if(cur!=head){cout<<" ";}
      cout<<cur->val;
      cur=cur->next;
    }
    cout<<"\n";
  }
  
};
int main(){
  int n,x;
  string s;
  Node *linkedList = new LinkedList();
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s;
    if(s=="insertFirst"){
      cin>>x;
      linkedList->insertFirst(x);
    }
    if(s=="insertLast"){
      cin>>x;
      linkedList->insertLast(x);
    }
    if(s=="delete"){
      cin>>x;
      linkedList->del(x);
    }
    if(s=="deleteLast"){
      linkedList->deleteLast();
    }
    if(s=="deleteFirst"){
      linkedList->deleteFirst();
    }
    if(s=="cnt"){
      cin>>x;
      linkedList->cnt(x);
    }
    if(s=="getNth"){
      cin>>x;
      linkedList->getNth(x);

    }
  }
  linkedList->print();

  
  return 0;
}