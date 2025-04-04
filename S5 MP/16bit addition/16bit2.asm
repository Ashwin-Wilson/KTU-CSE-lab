data segment
	msg1 db 0ah,0dh,"first no$"
	msg2 db 0ah,0dh,"second no$"
	msg3 db 0ah,0dh,"result$"
	n1 db 07h dup(?)
	n2 db 07h dup(?)
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
	mov si,offset n1
	mov di,offset n2
	display msg1
	mov cl,04h
	
	first:
		readDigit
		mov [si],al
		inc si
		dec cl
		jnz first
		display msg2
		mov cl,04h
	second:
		readDigit
		mov [di],al
		inc di
		dec cl
		jnz second
		clc
		mov cl,04h
	addition:
		dec di
		dec si
		mov al,[si]
		mov bl,[di]
		adc al,bl
		mov ah,00h
		aaa
		mov [di],al
		dec cl
		jnz addition
		display msg3
		mov cl,04h
	print:
		mov dl,[di]
		printDigit
		inc di
		dec cl
		jnz print
		mov ah,4ch
		int 21h
	code ends
end start
	

