#include <stdio.h>

int main(void) 
{
	float commission, price_per_share, trade_value;
	int num_shares;

	printf("Enter number of shares: ");
	scanf("%d", &num_shares);

	printf("Enter price per share: $");
	scanf("%f", &price_per_share);

	trade_value = num_shares * price_per_share;

	if (trade_value < 2500.00f) {
		commission = 30.0f + 0.017f * trade_value;
	} else if (trade_value < 6250.00f) { 
		commission = 56.00f + 0.0066f * trade_value;
	} else if (trade_value < 20000.00f) {
		commission = 76.00f + 0.0034f * trade_value;
	} else if (trade_value < 50000.00f) {
		commission = 100.00f + 0.0022f * trade_value;
	} else if (trade_value < 500000.00f) {
		commission = 155.00f + 0.0011f * trade_value;
	} else {
		commission = 255.00f + 0.0009f * trade_value;
	}

	if (commission < 39.00f) {
		commission = 39.00f;
	}

	printf("Commission: $%.2f\n", commission);

	return 0;
}
