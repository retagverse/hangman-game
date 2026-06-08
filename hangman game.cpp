#include <iostream>
#include <string>
using namespace std;

int main() {
    string word = "code";
    string guessWord = "____";
    char letter;

    int tries = 6;
    int score = 100;

    cout << "=== Hangman Game ===\n";

    while (tries > 0 && guessWord != word) {
        cout << "\nWord: " << guessWord;
        cout << "\nTries left: " << tries;
        cout << "\nScore: " << score;
        cout << "\nEnter a letter: ";
        cin >> letter;

        bool correct = false;

        for (int i = 0; i < word.length(); i++) {
            if (word[i] == letter && guessWord[i] == '_') {
                guessWord[i] = letter;
                correct = true;
            }
        }

        if (!correct) {
            tries--;
            score -= 10;
            cout << "Wrong guess! -10 points\n";
        }
        else {
            cout << "Good job!\n";
        }
    }

    if (guessWord == word) {
        score += tries * 20; 
        cout << "\nYou won! 🎉";
    }
    else {
        score = 0;
        cout << "\nGame Over 💀";
    }

    cout << "\nFinal score: " << score << endl;

    return 0;
}