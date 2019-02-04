#include <stdio.h>
#include <stdlib.h>

const int BUFFER_AMOUNT = 512;
int main(int argc, char *argv[])
{
    if (argc != 2) // make sure for the number of arguments
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    FILE* myfile = fopen(argv[1], "r");  // create a file pointer with reading mode
    if (myfile == NULL) // ensure for valid file
    {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return 2;
    }

    unsigned char *buffer = malloc(BUFFER_AMOUNT);  //create a heap memory for the bytes
    int count = 0;
    FILE *jpag;
    while (fread(buffer , BUFFER_AMOUNT, 1, myfile)) // check for the end of the card
    {
        if ( buffer[0] == 0xff &&
             buffer[1] == 0xd8 &&
             buffer[2] == 0xff &&
             (buffer[3] & 0xf0) == 0xe0) // check for the header of the ipag
             {
                 if (count != 0)
                 {
                     fclose(jpag);  // close the current working jpag if it is not the first jpag
                 }
                 char filename[8];
                 sprintf(filename, "%03i.jpg", count); // create the name of the jpag sequently
                 jpag = fopen(filename,"w");

                 if (!jpag)  // check if jpg file is successfully created
                 {

                     fclose(myfile);
                     free(buffer);
                     fprintf(stderr, "Could not create output JPG %s", filename);
                     return 3;
                 }

                 count ++;
             }
        if (!count)  // if first jpg is not yet found, skip
        {
            continue;
        }

        // write jpg info into current file
        fwrite(buffer, BUFFER_AMOUNT, 1, jpag);

    }

    fclose(myfile);
    fclose(jpag);
    free(buffer);  //avoiding memory leak by freeing the memory used
    return 0;
}