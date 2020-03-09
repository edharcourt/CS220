.global avg       // assembler directive
.cpu cortex-a53   // The cortex a53 has a divide instruction
.text             // start of the text segment (code)

avg:
    add r0,r0,r1
    add r0,r0,r2
    mov r3, #3    // constant 3 into r3
    sdiv r0,r0,r3  
    bx lr
