#include <stdio.h>


int ReverseNumber(int num, int reversedNum) {
    if (num == 0) 
        return reversedNum;
    else {
        return ReverseNumber(num / 10, reversedNum * 10 + num % 10);
    }
}

int main() {
    int num = 12345; 
    int reversedNum = ReverseNumber(num, 0); 

    printf("Original number: %d\n", num);
    printf("Reversed number: %d\n", reversedNum);

    return 0;
}

