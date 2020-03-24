.global weekday
.cpu cortex-a53
.text 

/*
int weekday(int month, int day, int year) {
    int y0 = year - (14 - month) / 12;
    int x = y0 + y0/4 - y0/100 + y0/400;  // leap year
    int m0 = month + 12  * ((14 - month) / 12) - 2;
    int d0 = (day + x + (31 * m0) / 12) % 7;
    return d0;
}
*/

weekday:
    push {r4}        // push r4 on to the stack, save it so we can restore it later
    mov r3, #14      // constant 14 into r3
    sub r3, r3, r0   // r3 = 14 - month
    mov r4, #12      
    sdiv r3, r3, r4  // r3 = (14 - month) / 12 
    sub r2, r2, r3

    // HW4 is to finish this function

    mov r0, r2 
    pop {r4}
    bx lr
