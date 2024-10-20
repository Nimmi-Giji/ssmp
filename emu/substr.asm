;SUBSTRING

ASSUME CS:CODE,DS:DATA
DATA SEGMENT
    STR DB 'MALAYALAM$',0
    SUBS DB 'MES$',0
    FOUNDSTR DB 'FOUND$',0
    NOTFOUNDSTR DB 'NOT FOUND$',0
DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    MOV ES,AX
    
    LEA SI,STR
    LEA DI,SUBS
    
    SEARCH:
    PUSH SI
    PUSH DI
    
    COMPARE:
    MOV AL,[SI]
    MOV BL,[DI] 
    
    CMP BL,'$'
    JE FOUND
    
    CMP AL,BL
    JNE NOMATCH
    INC SI
    INC DI 
    JMP COMPARE    
    
    NOMATCH:
    POP DI
    POP SI
    INC SI
    CMP BYTE PTR [SI] ,'$'
    JE NOTFOUND 
    CMP BYTE PTR [SI] ,0
    JE NOTFOUND
    JMP COMPARE
    
    FOUND:
    LEA DX,FOUNDSTR
    MOV AH,09H
    INT 21H
    JMP FIN
    
    NOTFOUND:
    LEA DX,NOTFOUNDSTR
    MOV AH,09H
    INT 21H
    JMP FIN
    
    FIN:
    MOV AH,4CH
    INT 21H
CODE ENDS
END START