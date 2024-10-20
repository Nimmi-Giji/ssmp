#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int findOpcode(char* op) {
    FILE *optab = fopen("optab.txt","r");
    if (optab == NULL) {
        printf("Error: Could not open optab.txt\n");
        return -1;
    }
    char opcode[4];
    int hexcode;
    while(fscanf(optab,"%s %x",opcode, &hexcode)!=EOF) {  
        if(strcmp(opcode, op) == 0) {
            fclose(optab);
            return hexcode;
        }
    }
    fclose(optab);
    return -1;
}
int findSym(char* op) {
    FILE *symtab = fopen("symtab.txt","r");
    if (symtab == NULL) {
        printf("Error: Could not open optab.txt\n");
        return -1;
    }
    char label[15];
    int addr;
    while(fscanf(symtab,"%s %x",label, &addr)!=EOF) {  
        if(strcmp(label, op) == 0) {
            fclose(symtab);
            return addr;
        }
    }
    fclose(symtab);
    return -1;
}

int main() {
    FILE *inter, *object, *final, *length;
    inter = fopen("intermediate.txt","r");
    object = fopen("objcode.txt","w");
    length = fopen("length.txt","r");
    final = fopen("final.txt","w");

    char label[15], opcode[5], operand[10];
    int locctr,len,addr,sa;
    fscanf(length,"%x",&len);

    fscanf(inter,"%x %s %s %x",&addr,label,opcode,&sa);
    if(strcmp(opcode,"START") == 0)
        fprintf(final,"%x\t%s\t%s\t%x",addr,label,opcode,sa);
    fprintf(object,"H^%6s^%06x^%06x",label,sa,len);
    fscanf(inter,"%x %s %s %s",&addr,label,opcode,operand);
    fprintf(object,"\nT^%06x^%x",addr,len);

    while(strcmp(opcode,"END")!=0){
        int hexcode = findOpcode(opcode);
        char hex[7]="";
        if(hexcode!=-1) {
            sprintf(hex, "%02X", hexcode);
            if(strcmp(operand,"**")!=0) {
                int loc = findSym(operand);
                char temp[5]="";
                sprintf(temp,"%04X",loc);
                strcat(hex,temp);
            }
            else
                strcat(hex,"0000");
        }
        else if(strcmp(opcode,"BYTE")==0 || strcmp(opcode,"WORD")==0) {
            if(strcmp(opcode,"WORD")==0)
                fprintf(object,"^00000%s",operand);
            else {
                len=strlen(operand);
                for(int i=2;i<len-1;i++) {
                    char asciiHex[3];
                    sprintf(asciiHex, "%02X", (unsigned char)operand[i]); 
                    strcat(hex, asciiHex); 
                }   
            }
        }
        if(strcmp(hex,"")!=0)
            fprintf(object,"^%s",hex);
        fscanf(inter,"%x %s %s %s",&addr,label,opcode,operand);
    }
    fprintf(object,"\nE^00%x",sa);
    fclose(inter);
    fclose(object);
    fclose(length);
    fclose(final);
    return 0;
}