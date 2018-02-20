#include<stdio.h>
#include<stdlib.h>


struct node{
  
  int data;
  struct node *next;

}*start;

int x;


struct node *create();

void insertAtBegining();
void insertAtEnd();
void insertAfterSpecifyNode();
void insertBeforeSpecifyNode();

void deleteAtBegining();
void deleteAtEnd();
void deleteSpecificNode();

void changeSpecificNodeData();
void reverseLinkedList();
void displayLinkedList();


int sizeOfLinkedList();

int main(){ 

  int n,h;
  do{
    printf("\n\t\t***********SINGLY LINKED LIST************\n");
    
    printf("1 : Insert Node At Begining\n");
    printf("2 : Insert Node At End\n");
    printf("3 : Insert Node After A Specific Node\n");
    printf("4 : Insert Node Before A Specific Node\n");
    
    printf("5 : Delete Node At Begining\n");
    printf("6 : Delete Node At End\n");
    printf("7 : Delete Node No.\n");
    
    printf("8 : Change Data Of A Specific Node\n");
    printf("9 : Reverse the Linked List\n");
    
    printf("Your Choice: ");


    scanf("%d",&n);
    
    switch(n){
      
      case 1 :   insertAtBegining();
            break;
            
      case 2 :   insertAtEnd();
            break;
            
      case 3 :   insertAfterSpecifyNode();
            break;
            
      case 4 :   insertBeforeSpecifyNode();
            break;
            
      case 5 :   deleteAtBegining();
            break;
            
      case 6 :   deleteAtEnd();
            break;
            
      case 7 :   deleteSpecificNode();
            break;
            
      case 8 :   changeSpecificNodeData();
            break;
    
      case 9 :   reverseLinkedList();
            break;
            
      default:   printf("Try again\n\n");
      
        }
    
    displayLinkedList();
    
    printf("1 : Continue\n");
    scanf("%d",&h);
    
    if(h!=1){
      printf("\nInvalid Value.\nExited From The Process.");
      exit(1);
    }
  }while(h==1);
  
  return 0;

}






int sizeOfLinkedList(){
  
  int num=0;
  
  struct node *t;
  
  t=start;
  
  while(t!=NULL){
    
    t = t->next;
    num++;
    
  }
  
  return num;
  
}

struct node *create(){ 

  struct node *p;
  p=(struct node*)malloc(sizeof(struct node));
  printf("Enter the number : ");
  scanf("%d",&x);
  p->data=x;
  p->next=NULL;
  return p;

}



void insertAtBegining(){
  
  struct node *t, *q;
  if(start==NULL){ 
    t=create(); 
    start=t;  
  }
  else{ 
    t=start;
    q=create();   
    q->next=t;
    start=q;  
  }
  
}



void insertAtEnd(){
  
  struct node *t, *q;
  if(start==NULL){
    t=create();  
    start=t; 
    }
  else{
    
    t=start;
    
    while(t->next!=NULL)
      t=t->next;
        
    q=create(); 
    t->next=q; 
    
    }
  
}



void insertAfterSpecifyNode(){ 
  
  struct node *t, *q;
  int se, getSize, counter=1;
  
  printf("Enter Specific Node No: ");
  scanf("%d",&se);       
  
  getSize = sizeOfLinkedList();
  
  t=start;
  
  if(se>0&&(se<=getSize)){
      
        while(counter<se){
            t=t->next;
            counter++;
        }
        q=create();  
        q->next=t->next;
        t->next=q; 
        
  }
  else{
      printf("Please choose valid node number.\n");
  }
  
}

void insertBeforeSpecifyNode(){
  
  struct node *t, *q, *r;
  int se, getSize, counter=1;
  
  printf("Enter Specific Node No: ");
  scanf("%d",&se);       
  
  getSize = sizeOfLinkedList();
  
  t=start;
  
  if(se>0&&(se<=getSize)){
      
        
        if(se>1){
        
           while(counter<se){
                r=t;
                t=t->next;
                counter++;
            }
            
            q=create();
            q->next=r->next;
            r->next=q; 
        }
        else{
            insertAtBegining();
        }
        
        
  }
  else{
      printf("Please choose valid node number.\n");
  }
  
}


void deleteAtBegining(){ 
    struct node *t;
    
    if(start!=NULL){ 
        t=start;
        start=t->next;
        free(t);  
        t=NULL;
    }
    
}


void deleteAtEnd(){ 
    struct node *t, *r;
    
    if(start!=NULL){
        if(start->next==NULL){
            free(start);
            start=NULL;
        }
        else{
            t=start;
            while(t->next!=NULL){
                r=t;
                t=t->next;
            }
            free(t);
            t=NULL;
            r->next=NULL; 
        }
        
    }
    
}


void deleteSpecificNode(){
    struct node *t, *r;
    int se, getSize, counter=1;
  
    printf("Enter Node no. = ");
    scanf("%d",&se);
    
    getSize = sizeOfLinkedList();

    t=start;
  
    if(se>0&&(se<=getSize)){
      
            if(se>1){
                
                t=start;
                while(counter<se){ 
                    r=t;
                    t=t->next; 
                    counter++;
                } 
                r->next=t->next;
                printf("The deleting element is %d.\n",t->data);
                free(t);   /*Delete with perticular data*/
                t=NULL;
            }
            else{
                deleteAtBegining();
            }
            
      
    }
    else{
        printf("Please choose valid node number.\n");
    }
}


void changeSpecificNodeData(){
    struct node *t;
    int se, c, getSize, counter=1;
  
    printf("Enter Node no = ");
    scanf("%d",&se);
    
    
    getSize = sizeOfLinkedList();

    t=start;
  
    if(se>0&&(se<=getSize)){
      
            t=start;
            while(counter<se){
                t=t->next;
                counter++;
            }
                
                
            printf("Enter the no : ");
            scanf("%d",&c);
            
            t->data=c;
      
    }
    else{
        printf("Please choose valid node number.\n");
    }
    
}


void reverseLinkedList(){
    
    struct node *prev, *current, *next;
    prev = NULL;
    current = start;
    
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    start = prev;
    
}


void displayLinkedList()
{ struct node *t;
  t=start;
  if(t==NULL) /*When there is no node*/
    { printf("Linked List is empty.\n");
    }
  else   /*When there are some node*/
    { while(t!=NULL)
           { printf("%d\t",t->data);
             t=t->next;
           }
      printf("\n");
    }
}
