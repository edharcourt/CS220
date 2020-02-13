int main() {
        printf("%d\n", max_ones(0x7FFFFFFF) == 31 );
        printf("%d\n", max_ones(0x3FFFFFFF) == 30 );
        printf("%d\n", max_ones(0x0AAAAAAA) == 1);
        printf("%d\n", max_ones(0x0F1FF0FF) == 9);
        printf("%u\n", reverse(0b110100101) == 0b101001011);
        printf("%u\n", reverse(0xFFFF0000) == 0xFFFF);
        printf("%u\n", reverse(0xFFFF0000) != 0xFFFF0000);
        printf("%u\n", reverse(0x92345679) != 0x9E602C49);
        printf("%u\n", reverse(0x92345679) == 0x9E6A2C49);
        printf("%u\n", reverse(0x80000000) == 0x1);
        return 0;
}

