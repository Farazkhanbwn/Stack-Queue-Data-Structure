#include <stdio.h>
#include <stdlib.h>

struct ArrayQueue
{
    int front,rear;
    int capacity;
    int *array;
};

struct ArrayQueue* createQueue(int cap){
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q) 
      return (NULL);
    Q->capacity = cap;
    Q->front = Q->rear = -1;
    Q->array = malloc(sizeof (int) * Q->capacity);
    if(!Q->array)
      return (NULL);
    return Q;
}

int isEmptyQueue(struct ArrayQueue *Q){
  return (Q->front==-1);
}

int isFullQueue(struct ArrayQueue *Q){
  return ((Q->rear+1)%Q->capacity==Q->front);
}

int QueueSize(struct ArrayQueue *Q){
  if (isEmptyQueue(Q)){
    return(0);
  }
  else if(Q->capacity>3){
    return ((Q->capacity-Q->front+Q->rear+1)%Q->capacity+1);
  }
  return ((Q->capacity-Q->front+Q->rear+1)%Q->capacity);
}
// Insertion
void enQueue(struct ArrayQueue *Q , int data){
  if(isFullQueue(Q))
    printf("Overflow");
  else
  {
    Q->rear = (Q->rear+1) % Q->capacity;
    Q->array[Q->rear]=data;
    if(Q->front==-1)
      Q->front=Q->rear;
  }
}

// Deletion
int deQueue(struct ArrayQueue *Q){
  int data=-1;
  if(isEmptyQueue(Q))
  {
    printf("Queue is Empty");
    return(-1);
  }
  else
  {
    data=Q->array[Q->front];
    if(Q->front==Q->rear)
      Q->front=Q->rear=-1;
    else
      Q->front=(Q->front+1)%Q->capacity;
  }
  return data;
}

// Delete Queue
void deleteQueue(struct ArrayQueue *Q){
  if(Q)
  {
    if(Q->array){
      free(Q->array);
    }
    free(Q);
  }
}

int main(){
    int choice , item;
    struct ArrayQueue *Q;
    Q = createQueue(4);
    while(1){
        system("clear");
        printf("\n1 insert");
        printf("\n2 Delete");
        printf("\n3 QueSize");
        printf("\n4 QueDelete");
        printf("\n5 Exit");
        printf("\nEnter Your Choice");
        scanf("%d" ,&choice);
        switch(choice)
        {
            case 1:
                printf("\nEnter a number");
                scanf("%d" , &item);
                enQueue(Q , item);
                break;
                
            case 2:
                item = deQueue(Q);
                if(item == -1)
                    printf("\nQueue is Empty");
                else
                    printf("\nDeleted value is %d" , item);
                break;
          
            case 3:
                item = QueueSize(Q);
                printf("\nSize of Queue is %d" , item);
                break;
          
            case 4:
                printf("\nQueue is Deleted");
                deleteQueue(Q);
                exit(0);
                
            case 5:
                exit(0);  
                
        }
        getchar();
    }
}