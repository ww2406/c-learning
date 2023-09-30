#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include<ctype.h>

#define N_DIE_SIDES 6

int roll_dice(void);
bool play_game(void);

int main(void)
{
	srand((unsigned) time(NULL));
	
	int num_wins = 0, num_loss = 0;

	char play_again = 'N';

	do {
		bool won_game = play_game();

		if (won_game) 
			num_wins++; 
		else 
			num_loss++;

		printf("You %s!\n", won_game ? "won" : "lost");

		printf("Play again (Y/N)? ");
		scanf(" %c", &play_again);
	} while (toupper(play_again) == 'Y');

	printf("Wins: %d \t Losses: %d\n", num_wins, num_loss);
}

int roll_dice(void)
{
	int first_die = rand() % N_DIE_SIDES;
	int second_die = rand() % N_DIE_SIDES;

	int dice_sum = first_die + second_die;

	printf("You rolled: %d\n", dice_sum);

	return dice_sum;
}

bool play_game(void)
{
	int dice_sum = roll_dice();

	if (dice_sum == 7 || dice_sum == 11) return true;
	if (dice_sum == 2 || dice_sum == 3 || dice_sum == 12) return false;

	printf("Your point is %d\n", dice_sum);

	while(dice_sum != 7) {
		int new_dice_sum = roll_dice();

		if (new_dice_sum == dice_sum) return true;
		if (new_dice_sum == 7) return false;

		dice_sum = new_dice_sum;
	}

	return false;
}
