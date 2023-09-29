#include <stdio.h>

int main(void) {
	float loan_balance, interest_rate, monthly_pmt;

	printf("Enter amount of loan: ");
	scanf("%f", &loan_balance);

	printf("Enter interest rate: ");
	scanf("%f", &interest_rate);
	interest_rate = interest_rate / 100 / 12;

	printf("Enter monthly payment: ");
	scanf("%f", &monthly_pmt);

	loan_balance = (loan_balance - monthly_pmt) + (loan_balance * interest_rate);
	printf("Balance remaining after first payment: $%.2f\n", loan_balance);

	loan_balance = (loan_balance - monthly_pmt) + (loan_balance * interest_rate);
	printf("Balance remaining after second payment: $%.2f\n", loan_balance);

	loan_balance = (loan_balance - monthly_pmt) + (loan_balance * interest_rate);
	printf("Balance remaining after third payment: $%.2f\n", loan_balance);

	return 0;
}
