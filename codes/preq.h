#include"process.h"
//create the new process
pptr create_process(int tpid,int tarr_time,int tburst_time);
//insert in global queue -- the input queue that is the input from given
void add_to_queue(pptr* head,pptr* tail,pptr c_process);
//insert into sched queue
void add_sched_queue(pptr* s_head,pptr* s_tail,pptr c_process);
//fetch process from the sched queue's top
pptr fetch_from_queue(pptr* head,pptr* tail);
//the process is served with cpu for certain duration
pptr serve(pptr c_process,int duration);
//check is theprocess is over
int checkfinish(pptr c_process);
//print process details
void display(pptr c_process);

//file functionality function
void filecopy(FILE* from,FILE* to);
