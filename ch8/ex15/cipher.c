#include<stdio.h>
#include<stdbool.h>

#define MAX_LEN 80

int main(void)
{
	char msg[MAX_LEN];
	int shift_amt;

	printf("Enter message to be encrypted: ");
	
	int chars_read = 0;
	do {
		char ch;
		scanf("%c", &ch);

		if (ch == '\n') break;

		msg[chars_read] = ch;
		chars_read++;
	} while (chars_read < MAX_LEN);

	printf("Enter shift amount (1-25): ");
	scanf("%d", &shift_amt);

	for(int i = 0; i < MAX_LEN; i++) {
		int base_letter = 'a';

		if (msg[i] >= 'A' && msg[i] <= 'Z') {
			base_letter = 'A';
		}
		
		if ('A' <= msg[i] && msg[i] <= 'z') { 
			msg[i] = (msg[i] + shift_amt - base_letter) % 26 + base_letter;
		}
	}

	printf("Encrypted message: %s\n", msg);

	return 0;
}
