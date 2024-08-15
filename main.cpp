#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

void printFeedback(const std::string &secret, const std::string &guess) {
    std::string feedback;
    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i]) {
            feedback += "+";
        } else if (secret.find(guess[i]) != std::string::npos) {
            feedback += "0";
        } else {
            feedback += "X";
        }
    }
    std::cout << feedback << std::endl;
}

int main() {
    int randomNumber = 0, enteredNumber = 0;
    std::srand(std::time(nullptr));
    randomNumber = std::rand() % 9000 + 1000;
    std::string secret = std::to_string(randomNumber);

    std::cout << "A random number between 1000 and 9999 has been generated." << std::endl;
    while (true) {
        std::cout << "\033[33mPlayer 1:\033[33m " << std::endl;
        std::cout << "Enter your guess: ";
        std::cin >> enteredNumber;

        if (enteredNumber < 1000 || enteredNumber > 9999) {
            std::cout << "Please enter a number between 1000 and 9999." << std::endl;
        } else if (enteredNumber == randomNumber) {
            std::cout << "Player 1 wins!" << std::endl;
            return 0;
        } else {
            std::string guess = std::to_string(enteredNumber);
            printFeedback(secret, guess);
            if (enteredNumber > randomNumber) {
                std::cout << "Too high! It's Player 2's turn." << std::endl;
            } else {
                std::cout << "Too low! It's Player 2's turn." << std::endl;
            }
        }


        std::cout << "\033[36mPlayer 2:\033[36m" << std::endl;
        std::cout << "Enter your guess: ";
        std::cin >> enteredNumber;

        if (enteredNumber < 1000 || enteredNumber > 9999) {
            std::cout << "Please enter a number between 1000 and 9999." << std::endl;
        } else if (enteredNumber == randomNumber) {
            std::cout << "Player 2 wins!" << std::endl;
            return 0;
        } else {
            std::string guess = std::to_string(enteredNumber);
            printFeedback(secret, guess);
            if (enteredNumber > randomNumber) {
                std::cout << "Too high! It's Player 1's turn." << std::endl;
            } else {
                std::cout << "Too low! It's Player 1's turn." << std::endl;

            }
        }
    }
}
