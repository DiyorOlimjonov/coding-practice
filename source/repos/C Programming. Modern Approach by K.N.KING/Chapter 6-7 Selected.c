
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
/*	.6.1 Displays the largest number from a series of numbers.	*/ 
void largest_number(void);


/*	6.7 Asks the user to enter a U.S. dollar amount and then shows how to pay that amount
using the smallest number of $20, $10, $5, and $1 bills.	*/
void bills(void);

/*	7. Executes arithmetic operation between two fractions(*, / , +, -)	*/
void arthmetic_in_fractions(void);

/*	7.10 Counts number of vovels in a sentence	*/
void count_vowels(void);

int main(void)
{
	largest_number();

	bills();

	arthmetic_in_fractions();

	count_vowels();

	return 0;


}

// 6.1 Displays the largest number from a series of numbers
void largest_number(void)
{
	double max = 0, temp;
	printf("Stops when 0 is entered...");
	for (;;) {
		printf("Enter a number...");
		scanf_s("%lf", &temp);
		if (temp == 0) {
			printf("The largest number is %8.2f \n", max);
			return;
		}
		else if (temp > max) {
			max = temp;
		}
	}
}

/*	6.7 Asks the user to enter a U.S. dollar amount and then shows how to pay that amount
using the smallest number of $20, $10, $5, and $1 bills.	*/
void bills(void)
{
	int b_20, b_10, b_5, b_1, amount;
	printf("\nEnter the dollar amount...");
	scanf_s("%d", &amount);
	b_20 = amount / 20;
	amount = amount % 20;
	b_10 = amount / 10;
	amount = amount % 10;
	b_5 = amount / 5;
	b_1 = amount % 5;
	printf("You need:\n$20: %d\n$10: %d\n$5: %d\n$1: %d\n", b_20, b_10, b_5, b_1);
	return;
}

/*	7. Executes arithmetic operation between two fractions(*, / , +, -)	*/
void arthmetic_in_fractions(void)
{
	int dig1_fr1 = 1, dig2_fr1, dig1_fr2, dig2_fr2;
	float sum_frac = 0;
	char operator_;
	bool while_check = 1;
	while (while_check == 1) {
		printf("Enter two fractions and the desired operation operator between them (d/d operator d/d:)");
		scanf_s("%d/%d%c%d/%d", &dig1_fr1, &dig2_fr1, &operator_, 1, &dig1_fr2, &dig2_fr2);

		switch (operator_) {
		case '*': sum_frac = (dig1_fr1 * (float)dig1_fr2) / (dig2_fr1 * (float)dig2_fr2); break;
		case '/': sum_frac = (dig1_fr1 * (float)dig2_fr2) / (dig2_fr1 * (float)dig1_fr2); break;
		case '+': sum_frac = ((dig1_fr1 * (float)dig2_fr2) + (dig2_fr1 * (float)dig1_fr2)) / ((dig2_fr1 * (float)dig2_fr2)); break;
		case '-': sum_frac = ((dig1_fr1 * (float)dig2_fr2) - (dig2_fr1 * (float)dig1_fr2)) / ((dig2_fr1 * (float)dig2_fr2)); break;
		default: printf("Enter a valid expression...");
		}

		printf("%10.2f\n", sum_frac);
		printf("Enter new fractions to continue or 0  to stop\n");
		scanf_s("%d/%d%c%d/%d", &dig1_fr1, &dig2_fr1, &operator_, 1, &dig1_fr2, &dig2_fr2);
		if (dig1_fr1 == 0)
			return;
	}
}

/*	7.10 Counts number of vovels in a sentence	*/
void count_vowels(void)
{
	char c = 'A';
	int i = 0;
	getchar();
	printf("Enter a text: ");
	while (c != '\n') {

		c = toupper(getchar());
		switch (c) {
		case 'A': case 'E':case 'I':case 'O':case 'U': ++i; break;
		}
		if (c == '\n') {
			printf("Vowels: %d\n", i);
			return;
		}
	}
}
