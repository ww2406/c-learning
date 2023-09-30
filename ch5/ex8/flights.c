#include<stdio.h>
#include<stdbool.h>

int main(void)
{
	int hours, minutes;

	printf("Enter a 24-hour time: ");
	scanf("%d:%d", &hours, &minutes);

	// make sure the entries are valid
	if (hours < 0 || hours > 23) {
		printf("You entered an invalid hour. Please run the program again.\n");
		return 1;
	}

	if (minutes < 0 || minutes > 59) {
		printf("You entered invalid minutes. Please run the program again.\n");
		return 1;
	}

	int mins_midnight = hours * 60 + minutes;

	// represents the departure and arrival times in minutes since midnight

	// flight 1
	int flight1_depart = 480; // 8:00 AM
	int flight1_arrive = 616; // 10:16 AM
	int flight1_depart_hours = 8;
	int flight1_depart_mins = 0;
	int flight1_arrive_hours = 10;
	int flight1_arrive_mins = 16;

	// flight 2
	int flight2_depart = 583; // 9:43 AM
	int flight2_arrive = 712; // 11:52 AM
	int flight2_depart_hours = 9;
	int flight2_depart_mins = 43;
	int flight2_arrive_hours = 11;
	int flight2_arrive_mins = 52;

	// flight 3
	int flight3_depart = 679; // 11:19 AM
	int flight3_arrive = 811; //  1:31 PM
	int flight3_depart_hours = 11;
	int flight3_depart_mins = 19;
	int flight3_arrive_hours = 13;
	int flight3_arrive_mins = 31;

	// flight 4
	int flight4_depart = 767; // 12:47 PM
	int flight4_arrive = 900; //  3:00 PM
	int flight4_depart_hours = 12;
	int flight4_depart_mins = 47;
	int flight4_arrive_hours = 15;
	int flight4_arrive_mins = 0;

	// flight 5
	int flight5_depart = 840; // 2:00 PM
	int flight5_arrive = 968; // 4:08 PM
	int flight5_depart_hours = 14;
	int flight5_depart_mins = 0;
	int flight5_arrive_hours = 16;
	int flight5_arrive_mins = 8;

	// flight 6
	int flight6_depart = 945;  // 3:45 PM
	int flight6_arrive = 1075; // 5:55 PM
	int flight6_depart_hours = 15;
	int flight6_depart_mins = 45;
	int flight6_arrive_hours = 17;
	int flight6_arrive_mins = 55;

	// flight 7
	int flight7_depart = 1140; // 7:00 PM
	int flight7_arrive = 1280; // 9:20 PM
	int flight7_depart_hours = 19;
	int flight7_depart_mins = 0;
	int flight7_arrive_hours = 21;
	int flight7_arrive_mins = 20;

	// flight 8
	int flight8_depart = 1305; //  9:45 PM
	int flight8_arrive = 1438; // 11:58 PM
	int flight8_depart_hours = 21;
	int flight8_depart_mins = 45;
	int flight8_arrive_hours = 23;
	int flight8_arrive_mins = 58;
	
	// find closest departing flight not earlier than provided time
	int closest_depart_hours, closest_depart_mins, closest_arrive_hours, closest_arrive_mins;

	if (mins_midnight > flight8_depart) {
		// missed the last flight
		printf("You missed the last flight.\n");
		return 0;
	} else if (mins_midnight > flight7_depart) {
		closest_depart_hours = flight8_depart_hours;
		closest_depart_mins = flight8_depart_mins;
		closest_arrive_hours = flight8_arrive_hours;
		closest_arrive_mins = flight8_arrive_mins;
	} else if (mins_midnight > flight6_depart) {
		closest_depart_hours = flight7_depart_hours;
		closest_depart_mins = flight7_depart_mins;
		closest_arrive_hours = flight7_arrive_hours;
		closest_arrive_mins = flight7_arrive_mins;
	} else if (mins_midnight > flight5_depart) {
		closest_depart_hours = flight6_depart_hours;
		closest_depart_mins = flight6_depart_mins;
		closest_arrive_hours = flight6_arrive_hours;
		closest_arrive_mins = flight6_arrive_mins;
	} else if (mins_midnight > flight4_depart) {
		closest_depart_hours = flight5_depart_hours;
		closest_depart_mins = flight5_depart_mins;
		closest_arrive_hours = flight5_arrive_hours;
		closest_arrive_mins = flight5_arrive_mins;
	} else if (mins_midnight > flight3_depart) {
		closest_depart_hours = flight4_depart_hours;
		closest_depart_mins = flight4_depart_mins;
		closest_arrive_hours = flight4_arrive_hours;
		closest_arrive_mins = flight4_arrive_mins;
	} else if (mins_midnight > flight2_depart) {
		closest_depart_hours = flight3_depart_hours;
		closest_depart_mins = flight3_depart_mins;
		closest_arrive_hours = flight3_arrive_hours;
		closest_arrive_mins = flight3_arrive_mins;
	} else if (mins_midnight > flight1_depart) {
		closest_depart_hours = flight2_depart_hours;
		closest_depart_mins = flight2_depart_mins;
		closest_arrive_hours = flight2_arrive_hours;
		closest_arrive_mins = flight2_arrive_mins;
	} else {
		closest_depart_hours = flight1_depart_hours;
		closest_depart_mins = flight1_depart_mins;
		closest_arrive_hours = flight1_arrive_hours;
		closest_arrive_mins = flight1_arrive_mins;
	}

	// print the flight times
	bool is_depart_pm = closest_depart_hours < 12 ? false : true;
	bool is_arrive_pm = closest_depart_hours >= 12 ? true : false;

	closest_depart_hours = closest_depart_hours % 12 == 0 ? 12 : closest_depart_hours % 12;
	closest_arrive_hours = closest_arrive_hours % 12 == 0 ? 12 : closest_arrive_hours % 12;

	printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s.\n", 
		closest_depart_hours,
		closest_depart_mins,
		is_depart_pm ? "PM" : "AM",
		closest_arrive_hours,
		closest_arrive_mins,
		is_arrive_pm ? "PM" : "AM");

	return 0;
}
