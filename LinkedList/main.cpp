#include <iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node();
        Node(int data){
            this->data = data;
            this->next = nullptr;
        }
};

void addToEnd(Node** headNode, Node* newNode){
     Node *currNode = *headNode;
     if(*headNode == nullptr){
         *headNode = newNode;
         return;
     }
     // if curr not null and next not null, step forward
     while(currNode != nullptr && currNode->next != nullptr){
             currNode = currNode->next;
     }
     // now curr not null but next is
     currNode->next = newNode;
}

void insert(Node** headNode, Node* insertAfter, Node* newNode){
    Node *currNode = *headNode;
    if(*headNode == nullptr){
         *headNode = newNode;
         return;
    }
    while (currNode != insertAfter)
    {
        currNode = currNode->next;
    }

    newNode->next = currNode->next;
    currNode->next = newNode;
    

}

void printList(Node *headNode)
{
    Node *currNode = headNode;
    while (currNode != NULL)
    {
        cout << currNode->data;
        currNode = currNode->next;
    }
    cout << endl;
}

//reverse list in place
void reverseList(Node** headNode){
    // if list empty, do nothing
    if(*headNode == nullptr){
        return;
    }

    Node *curr = *headNode;
    Node *prev;
    Node *next;
    //if has at least one element
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    
    //curr becomes head
    *headNode = prev;
}

int main()
{
    Node* head = nullptr; 
    Node *n1 = new Node(1);
    addToEnd(&head,n1);
    Node *n2 = new Node(2);
    addToEnd(&head,n2);
    Node *n3 = new Node(3);
    addToEnd(&head,n3);
    Node *n4 = new Node(4);
    addToEnd(&head,n4);
    reverseList(&head);
    printList(head);
}