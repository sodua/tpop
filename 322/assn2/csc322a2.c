#include <stdio.h>

void readfile(int numlines, char *line, FILE** readFile);
int countlines(char *fileName, FILE** countFile);

int main(int argc, char *argv[])
{
    FILE *fp_in, *fp_out, *fp_count;
    int lines = 0;

    if (argc < 2)
	{
        printf("Usage: csc322a2 <infile> [<outfile>]\n");
        return 1;
    }

    if (argc == 2)
    {
        fp_in = fopen(argv[1], "r");
        
        if (fp_in == NULL)
        {
            printf("Error: Cannot open input file [%s].\n", argv[1]);
            return 1;
        }

        
        if (fp_in == NULL)
        {
            printf("Error: Cannot open input file [%s].\n", argv[1]);
            return 1;
        }

        fp_count = fopen(argv[1], "r");
        lines = countlines(argv[1], &fp_count); 
        readfile(lines, argv[1], &fp_in);
    }

    if (argc > 2)
    {
        fp_in = fopen(argv[1], "r");
        fp_out = fopen(argv[2], "r+");

        if (fp_in == NULL)
        {
            printf("Error: Cannot open input file [%s].\n", argv[1]);
            return 1;
        }
        if (fp_out == NULL)
        {
            printf("Error: Cannot open output file [%s].\n", argv[2]);
            return 1;
        }

        fp_count = fopen(argv[1], "r");
        lines = countlines(argv[1], &fp_count); 
        readfile(lines, argv[1], &fp_in);
   }

return 0;
}

void readfile(int numlines, char *fileName, FILE** readFile)
{
    char buff[255];
    int i, cities, source, dest;
    int errorFound;
    int validTransactions = 0;    
    double avgtime;
    
    printf("Number of routes in file: %d\n", numlines);
    fgets(buff, 255, *readFile);
    sscanf(buff, "%d", &cities);
    printf("%d\n", cities);
    double route[cities][1];
    int passes[cities];
    for (i = 0; i <= cities; ++i)
    {
        passes[i] = 0;
    }
    for (i = 0; i <= cities; ++i)
    {
        route[i][0] = 0;
    }

    for (i = 0; i < numlines; ++i)
    {
        errorFound = 0;
        fgets(buff, 255, *readFile);
        sscanf(buff, "%d %d %lf", &source, &dest, &avgtime);
        printf("%d %d %5.2f", source, dest, avgtime);
        if (source < 1 || source > cities)
        {
            printf(" Error: Invalid source city.");
            errorFound = 1;
        }
        if (errorFound == 0 && (dest < 1 || dest > cities))
        {
            printf(" Error: Invalid destination city.");
            errorFound = 1;
        }
        if (errorFound == 0 && source == dest)
        {
            printf(" Error: Duplicated source and destination.");
            errorFound = 1;
        }
        if (errorFound == 0 && avgtime <= 0)
        {
           printf(" Error: Invalid time.");
           errorFound = 1;
        }
        printf("\n");

        if (errorFound == 0)
        {
            ++validTransactions;
            route[source][dest] += avgtime;
            ++passes[source];
            route[source][dest] = (route[source][dest] / passes[source]);
            printf("From city %d to city %d: %f (%d)\n", source, dest, route[source][dest], passes[source]);
        }
    }
    printf("\n%d\n\n", validTransactions);
    fclose(*readFile);
}

int countlines(char *fileName, FILE** countFile)
{
    char ch;
    int lines = 0;
    
    while (!feof(*countFile))
    {
        ch = fgetc(*countFile);
        if (ch == '\n')
        {
            lines++;
        }
    }

    return lines - 1;
}
