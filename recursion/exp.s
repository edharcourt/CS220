.global slowpow, fastpow
.text

/*
int fastpow(int x, int y) {
    if (y == 0)   // base case 
        return 1;
    else if (y & 1)  // odd case
        return x * fastpow(x, y - 1);
    else {
        int tmp = fastpow(x, y >> 1);   // even case
        return tmp*tmp;
    }
}
*/
fastpow:
    push { r4, r5, lr }
    mov r4, r1   // save y in r4
    mov r5, r0   // save x in r5
    
    cmp r1, #0
    bne else_odd
    mov r0, #1
    pop { r4, r5, lr }
    bx lr
     
else_odd:
    and r2, r1, #1   // if (y & 1)
    cmp r2, #1
    bne else_even
    sub r1, r4, #1   
    mov r0, r5
    bl fastpow
    mul r0, r5, r0 
    pop { r4, r5, lr }
    bx lr
else_even:
    lsr r1, r4, #1
    mov r0, r5
    bl fastpow
    mul r0, r0, r0   // return tmp*tmp
    pop { r4, r5, lr }
    bx lr
    


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

