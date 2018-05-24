.386
.model flat

.code
; ----------------------------------------------
_Func PROC
; Calculate 'Ax+Bx+C'
; REceives: [ebp + 8] = x
;			[ebp + 12] = y
; ----------------------------------------------
push ebp; save the value of ebp
mov ebp, esp; ebp now points to the top of the stack
sub esp, 12; space allocated on the stack for the local vatiables

mov DWORD PTR[ebp - 4], 2; Local Variable A
mov DWORD PTR[ebp - 8], 4; Local Variable B
mov DWORD PTR[ebp - 12], 8; Local Variable C

mov eax, [ebp + 8]
mul DWORD PTR[ebp - 4]
mov ebx, eax
mov eax, [ebp + 12]
mul DWORD PTR[ebp - 8]
add eax, ebx
sub eax, [ebp - 12]
add esp, 12
pop ebp
ret
_Func ENDP

END