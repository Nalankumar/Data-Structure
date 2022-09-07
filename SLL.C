#include<stdio.h>
#include<stdlib.h>

void create();
void insert();
void Delete();
void find();
void display();

struct node{
  int data;
  struct node* next;
};

typedef struct node* position;

position p = NULL;
position l = NULL;

int main()
{
  int ch;
  do{
    printf("\n1.Create\n2.display\n3.Insert\n4.Delete\n5.Search\n6.Exit");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    switch(ch){
      case 1:
        create();
        break;
      case 2:
        display();
        break;
      case 3:
        insert();
        break;
      case 4:
        Delete();
        break;
      case 5:
        find();
        break;
      case 6:
        break;
      }
  }while(ch!=6);
  return 0;
}

void create()
{
  int i,x,n;
  position newnode;
  newnode = (struct node*)malloc(sizeof(struct node));
  printf("Enter no of elements: ");
  scanf("%d",&n);
  printf("Enter datas to add: ");
  scanf("%d", &x);
  newnode->data=x;
  newnode->next=NULL;
  l=newnode;
  p=l;
  for(i=1;i<n;i++){
    newnode= (struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    p->next=newnode;
    newnode->next=NULL;
    p=newnode;
  }
  display();
}

void display(){
  p=l;
  while(p!=NULL){
    printf("%d\t", p->data);
    p=p->next;
  }
}

void Delete(){
  position temp;
  int no;
  p=l;
  if(p->data==NULL)
    printf("List is empty");
  else
  {
    printf("Enter element to delete: ");
    scanf("%d",&no);
    if(p->data==no){
      temp=p;
      l=p->next;
      free(temp);
    }
    else{
      while((p->next->data!=no)  &&(p->next != NULL))
        p=p->next;
      temp = p->next;
      p->next=temp->next;
      free(temp);
    }
  }
}

void find(){
  int count,i,search;
  printf("Enter element to find: ");
  scanf("%d",&search);
  while(p->next!=NULL){
    if(p->data==search){
      count++;
      break;
    }
  }
  if(count!=0)
    printf("Element found in list");
  else
    printf("Element not found");
}

void insert(){
  int i,x,pos;
  position newnode;
  newnode =(struct node*)malloc(sizeof(struct node));
  printf("Enter data: ");
  scanf("%d",&x);
  newnode->data=x;
  newnode->next=NULL;
  printf("Enter position: ");
  scanf("%d",&pos);
  p=l;
  for(i=0;(i<pos-1)&&(p->next!=NULL);i++)
    p=p->next;
  if(l==NULL)
    l=newnode;
  else if(pos==1){
    newnode->next=l;
    l=newnode;
  }
  else if(p->next==NULL)
    p->next=newnode;
  else
  {
    newnode->next= p->next;
    p->next=newnode;
  }
}