
/*
 * 
 *   1 2 3 4 5 -> scale 2 -> 2 4 6 8 10
 */

void scale(int *vec, int n, int s) {
    int i = 0;
    
    while (i < n) {
        vec[i] = vec[i] * s;
        i++;
    }
}
