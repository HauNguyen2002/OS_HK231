#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
	return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
    if (q->size > MAX_QUEUE_SIZE);
    else {
        q->proc[q->size++] = proc;
    }
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
    if (empty(q) != 1) {
        struct pcb_t* pri_max_proc=q->proc[0];
        int pri_max=q->proc[0]->prio;
        int pri_index=0;
        for(int i=1;i<q->size;i++){
        	if(q->proc[i]->prio<pri_max){
        		pri_max=q->proc[i]->prio;
        		pri_index=i;
        		pri_max_proc=q->proc[i];
        	}
        }
        for(int i=pri_index;i<q->size-1;i++){
        	q[i]=q[i+1];
        }
        q->size--;
        q->proc[q->size-1]=NULL;
        return pri_max_proc;
    }
	return NULL;
}

