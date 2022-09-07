#include<stdio.h>
#include<conio.h>

//Declration
void create();
void display();
void search();
void insert();
void deletion();

//Global variables
int list[20];
int n;

//main function
void main(){

    int ch=0;
    do{
        printf("\n1.Create\n2.Display\n3.Search\n4.Insert\n5.Delete\n6.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                create();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                deletion();
                break;
            case 6:
                break;

        }
    }while(ch!=6);
    getch();
}

void create(){
    int i;
    printf("\nEnter n: ");
    scanf("%d",&n);
    printf("Enter elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    printf("\nArray successfully created");
    display();
}

void display(){
    int i;
    printf("\nElements of array:\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",list[i]);
    }
    printf("\n");
}

void search(){
    int i,ser,c=0;
    printf("\nEnter element to search: ");
    scanf("%d",&ser);
    for(i=0;i<n;i++)
    {
        if(list[i]==ser){
            printf("\nElement %d found at position %d",list[i],i+1);
            c++;
        }
    }
    if(c==0){
        printf("\nElement not found in list");
    }
}

void insert(){
    int i,data,pos;
    printf("Enter element to add: ");
    scanf("%d",&data);
    printf("Enter position to add: ");
    scanf("%d",&pos);
    for(i=n;i>pos-1;i--){
        list[i+1]=list[i];
    }
    list[pos]=data;
    n=n+1;
    display();
}

void deletion(){
    int i,pos;
    printf("Enter position: ");
    scanf("%d",&pos);
    for(i=pos;i<=n;i++){
	    list[pos]=list[pos+1];
    }
    n=n-1;
    display();
}