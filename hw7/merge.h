
/*
 * merge vec1 and vec2 into a new ordered array. 
 * precondition: vec1 and vec2 must already be ordered.
 *     n1 and n2 are the lengths of vec1 and vec2 and should be 
 *     non-negative.
 * 
 * merge allocates memory using malloc. The caller must
 * be responsible for cleaning it up.
 * 
 */
extern int *merge(int *vec1, int n1, int *vec2, int n2);
