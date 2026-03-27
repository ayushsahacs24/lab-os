#include <stdio.h>
struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int pr;
    int ct;
    int tat;
    int wt;
};
int main() {
int n, time = 0, completed = 0, min_pr, shortest;
printf("Enter number of processes: ");
scanf("%d", &n);
struct Process p[n];
for(int i = 0; i < n; i++) {
    printf("\nProcess %d\n", i+1);
    p[i].pid = i+1;
    printf("Arrival Time: ");
    scanf("%d", &p[i].at);
    printf("Burst Time: ");
    scanf("%d", &p[i].bt);
    printf("Priority: ");
    scanf("%d", &p[i].pr);
    p[i].rt = p[i].bt;
}
while(completed < n) {
    min_pr = 9999;
    shortest = -1;
    for(int i = 0; i < n; i++) {
        if(p[i].at <= time && p[i].rt > 0) {
            if(p[i].pr < min_pr) {
                min_pr = p[i].pr;
                shortest = i;
    }
}
}
if(shortest == -1) {
    time++;
    continue;
}
p[shortest].rt--;
time++;
if(p[shortest].rt == 0) {
    completed++;
    p[shortest].ct = time;
    p[shortest].tat = p[shortest].ct - p[shortest].at;
    p[shortest].wt = p[shortest].tat - p[shortest].bt;
}
}
printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
for(int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
    p[i].pid, p[i].at, p[i].bt, p[i].pr,
    p[i].ct, p[i].tat, p[i].wt);
}
    return 0;
}