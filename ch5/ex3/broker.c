#include <stdio.h>

#define RIVAL_BASE_COMMISSION 33.0f

int main(void) 
{
	float commission, price_per_share, trade_value, rival_commission;
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

	if (num_shares < 2000) {
		rival_commission = RIVAL_BASE_COMMISSION + 0.03f * num_shares;
	} else {
		rival_commission = RIVAL_BASE_COMMISSION + 0.02f * num_shares;
	}

	printf("Commission: $%.2f\n", commission);
	printf("Rival commission: $%.2f\n", rival_commission);

	return 0;
}
