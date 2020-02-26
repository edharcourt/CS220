/*
 * Pointer exercises
 *
 */

int main() {

    int i = 12;
    
    // Declaration p to be a pointer to an int
    int * p = &i;

    

    // which of the following are aliases of i

    *p   // yes
    &p   // no
    *&p  // *(&p)  same as p, is not i
    &*p  // &(*p)  same as p, not i
    *i   // error, crash, seg fault
    &i   // address of i, not i
    *&i  // yes, alias
    &*i  // crash, seg fault, bye bye because of *i

    // p and q are pointers to an int
    int *p, *q;

    p = i;   // not OK, but can force the issue if needed 
    *p = &i; //
    printf("%X\n", p);  // 0XA0192400
    printf("%d\n, *p);
    &p = q;  // can't change where cxompiler put p
             // can't the address of o
    q = &p;  // not okay q is a pointer to an int which 
             // is differnt than &p which is a pointer to a 
             // pointer to an int

    p = *&q; // OK
    p = q;   // OK
    p = *q;  // not OK, assigning int to pointer
    *p = q;  // not OK, same reason
    *p = *q;
}

