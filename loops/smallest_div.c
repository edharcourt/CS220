
// Write a function that takes an integer n and returns the 
// smallest integer that divides n that is greater than 1.

// smallest_div(4) == 2
// smallest_dv(33) == 3
// smallest_div(13) == 13    
int smallest_div(int n) {
     
     int i = 2;
     
     while (n % i != 0) {
         i = i + 1;
     } 
    
}
