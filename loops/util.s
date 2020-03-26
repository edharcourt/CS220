.global max
.text

/*
int max(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
        
}
*/
max:
      cmp r0, r1
      ble else
      bx lr 
else:
      mov r0, r1
      bx lr
