#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

struct Node
{
int data;
Node* link;
};

Node* XOR(Node* x, Node* y) {
return (Node*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverse(Node* head)
{
Node* curr = head;
Node* prev = nullptr;
Node *next;

while (curr != nullptr)
{
cout << curr->data << " —> ";

next = XOR(prev, curr->link);

prev = curr;
curr = next;
}

cout << "nullptr";
}

void push(Node* &headRef, int data)
{

Node* newNode = new Node();
newNode->data = data;


newNode->link = XOR(headRef, nullptr);


if (headRef)
{

headRef->link = XOR(newNode, XOR(headRef->link, nullptr));
}


headRef = newNode;
}

Node* delEnd(Node *head)
{
    // Base condition
    if (head == NULL)
        cout<<"List is empty";
    else {
  
        // Stores XOR pointer
        // in current node
         Node* curr = head;
  
        // Stores XOR pointer of
        // in previous Node
        struct Node* prev = NULL;
  
        // Stores XOR pointer of
        // in next node
        Node* next;
  
        // Traverse XOR linked list
        while (XOR(curr->link, prev) != NULL) {
  
            // Forward traversal
            next = XOR(prev, curr->link);
  
            // Update prev
            prev = curr;
  
            // Update curr
            curr = next;
        }
        // If the Linked List contains more than 1 node
        if (prev != NULL)
            prev->link = XOR(XOR(prev->link, curr), NULL);
  
        // Otherwise
        else
            head = NULL;
  
        // Delete the last node from memory
        free(curr);
    }
  
    // Returns head of new linked list
    return head;
}
  

int main()
{

vector<int> keys = { 1, 2, 3, 4, 5 };

Node* head = nullptr;
for (int i = keys.size() - 1; i >=0; i--) {
push(head, keys[i]);
}

traverse(head);

delEnd(head);
cout<<"\n";

traverse(head);
return 0;
}
