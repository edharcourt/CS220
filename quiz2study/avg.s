	.text
	.global	avg
	.cpu cortex-a53
avg:
	add	r0, r0, r1
	add	r0, r0, r2
        mov r3, #3
        sdiv    r0,r0,r3    
	bx	lr
