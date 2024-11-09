assume cs:code,ds:data

data segment
	msg1 db 0ah,0dh,"enter the string :$"
	msg2 db 0ah,0dh,"the reverse is :$"
	str1 db 20 dup("?")
	rev db 20 dup("?")
data ends

display macro msg
	mov ah,09h
	lea dx,msg
	int 21h
endm

code segment
start:
	mov ax,data
	mov ds,ax
	display msg1
	mov cx,0000h
	lea si,str1

loop1:
	mov ah,01h
	int 21h
	mov [si],al
	cmp al,0dh
	je loop2
	inc si
	inc cx
	jmp loop1

loop2:
	mov bl,"$"
	mov [si],bl
	mov di,si
	lea si,rev
	dec di

loop3:
	mov bl,[di]
	mov [si],bl
	dec di
	inc si
	dec cx
	jnz loop3
	mov bl,"$"
	mov [si],bl
	display msg2
	display rev
	mov ah,4ch
	int 21h

code ends
end start

