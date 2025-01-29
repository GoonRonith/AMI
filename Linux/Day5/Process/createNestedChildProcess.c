// #include <unistd.h>
// #include <sys/types.h>
// #include <stdio.h>

// int main() {
//     pid_t q;
//     printf("\nbefore fork");
//     fflush(stdout); 
    
//     q = fork();
    
//     if (q < 0) {
//         printf("\nError creating child process");
//     } 
//     else if (q == 0) {
//         printf("\nI am child process and my PID: %d", getpid());
//         printf("\nI am child process and my parent's PID: %d", getppid());
//         pid_t x=fork();
//         if(x<0){
//             printf("\nError in creating child process of processId:%d",getpid());
//         }
//         else if(x==0){
//             printf("\nI am Nested child process and my PID: %d", getpid());
//         printf("\nI am Nested child process and my nested parent's PID: %d", getppid());
//         }
//         else{
//             printf("\nI am Nested Parent process and my PID: %d", getpid());
//             printf("\nI am Nested Parent process and my nested child's PID: %d", x);
//         }
//     } 
//     else {
//         printf("\nI am parent process and my PID: %d", getpid());
//         printf("\nI am parent process and my child's PID: %d", q);
//     }
    
//     return 0;
// }
// #include<stdio.h>
// #include<unistd.h>
// #include<sys/types.h>
// #include<stdlib.h>

// int main(){
// pid_t p;
// printf("befor fork\n");
// p=fork();
// if(p==0)
// {
// pid_t q;
// printf("Inside first fork\n");
// q=fork();
// if(q==0)
// {
// printf("Iam 2ndchild having id %d\n",getpid());
// printf("My parent  id is %d\n",getppid());
// }
// printf("Iam child havinf is is %d\n",getpid());
// printf("My parent id is %d\n",getppid());
// }
// else{
// printf("My child id is %d\n",p);
// printf("Iam parent having id %d\n",getpid());
// }
// printf("common\n");
// }