
global start

start:
mov rax, 201
xor rdi, rdi
syscall

mov rdi, rax
extern testing
call testing

xor rdx, rdx
mov rcx, 85000
mov r9, rax
div rcx
mov rax, rdx
xor rdx, rdx
mov rcx, 60
div rcx
mov rax, rdx

    