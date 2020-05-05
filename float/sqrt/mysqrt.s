.global mysqrt
.fpu neon-vfpv4
.cpu cortex-a53
.text

/*
double mysqrt(double n) {
    const double epsilon = 1e-6;
    double r = n;
    
    while (fabs(r*r - n) > epsilon)
        r = (r + n/r)/2.0;
        
    return r;
}
*/

mysqrt:
    push { lr }
    vpush { d8, d9, d10, d11 }
    
    vmov.f64 d8, d0        // n is in d8
    vmov.f64 d9, #2.0
    ldr r0, =epsilon
    vldr.f64 d10, [r0]
    vmov.f64 d11, d8       // r = n
    
while:
    vmul.f64 d0, d11, d11
    vsub.f64 d0, d0, d8
    bl fabs
    vcmp.f64 d0, d10   // the floating point status register was set
                       // we need to copy it to the integer status register
                       // nzvc - negative, zero, overflow, carry bits
    vmrs APSR_nzvc, FPSCR
    ble endwhile
    vdiv.f64 d0, d8, d11
    vadd.f64 d0, d0, d11
    vdiv.f64 d11, d0, d9
    b while
    
endwhile:
    vmov.f64 d0, d11
    vpop { d8,d9,d10,d11 }
    pop { lr }
    bx lr
    
    
    

.align 3
.data
epsilon: .double 1.0e-6
