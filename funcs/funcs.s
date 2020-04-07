// procedure calling conventions 

.global f,max4, randrange, array_sum
.cpu cortex-a53
.text
 
// clobber - to accidentally overwite a value

/*
int array_sum_c(int *vec, int n) {
    int sum = 0;
    int i = 0;
    
    while (i < n) {
        sum = sum + vec[i];
        i++;
    }
    return sum;
}
*/
array_sum:
    push { r4, r5 }
    mov r2, #0   // sum is in r2
    mov r3, #0   // i is in r3
    
while_array_sum:
    cmp r3, r1
    bge endloop_array_sum
    lsl r4, r3, #2   
    add r4, r0, r4
    ldr r5, [r4]
    add r2, r2, r5
    add r3, r3, #1
    b while_array_sum
endloop_array_sum:
    mov r0, r2
    pop { r4, r5 }
    bx lr


/*
    to compute x % y
    q = x/y
    r = x - qy
*/
mod:
    sdiv r3, r0, r1
    mul r3, r3, r1
    sub r0, r0, r3
    bx lr

/*
int randrange_c(int x, int y) {
    return rand() % (y - x) + x;
}
*/
randrange:
    push { r4, r5, lr }
    mov r4, r0   // save x into r4
    mov r5, r1   // save y in r5
    bl rand    
    sub r1, r5, r4
    bl mod
    add r0, r0, r4
    pop { r4, r5, lr }
    bx lr
    

    // leaf function because do not call
    // other functions and do not need to save lr
//int max4(int w, int x, int y, int z) {
//    return max(max(w, x), max(y, z));
//}

max4:
    push { r4, r5, r6, lr }
    mov r4, r2 
    mov r5, r3
    
    // must assume r2, r3 get modified by max
    bl max
    mov r6, r0     // save the return result 
    mov r0, r4     // move y and z into r0 and r1
    mov r1, r5
    bl max
    mov r1, r6
    bl max
        
    pop { r4, r5, r6, lr }
    bx lr
    
    // return abs(x) + x
g:
    push { r4, lr }

    mov r4, r0    
    bl abs     // x already in r0
    add r0, r0, r4 

    pop { r4, lr }
    bx lr
   
f:
    push { lr }     // save the link register
    bl g   // call g
    pop { lr }      // restore the link register
    
    bx lr


