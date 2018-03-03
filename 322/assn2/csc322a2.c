#include <stdio.h>

void readfile(int numlines, char *line, FILE** readFile);
int countlines(char *fileName, FILE** countFile);

int main(int argc, char *argv[])
{
    FILE *fp_in, *fp_count;
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
        /* fp_out = fopen(argv[2], "w"); */

        if (fp_in == NULL)
        {
            printf("Error: Cannot open input file [%s].\n", argv[1]);
            return 1;
        }
        
   }

return 0;
}

void readfile(int numlines, char *fileName, FILE** readFile)
{
    char buff[255];
    int i, cities, source, dest;
    double avgtime;
    
    printf("Number of lines in file: %d\n", numlines);
    fgets(buff, 255, *readFile);
    sscanf(buff, "%d", &cities);
    printf("Number of cities: %d\n", cities);

    for (i = 0; i < numlines; ++i)
    {
        fgets(buff, 255, *readFile);
        sscanf(buff, "%d %d %lf", &source, &dest, &avgtime);
        printf("Source: %d Destination: %d Time: %lf\n", source, dest, avgtime);
    }

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

    return lines;
}
