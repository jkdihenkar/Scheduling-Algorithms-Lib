#include<stdio.h>
#include<stdlib.h>
#include"preq.h"

void display(pptr cprocess) {

  printf("Process Id : %d\tArr_Time : %d\tBurst Time : %d\n",cprocess->pid,cprocess->arr_time,cprocess->burst_time);

}

void add_to_queue(pptr* head,pptr* tail,pptr cprocess) {
    //clone and add...
    pptr auxnode;
    auxnode = (pptr) malloc(sizeof(process));
    auxnode->pid=cprocess->pid;
    auxnode->arr_time=cprocess->arr_time;
    auxnode->burst_time=cprocess->burst_time;
    auxnode->over=cprocess->over;
    auxnode->next=NULL;
  if(*head == NULL) {
    *head = cprocess;
    *tail = cprocess;
    return;
  }
  (*tail)->next=cprocess;
  (*tail)=cprocess;
  return;
}

pptr create_process(int tpid,int tarr_time,int tburst_time) {
  pptr temp;
  temp = (pptr) malloc(sizeof(process));
  temp->pid = tpid;
  temp->arr_time=tarr_time;
  temp->burst_time=tburst_time;
  temp->over=0;
  temp->next=NULL;
  return temp;
}

void add_sched_queue(pptr* s_head,pptr* tail,pptr c_process){}
//fetch process from the sched queue's top
pptr fetch_from_queue(pptr* head,pptr* tail){
pptr auxnode = (*head);
(*head) = (*head)->next;
if((*head) == NULL) {
    (*tail) = NULL;
}
return auxnode;
}
//the process is served with cpu for certain duration
pptr serve(pptr c_process,int duration) {
    printf("\nThe process : pid : %d is served for %d duration",c_process->pid,duration);
    c_process->burst_time-=duration;
    printf("\nRemaining time for pid:%d to burst is %d",c_process->pid,c_process->burst_time);
return c_process;
}
//check is theprocess is over
int checkfinish(pptr c_process) {
if(c_process->burst_time == 0) {
        printf("\nThe process %d has burst!",c_process->pid);
    return 1;
} return 0;
}

void filecopy(FILE* from,FILE* to) {
    int c;
    while((c=getc(from))!=EOF) {
        putc(c,to);
    }
}
