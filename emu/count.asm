;COUNT VOWELS

ASSUME CS:CODE, DS:DATA
DATA SEGMENT
    STR DB 'LAZY FOX JUMPED OVER A LOG',0
    COUNT DB 0
DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    
    LEA SI,STR
    MOV CL,0
    
    COUNTL:
    MOV AL,[SI] 
    CMP AL,0
    JE FIN
    CMP AL,'A'
    JE VOWEL 
    CMP AL,'A'
    JE VOWEL
    CMP AL,'E'
    JE VOWEL
    CMP AL,'I'
    JE VOWEL
    CMP AL,'O'
    JE VOWEL
    CMP AL,'U'
    JE VOWEL
    CMP AL,'a'
    JE VOWEL
    CMP AL,'e'
    JE VOWEL
    CMP AL,'i'
    JE VOWEL
    CMP AL,'o'
    JE VOWEL
    CMP AL,'u'
    JE VOWEL   
    
    NOT_VOWEL:
    INC SI
    JMP COUNTL
    
    VOWEL:
    INC CL
    JMP NOT_VOWEL
    
    FIN:
    MOV COUNT,CL
    MOV AH,4CH
    INT 21H
CODE ENDS
END START