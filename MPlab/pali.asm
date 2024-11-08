data segment
	msg1 db 0ah,0dh,"enter the string:$"
	msg2 db 0ah,0dh,"the string is palindrome:$"
	msg3 db 0ah,0dh,"the string is not palindrome:$"
	str1 db 50 dup("?")
data ends

display macro msg
	mov ah,09h
	lea dx,msg
	int 21h
endm

code segment
assume cs:code,ds:data
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
	dec si
	lea di,str1

loop3:
	mov bl,[di]
	mov al,[si]
	cmp al,bl
	jnz loop4
	inc di
	dec si
	dec cx
	jnz loop3
	display msg2
	jmp loop5

loop4:
	display msg3

loop5:
	mov ah,4ch
	int 21h
code ends
end start

