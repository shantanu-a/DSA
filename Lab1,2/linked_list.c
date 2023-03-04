#include<stdio.h>
#include<stdlib.h>

typedef struct linkedList* List;
typedef struct node* Node;

struct node{
    int value;
    Node next;
};

struct linkedList{
    int count;
    Node head;
};

//The reason we are using List instead of list is because when the function returns the list variable will be destroyed and we will have no way of accesing it.

List createList(){
    List list;
    list=(List) malloc(sizeof(struct linkedList));
    list->head=NULL;
    list->count=0;
    return list;
}

Node createNewNode(int value){
    Node node=(Node)malloc(sizeof(struct node));
    node->value=value;
    node->next=NULL;

    return node;
}

void insertAtBegin(Node node,List list){

    if(list->count==0){
        list->head=node;
        node->next=NULL;     
        list->count++;
    }
    else{
        node->next=(list)->head;
        list->head=node;
        list->count++;
    }
}

void insertAfter(Node node,int targetNodeValue,List list){

    Node temp=list->head;

    if(list->count==0){
        printf("List is empty");
    }

    else{
        while((temp)!=NULL){

        if((temp)->value==targetNodeValue){
            Node ifTarget;
            ifTarget=temp->next;
            temp->next=node;
            node->next=ifTarget;
            
            list->count++;
            return ;
        }

        else{
            temp=temp->next;
        }
    }

    printf("Node not found");
    }
}

void insertAtEnd(Node node,List list){
    Node temp=list->head;

    if(list->count==0){
        list->head=node;
        node->next=NULL;
    }

    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=node;
        node->next;    
        list->count++;
    }
}

void deleteFirst(List list){
    if(list->count==0){
        printf("List is empty\n");
    }

    else{
        Node temp=(list->head)->next;
        list->head=temp;
        list->count--;
    }
}


void deleteAt(int value,List list){
    Node temp=list->head;
    Node prev=temp;

    if(list->count==0){
        printf("List is empty, nothing to be deleted\n");
    }

    else if(list->count==1){
        if(temp->value=value){
            list->head=NULL;
            free(temp);
            list->count--;
        }
        else{
            printf("Node not found");
        }
    }

    else{
        while(temp!=NULL){
            if(temp->value==value){
                prev->next=temp->next;
                free(temp);
                list->count--;
                return;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
    }
}


void printList(List list){
    Node temp=list->head;
    printf("The values in the list are:\n");

    if(list->count==0) printf("List is empty, nothing to print\n");

    while(temp!=NULL){
        printf("%d\n",temp->value);
        temp=temp->next;
    }
}


int main(){
    List list=createList();
    Node n1=createNewNode(10);
    Node n2=createNewNode(12);
    Node n3=createNewNode(2);
    Node n4=createNewNode(6);

    insertAtBegin(n1,list);
    insertAfter(n2,10,list);
    insertAfter(n3,12,list);
    insertAtEnd(n4,list);
    deleteAt(12,list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);
    deleteFirst(list);

    printf("%d\n",list->count);

    printList(list);
}


