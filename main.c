#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Node.h"
#include "Queue.h"

int main(int argc , char **argv) {
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL; 
// For struct Queue
  Queue  q;
   q.headPtr=NULL;
   q.tailPtr=NULL;
   q.size=0;

   int i,x; 

 for(i=1;i<argc;i++){
        if(strcmp(argv[i],"x")==0){
            x=dequeue_struct(&q);
            if(x!=0)printf("dequeing %d\n",x);
        }
        else {
       enqueue_struct(&q, atoi(argv[i]));
      printf("enqeue : %d \n",atoi(argv[i]));
        }
 }
  return 0;
}
