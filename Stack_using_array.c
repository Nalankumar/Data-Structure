#include<stdio.h>
#include<conio.h>

#define max 3
int stack[max];
int sp=-1;

void push(int);
int pop();
void print();

int main(){
    int ch=0,p,x;
    while(ch!=4){
        printf("\n1.Push\n2.Pop\n3.Print\n4.Exit\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the value: ");
                scanf("%d",&x);
                push(x);
                break;
            case 2:
                x=pop();
                if(x!=NULL)
                printf("The popped element is %d",x);
                break;
            case 3:
                print();
                break;
        }

    }
    return 0;
}

void push(int a){
    if(sp<max-1)
        stack[++sp]=a;
    else
        printf("Stack is full");
}

int pop(){
    int x;
    if(sp!=-1){
        x=stack[sp--];
        return x;
    }
    else{
        printf("Stack is empty");
        return NULL;
    }
}

void print(){
    int i;
    for(i=sp;i>=0;i--){
        printf("%d ",stack[i]);
    }
}
