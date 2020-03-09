
int weekday(int month, int day, int year) {
    
    int y0 = year - (14 - month) / 12;
    int x = y0 + y0/4 - y0/100 + y0/400;  // leap year
    int m0 = month + 12  * ((14 - month) / 12) - 2;
    int d0 = (day + x + (31 * m0) / 12) % 7;
    return d0;
}