// PROGRAM ENTRY, ARGUMENT PARSING
#include<string.h>
#include<stdio.h>
#include"../inc/encdec.h"


void help()
{
    fprintf(stdout,"\n run --help to get more info");
}
// to select files from user and mode : ENCRYPT OR DECRYPT
int main(int argc, const char *argv[])
{
    crypto task;

    if(argc==2 && strcmp(argv[1],"--help")==0)
    {
        fprintf(stdout,"USE: to encrypt text file to .enc and .enc back to test\n using password used for encryption by the user who encrypted \n\n");
        fprintf(stdout,"\tFORMAT\n\t <executabel_name> <flag(-e or -d) file1 file 2\n\t");
        fprintf(stdout,"encryptyion: file 1-> .txt file 2-> .enc\n\t");
        fprintf(stdout,"decryptyion: file 1-> .enc file 2-> .txt\n");
        fprintf(stdout,"INPUT FILE IS NECCESSARY with EXACT EXTENSION TYPE");
        return 0;
    }

    //MORE OR LESS ARGUMENT
    if(argc!=3 )  // .exe  <-e or -d> <file1path to encrypt> <output>
    {
        if(argc>4)
        {
            fprintf(stderr,"too many arguments");
            help();
            return 1;
        }

        if(argc<3)
        {
            fprintf(stderr,"not enough arguments");
            help();
            return 1;
        }
    }


    // to check the flag
    if(strcmp(argv[1],"-d")==0)
    {
        task.val=D;
    }
    else if(strcmp(argv[1],"-e")==0)
    {
        task.val=E;
    }
    else {
        fprintf(stderr,"invalid flag options : -e and -d");
        help();
        return 1;
    }

    // check if input file exist
    FILE *fptr=fopen(argv[2],"r");
    if(fptr==NULL)
    {
        fprintf(stderr,"the input file does not exist");
        return 1;
    }





    fclose(fptr);

    task.inpath=argv[2];

    // to select path for
    if(argv[3]==NULL)
    {

        if(task.val==E)
        {
            task.outpath="encrypted.enc";
        }
        else {
            task.outpath="output.txt";
        }

    }
    else
        task.outpath=argv[3];

    int ch;

    switch(task.val)
    {
        case E:
        if(encrypt(task.inpath,task.outpath)==1)
            fprintf(stderr,"file not opening error");
        break;

        case D:

        if((ch=decrypt(task.inpath,task.outpath))==1)
            fprintf(stderr,"file not opening error");

        if(ch ==2)
            fprintf(stderr,"WRONG PASSWORD FOR DECRYPTION");

        break;

    }

}