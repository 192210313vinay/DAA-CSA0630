#include <stdio.h>
int power(int base, int exp) {
    if (exp == 0)
        return 1;
    else
        return base * power(base, exp - 1);
}
int countDigits(int n) {
    if (n == 0)
        return 0;
    else
        return 1 + countDigits(n / 10);
}
int sumOfDigitsRaisedToPower(int n, int p) {
    if (n == 0)
        return 0;
    else
        return power(n % 10, p) + sumOfDigitsRaisedToPower(n / 10, p);
}
int isArmstrong(int n) {
    int p = countDigits(n);
    return n == sumOfDigitsRaisedToPower(n, p);
}
int main() {
    int number;

    printf("Enter a number: ");
    scanf("%d", &number);

    if (isArmstrong(number))
        printf("%d is an Armstrong number.\n", number);
    else
        printf("%d is not an Armstrong number.\n", number);

    return 0;
}

