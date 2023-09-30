#include<stdio.h>
#include<stdbool.h>

#define MAX_NUMS 5

void selection_sort(int n, int array[n]);

int main(void) 
{
	int nums[MAX_NUMS];

	int cur_num = 0;

	do {
		int num;
		
		printf("Enter a number: ");
		scanf("%d", &num);

		nums[cur_num] = num;

		cur_num++;
	} while (cur_num < MAX_NUMS);

	selection_sort(cur_num + 1, nums);

	for(int i = 0; i < cur_num + 1; i++) {
		printf("Sorted numbers:\n");
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

	for(int i = n - 1; i > largest_el_idx; i--) {
		array[i-1] = array[i];
	}

	array[n - 1] = largest_el_value;

	selection_sort(n-1, array);
}

