// LOGIC FOR ENCRYPTION AND DECRYPTION
#include "../inc/encdec.h"
#include <stdio.h>
#include <string.h>

//LOGIC TO ENCRYPT
int encrypt(const char *inpath,const char *encpath)
{
    char pass[10];
    printf("ENTER THE PASSWORD TO ENCRYPT\n\t1. LESS THAN 10 CHARACTERS:\n\t2. NO SPACES ALLOWED\nPASSWORD: ");
    scanf("%s",pass);

    FILE *fptri=NULL, *fptrenc=NULL;

    fptri=fopen(inpath,"r");
    fptrenc=fopen(encpath,"w");
    if(fptrenc==NULL || fptri==NULL)
    {
        if(fptrenc==NULL)
        {
            fprintf(stderr,"failing to create o/p file");
        }
        else {
        fprintf(stderr,"file to encrypt");
        }
        return 1;

    }
            int i=0;

    while(pass[i]!='\0')
    {
        fprintf(fptrenc,"%c",(pass[i])^(pass[0]));
        i++;
    }

    fprintf(fptrenc,"\n");

    char ch;
    while(fscanf(fptri,"%c",&ch) == 1)
    {
        fprintf(fptrenc,"%c",ch^pass[0]);
    }

    fclose(fptrenc);
    fclose(fptri);
    fprintf(stdout,"ENCRYPTED SUCCESFULLY at %s",encpath);
    return 0;

}

//LOGIC TO DECRYPT
int decrypt(const char *encpath, const char *outpath)
{

    FILE *fptrenc=NULL;

    char pass[10];
    char encpass[10];
    printf("ENTER THE PASSWORD TO VERIFY: ");
    scanf("%s",pass);

    fptrenc=fopen(encpath,"r");
    if(fptrenc==NULL)
    {
        fprintf(stderr,"file to decrypt");
        return 1;
    }
    int i=0;
    char ch;
    while((ch=fgetc(fptrenc))!='\n')
    {
        encpass[i]=ch^pass[0];
        i++;
    }
    encpass[i]='\0';

    if(strcmp(pass, encpass)!=0)
        return 2;

    FILE *fptro=fopen(outpath,"w");
    if(fptro==NULL)
    {
        fprintf(stderr,"failing to create outputfile");
        return 1;
    }
    while(fscanf(fptrenc,"%c",&ch) == 1)
    {
        fprintf(fptro,"%c",ch^pass[0]);
    }

    fclose(fptrenc);
    fclose(fptro);
    fprintf(stdout,"DECRYPTED SUCCESFULLY at %s",outpath);
    return 0;

}

