#include<stdio.h>
#include<stdlib.h>

typedef struct list* List;
typedef struct node* Node;

struct node{
    int value;
    Node next;
};

struct list{
    int count;
    Node head;
};

List createList(){
    List list=(List)malloc (sizeof(struct list));
    list->head=NULL;
    list->count=0;
    return list;
}

Node createNode(int value){
    Node n1=(Node)malloc(sizeof(struct node));
    n1->next=NULL;
    n1->value=value;

    return n1;
}

void insertAtEnd(Node n1,List l1){
    if(l1->count==0){
        l1->head=n1;
        l1->count++;
    }

    else{
        Node temp=l1->head;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n1;
        l1->count++;
    }
}

void printList(List l1){
    if(l1->count==0){
        printf("List is empty\n");
    }
    else{
        printf("The elements in the list are:\n");
        Node temp=l1->head;

        while(temp!=NULL){
            printf("%d\n",temp->value);
            temp=temp->next;
        }
        free(temp);
    }

}

void makeListCircular(List l1){
    if(l1->count==0){
        printf("List is empty\n");
    }

    else{
        Node temp=l1->head;

        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=l1->head;
    }
}

void rotateList(int k,List l1){
    int rotate=k%(l1->count);

    makeListCircular(l1);

    Node temp=l1->head;
    Node prev=temp;

    while(rotate--){
        prev=temp;
        temp=temp->next;
    }
    l1->head=temp;
    prev->next=NULL;
}

void reverseList(List l1){
    
    if(l1->count==0){
        printf("List is empty\n");
    }

    else{
        Node temp=l1->head;
        Node prev=NULL;
        Node next=temp->next;


        while(temp->next!=NULL){
            temp->next=prev;
            prev=temp;
            temp=next;
            next=next->next;
        }
        temp->next=prev;
        l1->head=temp;

    }
}

int hasCycle(List l1){
    Node hare=l1->head;
    Node tortoise=l1->head;

    while(hare->next!=NULL && tortoise->next!=NULL){
        hare=(hare->next)->next;
        tortoise=tortoise->next;

        if(hare->value==tortoise->value){
            return 1;
        }
    }
    return 0;
}

int wrapperHasCycle(List l1){
    if(hasCycle(l1)==1){
        printf("The list has a cycle\n");
    }
    else{
        printf("The list does not have a cycle");
    }
}


int main(){
    List l1=createList();

    Node n1=createNode(1);
    Node n2=createNode(2);
    Node n3=createNode(3);
    Node n4=createNode(4);
    Node n5=createNode(5);

    insertAtEnd(n1,l1);
    insertAtEnd(n2,l1);
    insertAtEnd(n3,l1);
    insertAtEnd(n4,l1);
    insertAtEnd(n5,l1);

    //printList(l1);

    //rotateList(7,l1);
    //printList(l1);

    //reverseList(l1);
    //printList(l1);

    //n5->next=n1;

    //makeListCircular(l1);

    //wrapperHasCycle(l1);
    

}

