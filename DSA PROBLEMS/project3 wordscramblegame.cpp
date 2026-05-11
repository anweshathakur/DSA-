/*
--- EDITORIAL ---
Description:
A simple console-based game where the user guesses a scrambled country name.

Key Features:
- Random Selection: Picks a random country from a predefined list.
- Scrambling: Uses std::shuffle to scramble the characters.
- Game Loop: Allows the user to keep guessing.
-----------------
*/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

void chooseword(string &secretword, string &scrambledword) {
    string words[] = {
        "india", "japan", "china", "brazil", "myanmar",
        "nepal", "srilanka", "maldives", "pakistan", "bangladesh",
        "bhutan", "vietnam", "thailand", "malaysia", "indonesia",
        "philippines", "singapore"
    };

    int totalWords = sizeof(words) / sizeof(words[0]); //total num of words in array
    int randomindex = rand() % totalWords; //random index

    secretword = words[randomindex];
    scrambledword = secretword;

    random_device rd;
    mt19937 g(rd());
    shuffle(scrambledword.begin(), scrambledword.end(), g);
}

void guessword(string secretword, string scrambledword) {
    string guess;
    int attempts = 0;
    cout << "Welcome to the word scramble game for COUNTRIES!" << endl;
    cout << "Guess the word in front of you:" << endl;
    cout << scrambledword << endl;

    do {
        attempts++;
        cout << "Attempt number: " << attempts << endl;
        cout << "Enter your guess: ";
        cin >> guess;

        if (guess == secretword) {
            cout << "Congratulations! That's correct" << endl;
            break;
        } else {
            cout << "Oops, try again!" << endl;
        }
    } while (guess != secretword);
}

int main() {
    srand(time(0));
    char choice;

    do {
        string secretword, scrambledword;
        chooseword(secretword, scrambledword);
        guessword(secretword, scrambledword);

        cout << "Do you want to play the game again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for playing!" << endl;
    return 0;
}
