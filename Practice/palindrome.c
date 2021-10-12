#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
struct node {
    char data;
    struct node* next;
};
 
bool isPalindromeUtil(struct node** left, struct node* right)
{
    if (right == NULL)
        return true;
 
    bool isp = isPalindromeUtil(left, right->next);
    if (isp == false)
        return false;
 
    bool isp1 = (right->data == (*left)->data);
 
    *left = (*left)->next;
 
    return isp1;
}
 
bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head, head);
}
 
void push(struct node** head_ref, char new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
 
    /* put in the data */
    new_node->data = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to pochar to the new node */
    (*head_ref) = new_node;
}
 
// A utility function to print a given linked list
void printList(struct node* ptr)
{
    while (ptr != NULL) {
        printf("%c->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
/* Driver program to test above function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    char str[] = "abacaba";
    int i;
 
    for (i = 0; str[i] != '\0'; i++) {
        push(&head, str[i]);
        printList(head);
        isPalindrome(head) ? printf("Is Palindrome\n\n") : printf("Not Palindrome\n\n");
    }
 
    return 0;
}
