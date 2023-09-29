#include <stdio.h>

int main(void) {
	int dollar_amount;

	printf("Enter a dollar amount: ");
	scanf("%d", &dollar_amount);

	int num_twenties = dollar_amount / 20;
	dollar_amount -= num_twenties * 20;

	int num_tens = dollar_amount / 10;
	dollar_amount -= num_tens * 10;

	int num_fives = dollar_amount / 5;
	dollar_amount -= num_fives * 5;

	int num_ones = dollar_amount;

	printf("$20 bills: %d\n", num_twenties);
	printf("$10 bills: %d\n", num_tens);
	printf(" $5 bills: %d\n", num_fives);
	printf(" $1 bills: %d\n", num_ones);

	return 0;
}
