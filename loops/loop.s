.global f
.cpu cortex-a53 
.text

/*
    int i = 0;
    while (i < 5) {
        i++;
    }
    
*/

f:
    mov r0, #0
while:
    cmp r0, #5      // i < 10, sets CPSR
    beq endloop
    add r0, r0, #1   // incrementing i
    b while    
endloop:
    bx lr            // puts the value of the link register in to the 
                     // program counter PC
                     // PC contains the adress the curently executing instruction

/*
  r0 = 0,1,2,3,4,5,6,7,8,9,10
*/


    
