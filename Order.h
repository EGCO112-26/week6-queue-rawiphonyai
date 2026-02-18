#ifndef ORDER_H
#define ORDER_H

#include <stdio.h>
#include <stdlib.h>


typedef struct order {
    int menu_id;
    int price;
    int order_number;
    struct order *next;
} Order;

typedef struct {
    Order *head;
    Order *tail;
    int size;
} Queue;


void initQueue(Queue *q){
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void enqueue(Queue *q, int menu_id, int price, int order_number, char *menuName[]){

    Order *newNode = (Order*)malloc(sizeof(Order));
    newNode->menu_id = menu_id;
    newNode->price = price;
    newNode->order_number = order_number;
    newNode->next = NULL;

    if(q->head == NULL){
        q->head = q->tail = newNode;
    }
    else{
        q->tail->next = newNode;
        q->tail = newNode;
    }

    q->size++;

}

Order* dequeue(Queue *q){

    if(q->head == NULL)
        return NULL;

    Order *temp = q->head;
    q->head = q->head->next;

    if(q->head == NULL)
        q->tail = NULL;

    q->size--;
    return temp;
}

void clearQueue(Queue *q){

    while(q->head != NULL){
        Order *temp = dequeue(q);
        free(temp);
    }
}

void serveCustomer(Queue *q, char *menuName[], int menuPrice[]){

    Order *customer = dequeue(q);

    if(customer == NULL){
        printf("Queue is empty\n");
        return;
    }
    printf("My order is %s\n", menuName[customer->menu_id - 1]);
    printf("Customer no. : %d\n", customer->order_number);
    printf("Serving Order #%d\n", customer->order_number);
    printf("Menu: %s\n", menuName[customer->menu_id - 1]);
    printf("Price: %d Baht\n", customer->price);

    int money = 0;

    do{
        printf("Enter money: ");
        scanf("%d", &money);

        if(money < customer->price){
            printf("Not enough money! Please pay at least %d\n", customer->price);
        }

    }while(money < customer->price);

    int change = money - customer->price;

    printf("Change: %d Baht\n", change);
    printf("Thank you!\n\n");

    free(customer);
}

#endif