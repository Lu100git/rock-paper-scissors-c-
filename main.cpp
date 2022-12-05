#include <iostream>
#include <stdio.h>  // for system
#include <stdlib.h> // for random
using namespace std;

bool validAnswer(string answer, string main_choices[]) {
  for (int i = 0; i < 3; i++) {
    if (answer == main_choices[i])
      return true;
  }
  return false;
}

bool winingAnswers(string answer, string answer2) {
  if (answer == "rock" && answer2 == "scissors")
    return true;
  else if (answer == "paper" && answer2 == "rock")
    return true;
  else if (answer == "scissors" && answer2 == "paper")
    return true;
  else {
    return false;
  }
}

bool draw(string answer, string answer2) {
  if (answer == answer2)
    return true;
  return false;
}

int randomInt() {
  int randomValue = 0;
  srand(time(NULL));
  for (int i = 1; i <= 9; i++) {
    randomValue = rand() % 2;
  }
  return randomValue;
}

int main() {
  // main variables for the game
  int index = 0;
  string main_choices[3] = {"rock", "paper", "scissors"};
  bool running = true;
  bool validation = false;
  string player_answer;
  string pc_answer;

  // title
  cout << "\t.:|ROCK PAPER SCISSORS|:." << endl;

  while (running) {
    // player input
    cout << "type your choice: ";
    player_answer = "";
    cin >> player_answer;

    // validating the right answer either rock, paper scissors
    validation = validAnswer(player_answer, main_choices);
    if (!validation) {
      do {
        cout
            << "invalid answer...type a valid answer: [rock, paper scissors]: ";
        player_answer = "";
        cin >> player_answer;
        validation = validAnswer(player_answer, main_choices);
      } while (validation == false);
    }

    // ramdom desition
    cout << "computer is thinking..." << endl;
    system("sleep 1");
    index = randomInt();
    pc_answer = main_choices[index];
    cout << endl;

    // displaying the answers
    cout << "player answer was: [" << player_answer << "]"
         << " computer choose: [" << pc_answer << "]" << endl;
    cout << endl;
    system("sleep 0.5");

    // conditions to win the game
    if (draw(player_answer, pc_answer))
      cout << " .: IT'S A DRAW! :." << endl;

    if (winingAnswers(player_answer, pc_answer))
      cout << "# YOU WIN! #" << endl;

    else if (!winingAnswers(player_answer, pc_answer) &&
             !draw(player_answer, pc_answer))
      cout << "!!! YOU LOOSE !!!" << endl;
  }

  return 0;
}
