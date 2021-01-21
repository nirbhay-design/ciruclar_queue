#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define FOR(i,a,n) for(int i=a;i<=n;i++)


typedef struct circularq{
    int len;
    int front;
    int rear;
    int * arr;
}CQ;

int isempty(CQ * cq){
    if(cq->front==-1 || cq->rear ==-1){
        return 1;
    }
    return 0;
}
int isfull(CQ*cq){
    if(cq->front == (cq->rear+1)%cq->len){
        return 1;
    }
    return 0;
}
void enqueue(CQ * q,int element){
    if(isfull(q)){
        printf("the queue is full \n");
    }else if(isempty(q)){
        q->front = 0;
        q->rear = 0;
        q->arr[q->rear] = element;
    }else{
        q->rear = (q->rear + 1)%q->len;
        q->arr[q->rear] = element;
    }
}

int qfront(CQ * cq){
    return cq->arr[cq->front];
}
int dequeue(CQ * cq){
    if(isempty(cq)){
        printf("the queue is empty \n");
    }else if(cq->front == 0 && cq->rear == 0){
        cq->front = -1;
        cq->rear = -1;
    }
    else{
        cq->front = (cq->front+1)%cq->len;
    }
}
void printcq(CQ *cq){
    if(isempty(cq)){
        printf("the queue is empty \n");
    }else{
        int a = cq->front;
        int b = cq->rear;
        while(a!=b){
            printf("%d ",cq->arr[a]);
            a = (a+1)%cq->len;
        }
        printf("%d ",cq->arr[a]);
    }
    
    printf("\n");
}

int main(){

    CQ * q = (CQ* )malloc(sizeof(CQ));
    q->front = -1;
    q->rear = -1;
    q->len = 5;
    q->arr = (int *)malloc(q->len*sizeof(int));


    enqueue(q,56);
    enqueue(q,6);
    enqueue(q,5);
    enqueue(q,560);
    enqueue(q,856);
    enqueue(q,576);
    enqueue(q,576);
    dequeue(q);
    dequeue(q);
    enqueue(q,10);
    printcq(q);


    return 0;

}