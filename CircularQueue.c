#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int* arr;
};

// Enqueue function for circular queue
void Enqueue(struct Queue *ptr,int m){
    if(((ptr->rear+1)%ptr->size==ptr->front&&ptr->front!=0||ptr->rear==ptr->size-1&&ptr->front==0)){
        printf("Queue is full! Cannot enqueue %d to the queue", m);
    }
    else{
        ptr->rear=(ptr->rear+1)%ptr->size;
        ptr->arr[ptr->rear]=m;
    }
}

void Dequeue(struct Queue *ptr){
    if(ptr->front==ptr->rear+1){
        printf("Queue is empty! Cannot dequeue from the queue");
    }
    else{
        
        int val=ptr->arr[ptr->front];
        ptr->front=(ptr->front+1)%ptr->size;
        printf("%d  ",val);
    }
}

void display(struct Queue *ptr){
    int i=ptr->front+1;
    printf("\n");
    while(i!=(ptr->rear+1)%ptr->size){
        printf("%d  ",ptr->arr[i]);
        i=(i+1)%ptr->size;
    }
}

int main(){
    struct Queue *q=(struct Queue*)malloc(sizeof(struct Queue));
    q->front=0;
    q->rear=-1;
    q->size=4;
    q->arr=(int*)calloc(q->size,sizeof(int));
    // Dequeue(q);
    Enqueue(q,1); 
    Enqueue(q,13); 
    Enqueue(q,2);
    printf("\n");
    Dequeue(q);
    Dequeue(q);
    printf("\n");
    Enqueue(q,4);
    Enqueue(q,2);
    Enqueue(q,7);
    printf("\n");
    display(q);
}
