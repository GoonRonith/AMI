#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node *next;
};

struct node *insertAtFirst(struct node* head,int data){
     struct node* newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    if(head==NULL){
        newNode->next=NULL;
        head=newNode;
        return head;
    }
   
    newNode->next=head;
    head=newNode;
    return head;
}

struct node *insertAtLast(struct node *head,int data){
    struct node *temp=head;
    struct node* newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return head;
    }
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

void display(struct node *head){
    if(head==NULL){
        printf("\nList is empty!");
        return;
    }
    struct node *temp=head;
    printf("\n");
    while (temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->next;
    }
    
}
int main(){
  struct node *head=NULL;
    int choice;
    while (true)
    {
       printf("\n1.press 1 for insert node at first");
        printf("\n2.press 2 for insert node at last");
        printf("\n3.press 3 for display the list");
        printf("\n4.press any other integer for exit");
        scanf("%d",&choice);
        if(choice==1){
            printf("Enter the element you want to insert at the first");
            int item;
            scanf("%d",&item);
            head=insertAtFirst(head,item);
        }
        else if (choice==2)
        {
            printf("Enter the element you want to insert at the last");
            int item;
            scanf("%d",&item);
            head=insertAtLast(head,item);
        }
        else if(choice==3){
            printf("\nList items are->");
            display(head);
        }
        else{
            break;
        }

    }
    
}