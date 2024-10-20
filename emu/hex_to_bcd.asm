;HEX TO BCD

ASSUME CS:CODE, DS:DATA
DATA SEGMENT
    HEX DW 0FFFFH
    BCD DW 5 DUP(0)
DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX  
    
    LEA SI,BCD
    
              
    XOR DX,DX          
    MOV AX,HEX
    
    MOV CX,2710H
    DIV CX
    MOV [SI],AX
    INC SI 
    MOV AX,DX
    
    XOR DX,DX
    MOV CX,03E8H
    DIV CX
    MOV [SI],AX
    INC SI 
    MOV AX,DX
    
    XOR DX,DX
    MOV CX, 0064H
    DIV CX
    MOV [SI],AX
    INC SI 
    MOV AX,DX 
    
    XOR DX,DX
    MOV CX, 000AH
    DIV CX
    MOV [SI],AX
    INC SI 
    MOV [SI],DX 
    
    MOV AH,4CH
    INT 21H
CODE ENDS
END START