/* Name: Dylan Nangle
   Date: 6/11/2024
   Description: This program simulates an ATM machine, allowing users to enter their PIN, withdraw money, and check their balance.
   Section: 102
   */

#include <iostream>
#include <iomanip> //mandatory libraries
using namespace std;

int main() {
const int CORRECT_PIN = 1234; //initialize variables needed for loop
double balance = 1000;
int pin;
int wrong_attempts;
double withdrawal_amount; 
char continue_transaction;

do {
//transactions continue based on these conditions
	wrong_attempts = 0;
	bool pin_correct = false; //use booleans for conditions in the loop

	while (wrong_attempts < 3 && !pin_correct) { //PIN verification loop

	cout << "Enter your PIN "; // prompt for PIN, if for 3 attempts the account is locked
	cin >> pin;
	if (pin == 1234) {
	pin_correct = true;
	}
	else 
	{
		wrong_attempts ++;
		if (wrong_attempts < 3) 
			cout << "Wrong PIN, please re-enter your PIN." << endl;
	}
}
// If failed PIN attempts meets 3, the account is locked 
if (!pin_correct) {
	cout << "Wrong PIN, too many tries, your account has been locked." << endl;
	return 0;
}
//Withdrawal process
cout << "Enter the amount to withdraw: $";
cin >> withdrawal_amount;

if (withdrawal_amount > balance) {
	cout << "Insufficient funds. Your current balance is $" << balance << endl;
}
else {
	balance -= withdrawal_amount;
	cout << "Withdrawal successful! New balance: $" << fixed << setprecision(2) << balance<< endl;
}
	//Ask user for another transaction
	cout << "Do you want to perform another transaction? (Y/N): ";
	cin >> continue_transaction;
	} while (continue_transaction == 'Y' || continue_transaction == 'y');
	cout << "Thank you for using our ATM. Goodbye!" << endl;
	return 0;
	
	

}
