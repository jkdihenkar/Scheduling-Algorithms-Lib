typedef struct process {
  int pid;
  int arr_time;
  int burst_time;
  int over;
  struct process* next;
}process;

typedef process *pptr;
