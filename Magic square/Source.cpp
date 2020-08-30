#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void delay(int number_of_seconds);
void color(int a);
int main() {
	int n, a[10][10], x = 0, y = 0, c = 0;
	color(1);
	printf("Welcome Magic Square \npls input n;1<=n<=10\n");
	color(5);
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%d", &a[i][j]);
			}
	}
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			x = x + a[i][j];
			printf("X axis check : %d + %d = %d\n", x - a[i][j], a[i][j], x);
			delay(50);
		}
		for (int k = 0; k < n; k++) {
			y = y + a[k][i];
			printf("Y axis check : %d + %d = %d\n", y - a[k][i], a[k][i], y);
			delay(50);
		}
		if (x == y) {
			color(3);
			printf("Pass\n");
			color(5);
			c++;
		}
		else {
			color(2);
			printf("Fail\n");
			color(5);
		}
	}
	system("cls");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			color(4);
			printf("%d ", a[i][j]);
			if ((j+1)%3 == 0) {
				printf("\n");
			}
		}
	}
	color(5);
	if (c == n) {
		color(3);
		printf("yes");
		color(5);
	}
	else {
		color(2);
		printf("no");
		color(5);
	}
}

void color(int a) {
	if (a == 1) {			//yellow
		printf("\033[1;33m");
	}
	else if (a == 2) {		//red
		printf("\033[1;31m");
	}
	else if (a == 3) {		//green
		printf("\033[1;32m");
	}
	else if (a == 4) {		//cyan
		printf("\033[1;34m");
	}
	else {					//reset
		printf("\033[0m");
	}

}
void delay(int number_of_seconds){
	int milli_seconds = number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}