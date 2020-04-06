.global slowpow
.text

/*
int slowpow(int x, int y) {
    if (y == 0)
        return 1;
    else 
        return x * slowpow(x, y - 1);
}
*/
slowpow:
    push { r4, r5, lr}
    mov r4, r0   // save x
    mov r5, r1   // save y
    
    cmp r1, #0
    bne else
    mov r0, #1
    pop { r4, r5, lr }
    bx lr
        
else:
    mov r0, r4
    sub r1, r5, #1
    bl slowpow
    mul r0, r4, r0
    
    pop { r4, r5, lr }
    bx lr

