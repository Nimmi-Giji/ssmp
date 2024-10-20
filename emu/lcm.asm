;LCM
ASSUME CS:CODE,DS:DATA

DATA SEGMENT
    OP1 DB 7 
    OP2 DB 18
    LCM DB ?
DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    
    MOV AX,0000H
    MOV DL,00H
    MOV BH,OP1
    MOV BL,OP2
    
    RPT:
    ADD DL,BH
    MOV AH,0
    MOV AL,DL
    DIV BL
    CMP AH,00H
    JNZ RPT
    
    
    MOV LCM,DL
    MOV AH,4CH
    INT 21H
    
CODE ENDS
END START
    