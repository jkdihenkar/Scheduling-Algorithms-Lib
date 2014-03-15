/*
    Problem Defination : Implementation if First Come First Serve (FCFS) Sched. algorith.

    Input : file:"./input"

    Output : On stdout ( Standard Output Console)
                --file://"./write" Finish time of the processes
                --file://"./trace" Entire Trace of the algorithm

    Compiling : file://"./run" Script file

    Special Notes : FCFS Algorith Implementation
                    -- Dynamically allocated pid
                    -- Dynamic process entries rather to statics

    Dependencies :  process.h   Structure of process stamp's Header as Include
                    preq.h      Header as pre-requisites for the queue implementation
                    preq.c      Implementation of pre-requisites! ;) --may need optimization

    To solve for additional functionality : file://"./trace" --not implemented! (Don't 'cat' it)

    Implementation by : Jay Dihenkar! ( ;) )
                        date : 8th March 2014
                        guide : Mr. Hasmukh Rathod
                            Proffesor, Computer Science and Engineering
                            Parul Institue of Enginnering and Technology,
                            Baroda.

*/

#include<stdio.h>
#include<stdlib.h>
#include"preq.h"

static int g_pid=100;

FILE *write;
FILE *trace;

//first come first serve
void fcfs(pptr head,pptr tail);
//sort queue
//void sortqueue(pptr* head,pptr*tail);


int main() {

  pptr head=NULL;
  pptr tail=NULL;
  int i=0;
  int tpid,tarr_time,tburst_time;
  pptr tprocess;
  FILE *read;
  read=fopen("input","r");
  write=fopen("write","w");
  trace=fopen("trace","w");
  for(i=1;i<=3;i++) {
    //fscanf(read,"%d",&tpid);
    tpid=++g_pid;
    fscanf(read,"%d",&tarr_time);
    fscanf(read,"%d",&tburst_time);
    tprocess=create_process(tpid,tarr_time,tburst_time);
    add_to_queue(&head,&tail,tprocess);
  } fclose(read);

  fcfs(head,tail);



  return 0;


}


//fcfs algorithm -- no text referred developed from self logic : Jay Dihenkar
//date : 8th March 2014.
void fcfs(pptr head,pptr tail) {

pptr s_head=NULL;
pptr s_tail=NULL;
pptr auxnode;

int global_time=0;

start: while(head!=NULL && head->arr_time==global_time) {
auxnode = fetch_from_queue(&head,&tail);
add_to_queue(&s_head,&s_tail,auxnode);
}
if(s_head==NULL) {
    if(head==NULL) { //all process are served we exit
            fclose(write);
            filecopy(stdout,trace);
            fclose(trace);
        return;
    }
    //else it's empty slot but still processes to come
    printf("\nThe time slot at %d to %d is free slot!",global_time,global_time+1);
//    fprintf(trace,"\nThe time slot at %d to %d is free slot!",global_time,global_time+1);
    goto end_of_loop;
}
//else s_head not null and hence we serve the head process...
s_head=serve(s_head,1); //serve for 1 time slot
//check if the process has burst
if(checkfinish(s_head)) {
        printf("\n\t\t\t\tFinish time for pid:%d is %d!",s_head->pid,global_time);
//        fprintf(trace,"\n\t\t\t\tFinish time for pid:%d is %d!",s_head->pid,global_time);
        fprintf(write,"\nFinish time for pid:%d is %d!",s_head->pid,global_time);
    fetch_from_queue(&s_head,&s_tail);
}
end_of_loop:global_time++;
if(global_time>=100) { return;
}
goto start;


}

