#include<stdio.h>
#include<stdbool.h>

void selection_sort(int n, int array[n]);

int main(void) 
{
	int max_nums;

	printf("How many numbers will you enter? ");
	scanf("%d", &max_nums);

	int nums[max_nums];

	int cur_num = 0;

	do {
		int num;
		
		printf("Enter a number: ");
		scanf("%d", &num);

		nums[cur_num] = num;

		cur_num++;
	} while (cur_num < max_nums);

	selection_sort(cur_num, nums);

	printf("Sorted numbers:\n");

	for(int i = 0; i < cur_num; i++) {
		printf("%d,", nums[i]);
	}

	printf("\n");

	return 0;
}

void selection_sort(int n, int array[n]) {
	int largest_el_idx = 0;

	for(int i = 0; i < n; i++) {
		if (array[i] > array[largest_el_idx]) {
			largest_el_idx = i;
		}
	}

	int largest_el_value = array[largest_el_idx];

	for(int i = largest_el_idx; i < n - 1; i++) {
		array[i] = array[i+1];
	}

	array[n - 1] = largest_el_value;

	if (n > 1) {
		selection_sort(n-1, array);
	}
}

