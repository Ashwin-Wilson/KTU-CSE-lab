data segment 
	msg1 db 0ah, 0dh, "Enter string: $"
	msg2 db 0ah, 0dh, "Sorted string : $"
	msg3 db 0ah, 0dh, "Enter length : $"
	n1 db 09h dup(?)
	n db ?
data ends

display macro msg
	lea dx, msg
	mov ah, 09h
	int 21h
endm

readDigit macro
	mov ah, 01h
	int 21h
	sub al, 30h
endm

printDigit macro
	add dl, 30h
	mov ah, 02h
	int 21h
endm

code segment
assume cs:code, ds:data
start:
	mov ax, data
	mov ds, ax
	mov si, offset n1
	display msg3
	readDigit 
	mov n, al
	mov cl, n
	display msg1
readString:
	readDigit
	mov [si], al
	inc si
	dec cl
	jnz readString
	mov cl,n
loop1: 
	mov si, offset n1
	mov ch, n
	loop2:
		mov dl, [si]
		cmp dl, [si+1]
		jnc swap
		jmp swapped
		swap:
			mov dl, [si]
			xchg dl, [si+1]
			mov [si], dl
		swapped:
			inc si
			dec ch
			jnz loop2
	dec cl
	jnz loop1
	mov si, offset n1
	inc si
	mov cl, n
	display msg2
result: 
	mov dl, [si]
	printDigit
	inc si
	dec cl
	jnz result
	mov ah, 4ch
	int 21h
	
code ends
end start
