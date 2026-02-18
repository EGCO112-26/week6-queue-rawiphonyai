#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Order.h"

char *menuName[] = {"Ramen", "Fried Chicken", "Burger"};
int menuPrice[] = {200, 100, 300};


int main(int argc , char **argv){

    Queue q;
    initQueue(&q);

    int orderCounter = 1;

    int served = 0;
    for(int i=1;i<argc;i++){
      
        if(strcmp(argv[i],"x")==0){
          if(q.size == 0){
             printf("Queue is empty (มีคิวว่าง)\n");
          } else {
              serveCustomer(&q, menuName, menuPrice);
              served++;
          }
        }

        else{
          int menu = atoi(argv[i]);
          enqueue(&q, menu, menuPrice[menu-1], orderCounter++, menuName);
        }
    }

    while(served < 4){
      if(q.size == 0){
          printf("Queue is empty (มีคิวว่าง)\n");
          break;
      }
      serveCustomer(&q, menuName, menuPrice);
      served++;
    }

    printf("---------------------------------\n");
    printf("The shop is now closed. Only 4 queues are served per day.\n");
    printf("There are %d ppl left in queue\n", q.size);
    clearQueue(&q);
    
    return 0;
    }