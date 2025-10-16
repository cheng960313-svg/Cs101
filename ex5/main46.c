#include <stdio.h>

void toh (int n , char from_rod,char to_rod, char aux_rod){
    if(n==1){
        printf("\n move disk 1 from %c to rod %c",from_rod,to_rod);
        return;
    }
    toh(n-1,from_rod,aux_rod,to_rod);
    printf("\n move disk %d form reod%c to rod %c",n,from_rod,to_rod);
    toh(n-1,aux_rod,to_rod,from_rod);
}
int main()
{
    int n=3;
    toh(n,'A','B','C');
    return 0;
}
