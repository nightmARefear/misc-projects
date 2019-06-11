#include <stdio.h>
#include <errno.h>

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS 0
#endif

int main()
{
    FILE *fp;
    char filename[] = "C:\\Programming\\cryptographic\\encrypted.txt";

    fp = fopen(filename, "r");
    if (!fp)
    {
        printf("\nAn error occurred: ");
        perror("", errno);
        exit(EXIT_FAILURE);
    }

    // abcdefghijklmnopqrstuvwxyz
    // a e i o u y
    char c;
    int times[6][2]; // 1st column is for the character itself {i=0, a}, {i=1, e}, etc while the 2nd is the counter for each vowel
    int i, j;
    for (j = 0; j < 6; j++)
        times[j][1] = 0;

    int counter = 0; // total vowel counter

    while (!feof(fp))
    {
        c = fgetc(fp);
        counter++;

        switch (c)
        {
        case 'a':
            times[0][1]++;
            break;

        case 'e':
            times[1][1]++;
            break;

        case 'i':
            times[2][1]++;
            break;

        case 'o':
            times[3][1]++;
            break;
        case 'u':
            times[4][1]++;
            break;

        case 'y':
            times[5][1]++;
            break;
        }
    }

    // transforming all vowel counters to % of the total vowel count
    for (i = 0; i < 6; i++)
    {
        times[i][1] = (times[i][1] / counter) * 100;
    }

    // comparing all % vowel count to each other
    int min = times[0], max = times[0];
    for (i = 1; i < 6; i++)
    {
        if (times[i] > max)
            max = times[i][1];
        else
            min = times[i][1];
    }

    /* not sure what to do next */

    return EXIT_SUCCESS;
}