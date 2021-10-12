#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    char item;
    struct node *next;
};
typedef struct node *Node;

Node getNode()
{
    Node x;
    x=(Node)malloc(sizeof(struct node));
    return x;
}
Node insert_front(Node first,char data)
{
    Node new_node;
    new_node=getNode();
    new_node->item=data;
    new_node->next=NULL;
    if(first==NULL)
    {
        return new_node;
    }
        new_node->next=first;
        first=new_node;
        return first;

}

// Node insert_end(Node first,char data)
// {
//     Node last;
//     Node new_node;
//     new_node=getNode();
//     new_node->item=data;
//     new_node->next=NULL;
//     if(first==NULL)
//     {
//         return new_node;
//     }
//     last=first;
//     while(last->next!=NULL)
//     {
//       last=last->next;
//     }
//     last->next=new_node;
//     return first;
// }

int palindrome(Node *first,Node right)
{

    if(right==NULL)
    return 1;
   
    int val=palindrome(first,right->next);
   
    if(val==0)
    return 0;
   
    int check=((*first)->item==right->item);
   
   
   
    *first=(*first)->next;
   
    return check;
}
Node delete_front(Node first)
{
    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty Cannot be deleted\n");
        return first;
    }
    temp=first;
    temp=temp->next;
    free(first);
    return temp;
}
Node check_palin(Node first)
{
    int x=palindrome(&first,first);
    if(x)
    {
        printf("Given String of characters form palindrome\n");
    }
    else
    {
        printf("Not A palindrome\n");
    }
}
void display(Node first)
{

    Node temp;
    if(first==NULL)
    {
        printf("List Is Empty\n");
    }
    for(temp=first;temp!=NULL;temp=temp->next)
    {
        printf("%c\t",temp->item);
    }
    printf("\n");
}

// void swap(Node first,Node second)
// {
//     int temp=first->item;
//     first->item=second->item;
//     second->item=temp;
// }

// void alternate(Node first)
// {
//     if(first==NULL)
//     return;
   
   
//     Node prev=first;
//     Node curr=first->next;
   
   
   
//     while(curr!=NULL)
//     {
//         if(prev->item>curr->item)
//         swap(prev,curr);
       
//         if(curr->next && curr->next->item>curr->item)
//         swap(curr->next,curr);
       
//         prev=curr->next;
       
//         if(!curr->next)
//         break;
//         curr=curr->next->next;
//     }
// }


int main()
{
    Node first=NULL;
    Node a= NULL;
    Node b=NULL;
    Node ans=NULL;
    int choice,pos,n;
    char val;
    do
    {
        printf("1:Insert at Front\n");
        // printf("2:Insert at End\n");
        printf("2:Check for palindrome\n");
        printf("3:display\n");
       
        // printf("5:alternate\n");
        printf("4:Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter the Value To Be Inserted\n");
            scanf(" %c",&val);
            first=insert_front(first,val);
            break;
        // case 2:
        //     printf("Enter the Value\n");
        //     scanf(" %c",&val);
        //     first=insert_end(first,val);
        //     break;
           
            case 2:
            check_palin(first);
            break;
           
            case 3:
            display(first);
            break;
           
            // case 5:
            // alternate(first);
            // display(first);
            // break;
        }
    }while(choice!=4);
}
