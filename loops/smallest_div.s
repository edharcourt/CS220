.global smallest_div
.cpu cortex-a53
.text

/*
int smallest_div(int n) {
     int i = 2;
     
     while (n % i != 0) {  // when i = 5?
         i = i + 1;
     } 
     return i;
}

Computing x % y   q = x / y      r = x - qy
*/
smallest_div:
    mov r1, #2
while:
    sdiv r2, r0, r1   // r2 = n / i
    mul r2, r2, r1    // r2 = r2*y
    sub r2, r0, r2    // r2 = r0 - r2
    cmp r2, #0
    beq endloop
    add r1, r1, #1
    b while
endloop:
    mov r0, r1        // put return value in r0
    bx lr
    
    
