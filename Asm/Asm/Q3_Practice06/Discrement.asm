.386
.model flat

.code
; ----------------------------------------------
_Disc PROC
; Calculate 'discrement of ax^2+bx+c'
; REceives: [ebp + 8] = a
;			[ebp + 12] = b
;			[ebp + 16] = c
; ----------------------------------------------
push ebp; save the value of ebp
mov ebp, esp; ebp now points to the top of the stack
sub esp, 4; space allocated on the stack for the local vatiables

mov DWORD PTR[ebp - 4], -4; Local Variable X

mov eax, [ebp + 12]
mul DWORD PTR[ebp + 12]
mov ebx, eax
mov eax, [ebp + 8]
mul DWORD PTR[ebp - 4]
mul DWORD PTR[ebp + 16]
add eax, ebx
add esp, 4
pop ebp
ret

_Disc ENDP

END