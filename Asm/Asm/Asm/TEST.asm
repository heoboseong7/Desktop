TITLE Practice 02 - 04

INCLUDE Irvine32.inc

.data
Value DWORD ?

.code
main PROC

call DumpRegs
mov eax, Value
call DumpRegs
mov eax, 0AAAAAAAAh
call DumpRegs

exit
main ENDP
END main
