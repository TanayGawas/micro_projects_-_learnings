// FUNCTIONS DECLERATIONS AND CONSTANTS

#ifndef ENCDEC_H
#define ENCDEC_H

//#define INPUT_FILEPATH "/home/tanay/IITMESD/C_mini_project/data/input.txt"
//#define ENC_FILEPATH "/home/tanay/IITMESD/C_mini_project/data/encrypted.enc"
//#define OUTPUT_FILEPATH "/home/tanay/IITMESD/C_mini_project/data/output.txt"



//FUNCTION DECLERATIONS
//void xor(FILE *fptri, FILE *fptro,char k);
//void encrypt(FILE *fptri,FILE *fptro,char p);
//void decrypt(FILE *fptri,FILE *fptro, char p);

typedef struct opr{
int val;
const char* inpath;
const char* outpath;
}crypto;


enum{
E=0,
D=1
};

int encrypt(const char *inpath, const char *encpath);
int decrypt(const char *encpath, const char *outpath);

#endif