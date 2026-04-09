.386
.model flat, C

.code

; Complete the procedure
IsValidAssembly PROC

push ebp
mov ebp, esp

mov eax, [ebp + 8]		; Acessing the first argument
shr eax, 6				; Shifting the bits so that it is easier to apply a mask

and eax, 1h				; Applying the mask
jz isZero				; if ZF is 1 then the value of the first argument at position 6(ID[3]) was zero
jmp _exit				; Otherwise, the first condition is not fulfilled and the program exits with code 0 

isZero:
mov eax, [ebp + 12]		; Copying the second argument into eax
and eax, 7h				; Applying the mask via the AND operation to obtain the value of the 3(ID[0]) LSBs
mov ecx, eax			; Copying the result to ecx
mov eax, [ebp + 16]		; Copying the third argument into eax
and eax, 01FFh			; Applying the mask via the AND operation to obtain the value of the 9(ID[2] + 1) LSBs
cmp ecx, eax
jae _exit				; Exiting with code 0 if value at ecx is not less than eax
pop ebp
mov eax, 1
ret

_exit:
pop ebp
mov eax, 0
ret

IsValidAssembly ENDP

END
