#include <iostream>
#include "Header.h"
#include <cstdlib>  // For srand() and rand()
#include <ctime>    // For time()
#include <vector>


int main() {

std:srand(std::time(0));

    char play_again = 'y';

    std::vector<std::string> codewords = { "codecademy", "transport", "ufo", "galaxy", "extraterrestrial", "spaceship", "planet" };

    while (play_again == 'y' || play_again == 'Y') {


        greet();

        // Randomly select a codeword from the vector
        std::string codeword = codewords[std::rand() % codewords.size()];
        std::string answer(codeword.length(), '_');  // Create an answer string with the same length as the codeword, filled with underscores

        // std::string codeword = "codecademy";
       // std::string answer = "__________";
        int misses = 0;
        std::vector<char> incorrect;
        bool guess = false;
        char letter;

        while (answer != codeword && misses < 7) {

            display_misses(misses);
            display_status(incorrect, answer);

            std::cout << "\n\nPlease enter your guess: ";
            std::cin >> letter;

            // Reset guess flag for each new guess
            guess = false;

            // Check if the guessed letter is in the codeword
            for (int i = 0; i < codeword.length(); i++) {
                if (letter == codeword[i]) {
                    answer[i] = letter;
                    guess = true;// Mark as a correct guess

                }
            }

            if (guess) {
                std::cout << "\nCorrect!\n";
            }
            else {
                std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
                incorrect.push_back(letter); // Add incorrect letter to the list
                misses++;
            }
            guess = false;

        }


        end_game(answer, codeword);
        std::cout << "Doy you want to play again? (y/n):";
        std::cin >> play_again;
    }

    std::cout << "Thank you playing! Goodbye!\n";

    return 0;
}




/*Tweak the game so there is a vector of codewords that can be randomly selected in each play.

Allow players to play the game more than once.

Print out a message confirming what codeword was if the player wins or loses.

Modify player input so that it isn’t case sensitive.*/