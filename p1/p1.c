#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

bool findOpcode(char* op) {
    FILE *optab = fopen("optab.txt","r");
    if (optab == NULL) {
        printf("Error: Could not open optab.txt\n");
        return false;
    }
    char opcode[4];
    int hexcode;
    while(fscanf(optab,"%s %x",opcode, &hexcode)!=EOF) { 
        //printf("Checking opcode: '%s' against '%s' %x\n", opcode, op,hexcode); 
        if(strcmp(opcode, op) == 0) {
            fclose(optab);
            return true;
        }
    }
    fclose(optab);
    return false;
}
int main() {
    FILE *input,*symtab,*inter,*leng;
    input = fopen("input.txt","r");
    symtab = fopen("symtab.txt","w");
    inter = fopen("intermediate.txt","w");
    leng = fopen("length.txt","w");

    char opcode[10],label[10],operand[10];
    int locctr,start,length;

    fscanf(input,"%s %s %s",label,opcode,operand);
    if(strcmp(opcode,"START") == 0) {
        start = strtol(operand,NULL,16);
        locctr = start;
        fprintf(inter,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        printf("%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        fscanf(input,"%s %s %s",label,opcode,operand);
    }
    else
        locctr = 0;
    while(strcmp(opcode,"END") !=0 ) {
        fprintf(inter,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        printf("%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
        if(strcmp(label,"**")!=0)
            fprintf(symtab,"%s\t%x\n",label,locctr);
        
        if(findOpcode(opcode))
            locctr += 3;
        else if(strcmp(opcode,"WORD")==0)
            locctr += 3;
        else if(strcmp(opcode,"BYTE")==0) {
            int len = strlen(operand);
            if(operand[0]=='C'||operand[0]=='c') len -= 3;
            else if(operand[0]=='X'||operand[0]=='x') len = (len - 3)/2;
            locctr += len;
        }
        else if(strcmp(opcode,"RESB")==0)
            locctr+=atoi(operand);
        else if(strcmp(opcode,"RESW")==0)
            locctr += 0x3*atoi(operand);
        else
            printf("Error-Unregonized opcode %s\n",opcode);
        
        fscanf(input,"%s %s %s",label,opcode,operand);
    }
    fprintf(inter,"%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    printf("%x\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    length = locctr - start;
    fprintf(leng,"%x",length);
    fclose(input);
    fclose(inter);
    fclose(symtab);
    fclose(leng);
    return 0;
}