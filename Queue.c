#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int* arr;
};

int isEmpty(struct Queue *ptr){
    if((ptr->front)==(ptr->rear)){                // IS EMPTY
        return 1;
    }
    return 0;
}

int isFull(struct Queue *ptr){
    if((ptr->rear)-(ptr->front)==ptr->size){   // IS FULL
        return 1;
    }
    return 0;
}

void push(struct Queue *ptr,int m){
    if(isFull(ptr)){
        printf("Queue Overflow ");          // Enqueue Function
    }
    else{
        ptr->rear++;
        ptr->arr[ptr->rear]=m;
    }
}

void pop(struct Queue *ptr){
    if(isEmpty(ptr)){
        printf("Queue Underflow");           //Dequeue function
    }
    else{
        ptr->front++;
        int val=ptr->arr[ptr->front];
        printf("%d  ",val);
    }
}

int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=-1;
    q->rear=-1;
    q->size=10;
    q->arr=(int*)calloc(q->size,sizeof(int));
    for(int i=0;i<10;i++){
        push(q,i);
    }
    printf("\n");
    for(int i=0;i<10;i++){
        pop(q);
    }
}
