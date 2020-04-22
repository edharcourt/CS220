.global f2c
.cpu cortex-a53
.fpu neon-vfpv4 // Neon is the Vector instruction processor
                // vfp - vector floating-point, v4 version 4 (??)
                
.text

// Separate set of 16 double precision registers, d0 - d15.
// d0 - d7 caller saved registers. The function can use them at will 
// but they can be clobbered on a function call. (similar to r0 - r3
// general purpose registers).
// d8 - d15 callee saved registers.  The function can use them but 
// must save and restore for the caller. (similar r4 - r12 general
// purpose registers).
// d0 - first floating-point argument and also the floating-point
// return value
// d1 - d3 - reaming floating point arguments

/*
double f2c(double f) {
    return 5.0/9.0 * (f - 32.0);
}
*/
f2c:
    vmov.f64 d1, #5.0    // vmov (vector move)
    vmov.f64 d2, #9.0
    vdiv.f64 d1, d1, d2  // 5/9
    // vmov.f64 d2, #32.0   // assembler doesn't like 32
    
    // load the address of thirtytwo into a general purpose register
    ldr r0, =thirtytwo
    vldr.f64 d2, [r0]    // read 32.0 from memory
    
    vsub.f64 d2, d0, d2  // f - 32
    vmul.f64 d0, d1, d2
    bx lr

.align 3  // start the stuff that comes next on 
          // and address that is divisible by 8  (2^3)
          // start the double precision number on an 8 byte boundary
.data     // put some data in the "data memory"
thirtytwo: .double 32.0

     
