.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

push ebp
mov ebp, esp

mov eax, [ebp + 8]
shr eax, 6

and eax, 1h
jz isZero
jmp _exit

isZero:
mov eax, [ebp + 12]
and eax, 7h
mov ecx, eax
mov eax, [ebp + 16]
and eax, 01FFh
cmp ecx, eax
ja _exit
pop ebp
mov eax, 1
ret

_exit:
pop ebp
mov eax, 0
ret

IsValidAssembly ENDP

END
