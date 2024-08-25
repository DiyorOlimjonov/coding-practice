// Chapter 9 / Functions

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


// Exercises p.214
/*
// 1. Checks if x and y lies between 0 and n-1, inclusive
int checkXandY(int x, int y, int n)
{
	return ((x >= 0 && x <= n - 1) && (y >= 0 && y <= n - 1)) ? 1 : 0;
}

// 3. GCD for a and b

int gcd(int a, int b)
{
	int c;
	
	for (;;){
		if (b % a == 0)
			return a;
		else
			c = b % a;
			b = a;
			a = c;
	}
}

// # of days in year 

int day_of_year(int month, int day, int year)
{
	int days;
	switch (month) {
	case 1: case 3: case 5: case 7: case 8: case 9: case 11:
		days = 31 * (month - 1) + day;
		break;
	default:
		days = 30 * (month - 1) + day;
		break;
	}
	if (year % 4 == 0 && month > 2)  // adjusting # of days of Feb
		days -= 2;
	else
		days -= 3;
	return days;
}

// 5. counts # of digits in n(int)

	int num_digits(int n)
	{
		for (int i = 0; n > 0; ) {
			n /= 10;
			++i;
			if (n == 0)
				return i;
		}
	}

// 6. (n,k) returns k^th digit
	
	int digit(int n, int k)
	{	
		int digit, i = 0;
		for (;;)
		{
			digit = n % 10;
			++i;
			if (i <= k)
				return digit;
		}
	}

	// array

	int largest_num(int n, int a[])
	{	
		int largest_el = 0;
		for (int i = n - 1; ; --i)
			if (a[i] > largest_el) largest_el = a[i];
			else if (i <= 0)
				return largest_el;

	}

	// 12. Calculates GPA
	float compute_GPA(char grades[], int n)
	{
		float gpa = 0;
		for (int i = n - 1;;) {
			grades[i] = toupper(grades[i]);
			switch (grades[i]) {
			case 'A': gpa += 4;
			case 'B': gpa += 3;
			case 'C': gpa += 2;
			case 'D': gpa += 1;

			}
			++i;
			if (grades[i] <= 0)gpa = gpa / n;
		}
	}

	// 13.
	double inner_product(int n, double a[], double b[])
	{	
		int inner_product = 0;
		for (int i = 0; ; ) {
			inner_product += a[i] * b[i];
			++i;
			if (i = n) return inner_product;
		}

		
	}

	// 13. Sums position based on pieces on chess board

	int evaluate_position(double chess_board[8][8])
	{
		double difference = 0;
		
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++i) {
				char c = chess_board[i][j];
				if (c == 'Q') {
					difference += 9;
				}
				else if (c == 'R') {
					difference += 5;
				}
				else if (c == 'B' || c == 'N') {
					difference += 3;
				}
				else if (c == 'P') {
					difference += 1;
				}
				else if (c == 'q') {
					difference -= 9;
				}
				else if (c == 'r') {
					difference -= 5;
				}
				else if (c == 'b' || c == 'n') {
					difference -= 3;
				}
				else if (c == 'p') {
					difference -= 1;
				}

			}
		}
		return difference;
	}

	// 14. returns if any element is zero
	bool has_zero(int a[], int n)
	{
		for (int i = 0; i < n; ++i) {
			if (a[i] == 0) {
				return true;
			}
			else if (i == n - 1) {
				return false;
			}
		}
	}
	// 15. returns median 
	double median(double x, double y, double z)
	{
		double median;
		if ((x >= y && x <= z) || (x <= y && x >= z)) median = x;
		else if ((y >= x && y <= z) || (y <= x && y >= z)) median = y;
		else  median = z;
		return median;
			
	}

	// 16. Condensing fact function using exp1 ? exp2: exp3
	// n! = n * !(n - 1)
	int fact(int n)
	{
		return (n == 1) ? 1 : (n * fact(n - 1));
	}
	// 17. Rewriting factorial function without recursion

	int nonrecursive_fact(int n)
	{	
		
		for (int i = n - 1; i > 1; --i)
			n *= i;
		return n;

	}

	// 18. Condensing <ex.3 GCD int gcd(int a, int b)>
	int gcd_18(int a, int b)
	{
		return (b == 0) ? a : gcd_18(b, a % b);
	}

	// 19. mystery function
	void pb(int n)
	{
		if (n != 0)
			pb(n / 2);
			putchar('0' + n % 2);
	}

	// *Programming Projects* p. 216

	void selection_sort(int size, int a[])
	{	
		if (size <= 1) return;

		int largest_el = a[0], index = 0;
		for (int i = 1; i < size; ++i) {
			if (a[i] > largest_el) {
				largest_el = a[i];
				index = i;
			}
		}
		a[index] = a[size - 1];
		a[size - 1] = largest_el;
		selection_sort(size - 1, a);
	}
	// 2. Calculates tax due

	double tax_due(double salary)
	{
		double due;
		if (salary < 750.) due = salary / 100; // 1%
		else if (salary < 5000.) due = (salary / 100) * 3.5; // 3.5 %
		else due = (salary / 100) * 9 ; // 3.5 %
		return due;
	}
	// 3. Updating project 9 from chapter 8 <random walk>

	void generate_random_walk(char array_9[10][10])
	{
		printf("Project 9.");
		int row = 10, col = 10;
		
		memset(array_9, '.', row * col * sizeof(char)); // initiall elements: '.'
		int move_row = 0, move_colmn = 0, move_9, i_9 = 1;
		bool status_9 = { true };
		char c_9 = 'A';
		srand((unsigned)time(NULL));
		array_9[move_row][move_colmn] = c_9;

		while (status_9) {

			move_9 = rand() % 4;
			move_9 = move_9 % 4;

			while (array_9[move_row][move_colmn] != '.') {
				if (move_9 == 0) {// Move up
					if ((move_row - 1) >= 0 && array_9[move_row - 1][move_colmn] == '.') {
						move_row -= 1;
					}
					else if ((move_colmn - 1 >= 0 && array_9[move_row][move_colmn - 1] == '.') ||
						(move_row + 1 < 10 && array_9[move_row + 1][move_colmn] == '.') ||
						(move_colmn + 1 < 10 && array_9[move_row][move_colmn + 1] == '.')) {
						move_9++;
					}
					else {
						status_9 = false;
						break;
					}

				}
				else if (move_9 == 1) { // Move right
					if ((move_colmn + 1) < 10 && array_9[move_row][move_colmn + 1] == '.') {
						move_colmn += 1;
					}
					else if ((move_colmn - 1 >= 0 && array_9[move_row][move_colmn - 1] == '.') ||
						(move_row + 1 < 10 && array_9[move_row + 1][move_colmn] == '.') ||
						(move_row - 1 >= 0 && array_9[move_row - 1][move_colmn] == '.')) {
						move_9++;
					}
					else {
						status_9 = false;
						break;
					}

				}
				else if (move_9 == 2) { // Move down
					if ((move_row + 1) < 10 && array_9[move_row + 1][move_colmn] == '.') {
						move_row += 1;
					}
					else if ((move_colmn - 1 >= 0 && array_9[move_row][move_colmn - 1] == '.') ||
						(move_colmn + 1 < 10 && array_9[move_row][move_colmn + 1] == '.') ||
						(move_row - 1 >= 0 && array_9[move_row - 1][move_colmn] == '.')) {
						move_9++;
					}
					else {
						status_9 = false;
						break;
					}
				}
				else if (move_9 == 3) { // Move left
					if ((move_colmn - 1) > 0 && array_9[move_row][move_colmn - 1] == '.') {
						move_colmn -= 1;
					}
					else if ((move_row + 1 < 10 && array_9[move_row + 1][move_colmn] == '.') ||
						(move_colmn + 1 < 10 && array_9[move_row][move_colmn + 1] == '.') ||
						(move_row - 1 >= 0 && array_9[move_row - 1][move_colmn] == '.')) {
						move_9 = 0;
					}
				}
				else {
					status_9 = false;
					break;
				}


			}

			c_9++;
			array_9[move_row][move_colmn] = c_9;
			printf("\n %d Move_row = %d, Move_colmn = %d, move_9 = %d", i_9, move_row, move_colmn, move_9);
			++i_9;
			if (c_9 == 'Z') {
				status_9 = false;
			}


		}
	}
	void print_array(char array_9[10][10])
	{
		for (int i = 0; i < 10; i++) {
			printf("\n");
			for (int j = 0; j < 10; j++) {
				printf("%c ", array_9[i][j]);
			}
		}
	}

	// 4. Updating < 16. Checks if two words are anagrams> from chapter 8
	void read_words(int counts[26])
	{
		char c_16;
		printf("\nEnter first word: ");
		while ((c_16 = getchar()) != '\n') {
			c_16 = tolower(c_16);
			if (c_16 >= 'a' && c_16 <= 'z') {
				counts[c_16 - 'a'] += 1;
			}
		}

		printf("Enter second word: ");
		while ((c_16 = getchar()) != '\n') {
			c_16 = tolower(c_16);
			if (c_16 >= 'a' && c_16 <= 'z') {
				if (counts[c_16 - 'a'] > 0) {
					counts[c_16 - 'a'] -= 1;
				}
			}
		}
	}
	bool equal_arrays(int counts[26])
	{
		for (int i = 0; i < 26; ++i) {
			if (counts[i] > 0) {
				return false;
			}
			else if (i == 25 ) {
				
				return true;
			}
		}
	}
	*/
	// 5. Magic Square
	void create_magic_square(int n, int square[99][99])
	{
		int row = 0, col = n / 2;
		
		square[row][col] = 1; // start position with 1
		

		for (int i = 2; i <= n * n; ++i) {
			int new_row = (row - 1 + n) % n;
			int new_col = (col + 1) % n;
			if (square[new_row][new_col] == 0) {
				row = new_row;
				col = new_col;
				square[row][col] = i;
			}
			else {
				++row;
				square[row][col] = i;
			}
		}
	}

	void print_array_5(int n, int square[99][99])
	{	
		printf("\n Magic square: ");
		for (int i = 0; i < n; ++i) {
			printf("\n");
			for (int j = 0; j < n; ++j) {
				printf("%d ", square[i][j]);
			}
		}
	}
	
	// 7. 
	double power(double x, int n)
	{	
		
		if (n == 0) {
			return 1;
		}
		else if (n == 1) {
			return x;
		}
		if (n % 2 == 0) {
			double half_power = power(x, n / 2);
			return half_power * half_power;
		}
		
		else {
			return (power(x, n - 1) * x);
		}
	}

	// 6. 
	double polynomial(double x)
	{
		return (3 * power(x, 5) + 2 * power(x, 4) + 5 * power(x, 3) + power(x, 2)
			+ 7 * power(x, 1) - 6);
	}

	// Simulating game of craps using two dices

	int roll_dices(void)
	{
		srand((unsigned)time(NULL));
		int dice_1 = rand() % 6 + 1, dice_2 = rand() % 6 + 1; // Generate a random number between 1 and 6
		return dice_1 + dice_2;

	}
	bool play_game(void)
	{   
		bool status;
		int point = roll_dices();
		printf("\nYou rolled: %d\n", point);
		if (point == 7 || point == 11) {
			printf("You won\n");
			return true;
		}
		else if (point == 2 || point == 3 || point == 12) {
			printf("You lost\n");
			return false;
		}
		else {
			printf("Your point: %d", point);
			while (true) {
				int roll = roll_dices();
				printf("\nYou rolled: %d\n", roll);
				if (roll == point) {
					printf("You won\n");
					status = 1;
					break;
				}
				else if (roll == 7) {
					printf("You lost\n");
					status = 0;
					break;
				}
			}
			return status;
		}
		
		
	}

	long main(void)
	{
		// Calls of Exercises p.214
    /*
	// 1. Checks if x and y lies between 0 and n-1, inclusive
		bool check = checkXandY(3, 5, 9);
		printf("%d", check);

		// 3. GCD

		printf("\n GCD %d\n", gcd(270, 192));

		// 4. number of days

		int month, day, year;
		printf("Enter a date:(mm.dd.yyyy) ");
		scanf_s("%d.%d.%d", &month, &day, &year);
		printf("It is day %.3d", day_of_year(month, day, year));

		// 5. counts # of digits in n(int
		int n;
		printf("5. Enter a number: ");
		scanf_s("%d", &n);
		printf("Number %d has %d digits\n", n, num_digits(n));


		// 6.
		int n_6, k_6;
		printf("6. Enter n and k: ");
		scanf_s("%d%d", &n_6, &k_6);
		printf("Digit %d (from right)  of %d is %d", k_6, n_6, digit(n_6, k_6));


		// Largest num
		int n_10 = 4;
		int arr_10[4] = {1, 2, 3, 4};
		int largest_10 = largest_num(n_10, arr_10);
		printf("Largest num: %d", largest_10);


		// 14. returns if any element is zero: has_zero()
		int a_14[5] = {1, 2, 3, 4, 0}, n_14 = 5;
		printf("\n14. returns 1 if has zero, 0 if has not: %d", has_zero(a_14, n_14));

		// 15. returns median of three number

		double x = -1, y = 2, z = 1;
		printf("\n15. Median: %5.1lf", median(x, y, z));

		//


	// 16. Condensing fact function using exp1 ? exp2: exp3
	// n! = n * !(n - 1)
		int n_16 = 1;
		printf("\n16. Factorial of %d is %d", n_16, fact(n_16));

	// 17. Rewriting factorial function without recursion
		int n_17 = 5;
		printf("\n17. Factorial of %d is %d", n_17, nonrecursive_fact(n_17));


	// 18. GCD(greatest common devisor) with recursion
		int a_18 = 22, b_18 = 33;
		printf("18. GCD of %d and %d is %d", a_18, b_18, gcd_18(a_18, b_18));


	// 19. Converts to binary
		pb(12);

	// *Programming Projects* p.214

	// 1. selectoion_sort

		int size_1 = 10;
		int arr_1[10];
		printf("Enter  10 array elements (el1, el2, ... el10): ");
		for (int i = 0; i < size_1; ++i)
			scanf_s("%d,", &arr_1[i]);
		selection_sort(size_1, arr_1);
		printf("Sorted array: ");d
		for (int i = 0; i < size_1; ++i)
			printf("%d, ", arr_1[i]);


	// 2. Tax due calculator
		double salary_2;
		printf("\nEnter the amount: ");
		scanf_s("%lf", &salary_2);
		printf("Tax due %8.2f", tax_due(salary_2));


// 3. Random walk across 10x10 array, steps marked from A to Z in walking order
		
		char array_9[10][10];
		generate_random_walk(array_9);
		print_array(array_9);
	
// 4. Updating < 16. Checks if two words are anagrams> from chapter 8
	
		int counts[26] = { 0 };
	read_words(counts);
	printf("4. 1 if words are anagrams, 0 otherwise: %d", equal_arrays(counts));

	
// 5. Magic Square

	int square[99][99] = { 0 }, n_5;
	printf("\nEnter odd number as size of square: ");
	scanf_s("%d", &n_5);
	create_magic_square(n_5, square);
	print_array_5(n_5, square);

	
// 7. <polynomial>  ( 3 * power(x, 5) + 2 * power(x, 4) + 5 * power(x, 3) + power(x, 2) +7 * power(x, 1) - 6);
	double x_7;
	printf("\nEnter a value for x: ");
	scanf_s("%lf", &x_7);
	printf("Result of polynomial: %6.2f", polynomial(x_7));


// 8. Crap game using 2 dices
	int wins = 0, losses = 0;
	while (true) {
		bool result = play_game();
		char c_8;
		if (result) 
			wins++;
		else losses++;
		printf("Play again?(y or n)\n");
		
		scanf_s(" %c", &c_8, 1);
		if (c_8 == 'n') {
			printf("Wins: %d\nLoses: %d\n", wins, losses);
			break;
		}


	}
	
	return 0;
	}

