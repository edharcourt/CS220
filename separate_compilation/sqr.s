.global sqr

// function sqr. First argument gets pass
// in r0.
// functions returns their result in r0 as well.

sqr:    // sqr is a label. labels an instruction

    mul r0, r0, r0

    // we need to return to the caller
    bx lr  // branch and exchange putting the link 
           // register into the program counter.
