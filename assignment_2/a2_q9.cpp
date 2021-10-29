#include <iostream>

int main();

int main() {
  int secret_number{};
  std::cout << "Player A: enter a secret number: ";
  std::cin >> secret_number;

    while (secret_number <= 0 || secret_number > 100){
        std::cout << "Invalid Input. Enter a number between 1 and 100 inclusive.";
        std::cout << "Player A: enter a secret number: ";
        std::cin >> secret_number;
    }

  while ( true ) {
    int guessed_number{};
    int previous_guess{};
    std::cout << "Player B: enter a guess: ";
    std::cin >> guessed_number;

    if ( guessed_number == secret_number ) {
      std::cout << "You guessed the secret number"
                << std::endl;
      break;
    }
    else if (guessed_number > secret_number){
        std::cout << "Your guess is too high" << std::endl;
        previous_guess = guessed_number;
    }
    else {
        std::cout << "Your guess is too low" << std::endl;
        previous_guess = guessed_number;
    }


    guessed_number = 0;
    std::cout << "Player B: enter a guess: ";
    std::cin >> guessed_number;

    if ( guessed_number == secret_number ) {
      std::cout << "You guessed the secret number"
                << std::endl;
      break;
    }
    else if (guessed_number > secret_number && guessed_number >= previous_guess){
        std::cout << "No, I already told you " << previous_guess 
            << " was too high." << std::endl;
    }
    else if (guessed_number < secret_number && guessed_number <= previous_guess){
        std::cout << "No, I already told you " << previous_guess 
            << " was too low" << std::endl;
    }
    else if (guessed_number > secret_number){
        std::cout << "Your guess is too high" << std::endl;
        previous_guess = guessed_number;
    }
    else {
        std::cout << "Your guess is too low" << std::endl;
        previous_guess = guessed_number;
    }

  }

  return 0;
}