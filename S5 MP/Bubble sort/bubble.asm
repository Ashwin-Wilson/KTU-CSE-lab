data segment
	m1 db 0ah,0dh,"enter the no of elements:$"
	m2 db 0ah,0dh,"enter the numbers:$"
	result db 0ah,0dh,"sorted string:$"
	array db 09h dup(?)
	n db ?
data ends

display macro msg
	lea dx,msg
	mov ah,09h
	int 21h
endm

readDigit macro
	mov ah,01h
	int 21h
	sub al,30h
	endm
	printDigit macro
	add dl,30h
	mov ah,02h
	int 21h
endm

code segment
assume cs:code,ds:data
start:
	mov ax,data
	mov ds,ax
	display m1
	readDigit
	mov n,al
	mov cl,n
	display m2
	mov si,offset array

read:
	readDigit
	mov[si],al
	inc si
	dec cl
	jnz read
	mov cl,n

loop1:
	mov ch,n
	mov si,offset array
	loop2: mov dl,[si]
	cmp dl,[si+1]
	jnc swap
	jmp swapped

swap:
	mov dl,[si]
	xchg dl,[si+1]
	mov [si],dl

swapped:
	inc si
	dec ch
	jnz loop2
	dec cl
	jnz loop1
	display result
	mov si,offset array
	mov cl,n
	inc si

print:
	mov dl,[si]
	printDigit
	inc si
	dec cl
	jnz print
	mov ah,4ch
	int 21h
	code ends
end start
code ends
end starts

