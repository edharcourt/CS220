.global scale
.text

/*
void scale(int *vec, int n, int s) {
    int i = 0;
    
    while (i < n) {
        vec[i] = vec[i]*s;
        i++;
    }
}
*/

scale:
    push { r4, r5 }
    
    mov r3, #0   // i = 0
while:
    cmp r3, r1
    bge endwhile
    lsl r5, r3, #2
    add r5, r0, r5   // r5 = r0 + i*4
    ldr r4, [r5]
    mul r4, r4, r2
    str r4, [r5]   
    add r3, r3, #1
    b while
endwhile:
    pop { r4, r5 }
    bx lr
