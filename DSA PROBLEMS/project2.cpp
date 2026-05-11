/*
--- EDITORIAL ---
Description:
A classic game where the user tries to guess a secret number between 1 and 100.

Key Features:
- Random Target: Generates a secret number using rand().
- User Feedback: Tells the user if their guess is "too high" or "too low".
- Attempt Tracking: Keeps track of how many tries it took.
-----------------
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

char choice;
int attempts = 0;


int main() {
    srand(time(0)); // seed the randome num
    int secretnumber = rand() % 100 +1;
    int guess;
    std::cout << "welcome to the number fuessing game!" ;
    std::cout << "choose a number between 1 and 100:";
    do {
        attempts++;
        std::cout << "ateempt number:" << attempts;
        std::cout << "enter guess num";

        std::cin >> guess;
        if (guess > secretnumber){
            std::cout << "the number guessed is too high";
            
        }
        else if (guess < secretnumber) {
            std::cout << "the number guessed is too low";
        }


        else {
            std::cout << "congratulations! you guessed the number!";
            break;
        }
    }
        while (guess != secretnumber);

        // Ask user if they want to continue after a wrong guess
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> choice;

        if (choice == 'n' || choice == 'N') {
            std::cout << "Game exited. The secret number was: "
                      << secretnumber << "\n";
            return 0; // exit program early
   
    std::cout << "thankyou for playing!";
    std::cout << "the secret number was:" << secretnumber << std::endl;
    return 0;
    
        }
    }        
