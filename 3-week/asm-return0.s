# asm-retun0.s
# Минимальная программа на ассемблере в стиле языка C.
    .intel_syntax noprefix  # используется синтаксис Intel
    .text
    .globl  main
    .type   main, @function
main:
    push    rbp        	# сохранение указателя на кадр вызывающей подпрограммы
    mov     rbp, rsp    # формирование своего указателя кадра стека

    mov     eax, 0      # return 0;

    mov     rsp, rbp    # восстановление указателя стека
    pop     rbp         # восстановление кадар вызывающей подпрограммы
    ret                 # возврат в вызывающую подпрограмму
