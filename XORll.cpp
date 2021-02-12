#include <iostream>
using namespace std;
 
class Node
{
public:
    int val;
    Node *nPx;
    Node() {val=0;nPx=NULL;}
    Node(int v)
    {
        val = v;
        nPx = NULL;
    }
    
};
 
Node* XOR (Node *a, Node *b) 
{ 
    return reinterpret_cast<Node *>(
      reinterpret_cast<uintptr_t>(a) ^ 
      reinterpret_cast<uintptr_t>(b)); 
} 
 
void insertNode(Node *head, int data)
{
    Node *curr = head;
    Node *prev = NULL,*next=NULL;

    while(prev!=curr->nPx)
    {
        next = XOR(prev,curr->nPx);
        prev = curr;
        curr = next;
    }

    Node *tmp = new Node(data);
    curr->nPx = XOR(prev,tmp);
    tmp->nPx=curr;
}
 
void printList(Node *head){
    Node *curr = head;
    Node *prev = NULL,*next=NULL;
    while(prev!=curr->nPx || prev==NULL)
    {
        cout << curr->val << " ";
        next = XOR(prev,curr->nPx);
        prev = curr;
        curr = next;
    }
    cout<<curr->val<<endl;
}

Node* getNode(Node* head, int index){
    Node *curr = head;
    Node *prev = NULL,*next=NULL;
    int i=0;
    if(index==0){
        return head;
    }
    else{
        while(prev!=curr->nPx && index != i){
            
            next = XOR(prev,curr->nPx);
            prev = curr;
            curr = next;
            i++;
        }
      
        if(i!=index)
            return NULL;
        else
            return curr;
    }
}
int main()
{
    
    Node *head = new Node(5);
 
    head->nPx=NULL;
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 10);
    cout<<"XOR LINKED LIST: ";
    printList(head);
    int index=5;
    Node* tmp=getNode(head,index);
    if(tmp==NULL)
        cout<<"Node at Index: "<<index<<" :Index do not exist!!!"<<endl;
    else
        cout<<"Node at index is "<<tmp->val<<endl;
    return 0;
}

