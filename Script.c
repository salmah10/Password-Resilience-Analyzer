#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> //if I want to change the 0's and 1's to true and false

// Function prototypes
int evaluateStrength(char pass[]);
bool hasLowercase(char pass[]);
bool hasUppercase(char pass[]);
bool hasDigit(char pass[]);
bool hasSpecialChar(char pass[]);

//global variable storing most recent password strength
char* x;


int main() {
    char pass[100]; // Array to store the password

    while (1) {
        // Main menu
        printf("\nPassword Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. View strength of last tested password\n");
        printf("3. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Testing the new password
        if (choice == 1) {
            printf("Enter the password: ");
            scanf("%s", pass); // Note: This may not handle spaces in the password; consider using fgets

            if (strlen(pass) < 8) {
                printf("Error: Password should be at least 8 characters long.\n");
		continue;
            }
            int score = evaluateStrength(pass);

			// Assigning password strength
			if (score >= 0 && score <= 2) {
				x = strdup("Weak");
			} else if (score >= 3 && score <= 4) {
				x = strdup("Moderate");
			} else {
				x = strdup("Strong");
			}

			printf("Password Strength: %s\n", x);
	
	}

        // Viewing the strength of the last tested password
        else if (choice == 2) {
		printf("Last tested password strength: %s\n", x);
        }
        // Exiting the program
		else if (choice == 3) {
			printf("exiting...\n");
			break; // Exit the loop and end the program
		}
		else {
			printf("Invalid choice. Please enter a valid option.\n");
		}
	}
	return 0;
}


int evaluateStrength(char pass[]) {
    int score = 0;

    // Calculating password strength
    if (hasLowercase(pass)) {
        score += 1;
    }

    if (hasUppercase(pass)) {
        score += 1;
    }

    if (hasDigit(pass)) {
        score += 1;
    }

    if (hasSpecialChar(pass)) {
        score += 1;
    }

    if (strlen(pass) >= 12) {
        score += 1;
    }

	return score;
}


bool hasLowercase(char pass[]) {
	int i;
	for (i = 0; i < strlen(pass); i++) {
		if (pass[i] >= 'a' && pass[i] <= 'z') {
			return true;
		}
	}
	return false;
}

bool hasUppercase(char pass[]) {
	int i;
	for (i = 0; i < strlen(pass); i++) {
		if (pass[i] >= 'A' && pass[i] <= 'Z') {
			return true;
		}
	}
	return false;
}

bool hasDigit(char pass[]) {
	int i;
	for (i = 0; i < strlen(pass); i++) {
		if (pass[i] >= '0' && pass[i] <= '9') {
			return true;
		}
	}
	return false;
}

bool hasSpecialChar(char pass[]) {
	int i;
	for (i = 0; i < strlen(pass); i++) {
        	if (!(pass[i] >= '0' && pass[i] <= '9') && !(pass[i] >= 'A' && pass[i] <= 'Z') && !(pass[i] >= 'a' && pass[i] <= 'z')) {
            		return true;
        	}
	}
	return false;
}