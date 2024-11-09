data segment
	msg1 db 0ah,0dh,"Hai$"
data ends

code segment
assume cs:code, ds:data
start:
	mov ax, data
	mov ds, ax
	lea dx, msg1
	mov ah, 09h
	int 21h
	mov ah, 4ch
	int 21h
code ends
end start
 
