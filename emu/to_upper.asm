;CONVERSION

ASSUME CS:CODE, DS:DATA
DATA SEGMENT
    INP DB 'HELLO$',0   
    OUP DB ?
DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS, AX
    
    LEA SI,INP 
    LEA DI,OUP
    
    CONVERT: 
    MOV AL,[SI]
    CMP AL,0
    JE DISPLAY
    CMP AL,'A'
    JB NEXT
    CMP AL,'Z'
    JA NEXT
    ADD AL,20H
    NEXT:
    MOV [DI],AL
    INC DI
    INC SI
    JMP CONVERT
    
    DISPLAY:
    LEA DX,OUP
    MOV AH,09H
    INT 21H
    
    MOV AH,4CH
    INT 21H
CODE ENDS
END START
    