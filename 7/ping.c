#include<stdio.h>
#include<stdlib.h>

main(){
int ping_ret,status;

status=system("ping -w 3 192.168.1.3");
if(status!= -1)
ping_ret= WEXITSTATUS(status);
printf("%d",ping_ret);

return 0;

}
