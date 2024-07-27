#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Hello and Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I've produced a random number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    while (true) {
        std::cout << " Please enter your guess: ";
        std::cin >> userGuess;

        if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else if (userGuess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the correct number!" << std::endl;
            break;
        }
    }

    return 0;
}
