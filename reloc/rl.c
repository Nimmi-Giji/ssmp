#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char bit[30];
char bitmask[20];

void convert(char mask[]) {
    int len = strlen(mask);
    strcpy(bit,"");
    for(int i = 0 ; i < len ; i++) {
        switch(mask[i]) {
            case '0': strcat(bit,"0000");break;
            case '1': strcat(bit,"0001");break;
            case '2': strcat(bit,"0010");break;
            case '3': strcat(bit,"0011");break;
            case '4': strcat(bit,"0100");break;
            case '5': strcat(bit,"0101");break;
            case '6': strcat(bit,"0110");break;
            case '7': strcat(bit,"0111");break;
            case '8': strcat(bit,"1000");break;
            case '9': strcat(bit,"1001");break;
            case 'A': strcat(bit,"1010");break;
            case 'B': strcat(bit,"1011");break;
            case 'C': strcat(bit,"1100");break;
            case 'D': strcat(bit,"1101");break;
            case 'E': strcat(bit,"1110");break;
            case 'F': strcat(bit,"1111");break;
            default: break;
        }
    }
}
int main() {
    FILE *obj;
    int start,addr,modif,bin=0,add,len,i;
    char rec[20],name[20],first[3],second[5];
    scanf("%x",&start);
    addr = start;
    obj = fopen("relinput.txt","r");
    fscanf(obj,"%s",rec);
    if(strcmp(rec,"H")==0){
        fscanf(obj,"%s",name);
        fscanf(obj,"%x",&add);
        fscanf(obj,"%x",&len);
    }
    else
        exit(1);
    strcpy(rec,"");
    fscanf(obj,"%s",rec);
    while(strcmp(rec,"E")!=0){
        if(strcmp(rec,"T")==0){
            fscanf(obj,"%x",&add);
            fscanf(obj,"%x",&len);
            fscanf(obj,"%s",bitmask);
            add += start;
            bin=0;
            convert(bitmask);
            fscanf(obj,"%s",rec);
        }
        if(bit[bin] == '1') {
            for(i = 0; i < 6; i++) {
                if(i<2) first[i] = rec[i];
                else second[i-2] = rec[i];
            }

            first[2] = second[4]='\0';
            modif = strtol(second,NULL,16);
            modif += start;
            printf("%X\t%s%x\n",add,first,modif);
        }
        else
            printf("%X\t%s\n",add,rec);

        add += 3;
        bin++;
        fscanf(obj,"%s",rec);
    }
}