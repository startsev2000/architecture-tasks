# Команды для компиляции, компоновки и запуска в gdb
# as --gstabs -o asm-hello-world.o asm-hello-world.s
# gcc asm-hello-world.o -o asm-hello-world
# ./hello
#------------------------------------------------

    .intel_syntax noprefix
    .section .rodata
msg:
    .string      "hello, world!\n"
    .equ    msgLen, .-msg-1

    .text               # Code
    .globl main
    .type   main, @function
main:
    mov     rax, 1          # 1 = write
    mov     rdi, 1          # 1 = to stdout
    lea     rsi, msg[rip]   # string to display in rsi
    mov     rdx, msgLen     # length of the string, without 0
    syscall                 # display the string

    mov     rax, 60         # 60 = exit
    mov     rdi, 0          # 0 = success exit code
    syscall                 # quit
