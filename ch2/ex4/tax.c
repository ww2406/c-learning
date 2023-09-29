#include <stdio.h>

#define TAX_RATE 0.05

int main(void) {
	float entered_amount;

	printf("Enter an amount: ");
	scanf("%f", &entered_amount);

	printf("With tax added: $%.2f \n", entered_amount + (entered_amount * TAX_RATE));

	return 0;
}
