.global weekday
.cpu cortex-a53
.text

/*
 *  y0 = y - (14 - m)/12
 *  x = y0 + y0/4 - y0/100 + y0/400
 *  m0 = m + 12 * ((14 - m) / 12) - 2
 *  d0 = (d + x + (31 * m0) / 12) % 7
 * 
 *  On which day did Feb 14, 2000 fall
 *
 *  y0 = 2000 - 1 = 1999
 *  x = 1999 + 1999 / 4 - 1999 / 100 + 1999 / 400 = 2483
 *  m0 = 2 + 12(1) - 2 = 12
 *  d0 = (14 + 2483 + (31*12)/12) % 7 = 2528 % 7 = 1 (Monday)
 */

weekday:
     // r0 - day, r1 - month, r2 - year

    // calculate y0
    mov r3, #14       // hold the constant 14
    mov r5, #12
    mov r9, #100
    mov r10, #400
    sub r4, r3, r1    // r4 = 14 - m 
    sdiv r4, r4, r5   // r4 is (14-m)/12 
    sub r6, r2, r4    // r6 is y0 
    
	// calculate x
	lsr r7,r6,#2      // r7 is y0/4
    sdiv r8,r6,r9     // r8 = y0/100
    sdiv r11,r6,r10   // r10 not needed any longer
    add  r10, r6, r7  // r7 no longer needed  
    sub r10, r10, r8  
    add r10, r10, r11 // x = y0 + y0/4 - y0/100 + y0/400 

    // only need r4, r5, r0, r1, r2
	// calculate m0
    mul r6, r5, r4    // r6 = 12 * ((14-m)/12)
    add r6, r1, r6    // r6 = m + r6
    sub r6, r6, #2    // m0 = r6
    
    // only need r10, r6, r2, r5
	// calculate d0
    mov r8, #7
    mov r9, #31
    mul r9, r9, r6
    sdiv r9, r9, r5 
    add r9, r9, r10
    add r9, r9, r1 
    
    // numerator in r9, denominator in r8
    // r = x % y, q = x / y, r = x - qy
    sdiv r1, r9, r8
    mul r1, r1, r8
    sub r0, r9, r1
    bx lr
        

