data segment
    a db 1,2,3,4,5,6,7,8,9,10
    sum db ?
data ends                    

code segment
    assume ds:data,cs:code
    
    start:
        mov ax,data
        mov ds,ax
        mov cl,10
        lea si,a 
        mov ax,0000  
        
    l1:
        add al,[si]
        inc si
        dec cl
        cmp cl,00
        jnz l1
        mov [si],al
        mov ah,4ch
        int 21h
        
code ends 

end start