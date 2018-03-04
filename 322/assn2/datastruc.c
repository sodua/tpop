#include <stdio.h>

int main(void)
{
    int cities = 5;
    int source = 1;
    struct record
    {
        int source;
        int dest;
        double avgtime;
    };
    
    struct record myrecord[cities]; 
    myrecord[source].source = 1;
    myrecord[source].dest = 5;
    myrecord[source].avgtime = 5.22;

    printf("%d %d %5.2lf", myrecord[1].source, myrecord[1].dest, myrecord[1].avgtime);
    return 0;
}
