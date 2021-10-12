#include<stdio.h>
#include<stdlib.h>
 
typedef struct node {
    int data;
    struct node* next;
}Node;
 
// Function to create newNode in a linkedlist
Node* newNode(int key,Node** head)
{
    Node* temp = (Node *)malloc(sizeof(Node));
    temp->data = key;
    temp->next = NULL;
        if(*head==NULL)
    {
        *head=temp;
    }
    else
    {
        temp->next=*head;
        *head=temp;
    }
    // printf("Insertion successful\n");
    return temp;
}
 
void reverselist(Node** head)
{
    Node *prev = NULL, *curr = *head, *next;
 
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
 
    *head = prev;
}
 
// Function to print the linked list
void printlist(Node* head)
{
    while (head != NULL) {
        printf("%d ",head->data);
        if (head->next)
            printf("-> ");
        head = head->next;
    }
    printf("\n");
}
 
void rearrange(Node** head)
{
    // 1) Find the middle point using tortoise and hare
    // method
    Node *slow = *head, *fast = slow->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
 
    // 2) Split the linked list in two halves
    // head1, head of first half    1 -> 2
    // head2, head of second half   3 -> 4
    Node* head1 = *head;
    Node* head2 = slow->next;
    slow->next = NULL;
 
    // 3) Reverse the second half, i.e.,  4 -> 3
    reverselist(&head2);
 
    // 4) Merge alternate nodes
    // *head = newNode(0,&head1); // Assign dummy Node
 
    // curr is the pointer to this dummy Node, which will
    // be used to form the new list
    Node* curr = *head;
    while (head1 || head2) {
        // First add the element from list
        if (head1) {
            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
 
        // Then add the element from the second list
        if (head2) {
            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }
 
    // Assign the head of the new list to head pointer
    *head = (*head)->next;
}
 
// Driver program
int main()
{
    int n,data;
    Node* head=NULL;
    printf("Enter the number of elements\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        newNode(data,&head);   
    }
 
    printlist(head); // Print original list
    rearrange(&head); // Modify the list
    printlist(head); // Print modified list
    return 0;
}

