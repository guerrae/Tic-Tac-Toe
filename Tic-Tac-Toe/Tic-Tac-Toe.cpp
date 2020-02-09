/*
Efrain Guerra
Tic-Tac-Toe Final Project
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Global Variables
int gameArr[9];
int sampleArr[9] = { 1,2,3,4,5,6,7,8,9 };
int result = 0;
int turn = 0;
int menuNum;
int score = 0;
string find;
string name;
string file = "leaderboard.txt";
ifstream inLeader;
ofstream outLeader;

//Menu Functions
void menu();
void instructions();
void displayLeaderboard();

//Tic-Tac-Toe Functions
void game();
void board(int x[]);
void player(int play, int mark);
void initTic();
void winner(int x[]);
void setLeaderboard();

int main() {
	menu();
	return  0;
}	

//Contains all code to run the game
void game() {
	
	initTic();

	do {
		cout << "Guide Board\n";
		board(sampleArr); //Function call displays guide board
		cout << "Game Board\n";
		board(gameArr);   //Function call displays game board
		if (turn == 0 || turn == 2 || turn == 4 || turn == 6 || turn == 8) { player(1, 1); }
		else { player(2, 0); }

		turn++;
		system("cls");
		winner(gameArr);

	} while (result == 0 ); //Game runs until win or loss

	board(gameArr);
	if (result == 1) { setLeaderboard(); }// only calls function if winner
	turn = 0;
}

//Initializes the game board only
void initTic() {
	for (int i = 0; i < 9; i++) {
		gameArr[i] = 2;
	}
}

//Displays the game or guide board
//Take an input the input designates what board is displayed
void board(int x[]) {
	cout << x[0] << "|" << x[1] << "|" << x[2];
	cout << "\n-|-|-\n";
	cout << x[3] << "|" << x[4] << "|" << x[5];
	cout << "\n-|-|-\n";
	cout << x[6] << "|" << x[7] << "|" << x[8] << "\n\n";
}

//Used to set player one or player two
//Takes two inputs.
//The first input sets player one or two
//The second input sets the players marker
void player(int play, int mark) {
	cout << "\nplayer " << play << " turn.\n";
	cout << "\nEnter your move: ";
	int move;
	cin >> move;
	//if satement will only allow user to enter input if its between 1 and 9
	if (move > 0 && move < 10) {
		move--;
		//If statement sets the player and its marker
		if (gameArr[move] == 1 || gameArr[move] == 0) {
			cout << "invalid";
			player(play, mark);
		}
		else { gameArr[move] = mark; }//If the game box is no used place a marker
	}
	else { cout << "invalid"; player(play, mark); } //If the game box is used redo
}

//Contains all possible win combinations
void winner(int x[]) {
	
	string player1 = "Player 1 Wins\n\n";
	string player2 = "Player 2 Wins\n\n";

	//if statements will evaluate if player one has won
		 if (gameArr[0] == 1 && gameArr[1] == 1 && gameArr[2] == 1) { cout << player1; result = 1; }
	else if (gameArr[3] == 1 && gameArr[4] == 1 && gameArr[5] == 1) { cout << player1; result = 1; }
	else if (gameArr[6] == 1 && gameArr[7] == 1 && gameArr[8] == 1) { cout << player1; result = 1; }
	else if (gameArr[0] == 1 && gameArr[3] == 1 && gameArr[6] == 1) { cout << player1; result = 1; }
	else if (gameArr[1] == 1 && gameArr[4] == 1 && gameArr[7] == 1) { cout << player1; result = 1; }
	else if (gameArr[2] == 1 && gameArr[5] == 1 && gameArr[8] == 1) { cout << player1; result = 1; }
	else if (gameArr[0] == 1 && gameArr[4] == 1 && gameArr[8] == 1) { cout << player1; result = 1; }
	else if (gameArr[2] == 1 && gameArr[4] == 1 && gameArr[6] == 1) { cout << player1; result = 1; }

	//if statements will evaluate if player two has won
	else if (gameArr[0] == 0 && gameArr[1] == 0 && gameArr[2] == 0) { cout << player2; result = 1; }
	else if (gameArr[3] == 0 && gameArr[4] == 0 && gameArr[5] == 0) { cout << player2; result = 1; }
	else if (gameArr[6] == 0 && gameArr[7] == 0 && gameArr[8] == 0) { cout << player2; result = 1; }
	else if (gameArr[0] == 0 && gameArr[3] == 0 && gameArr[6] == 0) { cout << player2; result = 1; }
	else if (gameArr[1] == 0 && gameArr[4] == 0 && gameArr[7] == 0) { cout << player2; result = 1; }
	else if (gameArr[2] == 0 && gameArr[5] == 0 && gameArr[8] == 0) { cout << player2; result = 1; }
	else if (gameArr[0] == 0 && gameArr[4] == 0 && gameArr[8] == 0) { cout << player2; result = 1; }
	else if (gameArr[2] == 0 && gameArr[4] == 0 && gameArr[6] == 0) { cout << player2; result = 1; }

	//if statements will evaluate if the game is a draw
	else if (turn == 9) { cout << "This Game is a Draw\n\n"; result = 2; }

	//if no one has won and the number of turns is less than 9
	//return a zero the while loop in "game();" will use this to keep the game going
	else { result = 0; }


}

//Contains all function tied to a menu
void menu() {
	//Menu options
	cout << "   Tic - Tac - Toe\n\n";
	cout << "1. Player vs Player\n";
	cout << "2. Instructions\n";
	cout << "3. Leaderboards\n";
	cout << "4. Exit Game\n\n";
	cout << "Enter your selection:  ";

	//Menu option input
	cin >> menuNum;

	//if satements will proced depending on user selection
		 if (menuNum == 1) { system("cls"); game(); system("cls"); menu(); }
	else if (menuNum == 2) { system("cls"); instructions(); system("cls"); menu(); }
	else if (menuNum == 3) { system("cls"); displayLeaderboard(); system("cls"); menu(); }
}

//Instructions on how to play the game
void instructions() {

	//Sets the guide board 
	initTic();

	//Instructions
	cout << "Tic-Tac-Toe is a unique game. This game is played using 1's and 0's instead of  the more comon X's and O's.";
	cout << " To play chose the option of player vs player from   the menu and the game begins. Once the game starts you will be";
	cout << "introduced to two tic-tac-toe boards. The first board is your guide board and will contain the    numbers 1 - 9.";
	cout << " Simpli input the number for the location you want your mark to bewheater its a 1 or a 0.";
	cout << " The secong board is the game board. Initially it will   display the number 2, but as the game moves on the board will";
	cout << "begin to replace   the 2's with your designated mark.\n\n";
	cout << "Guide Board: \n";
	board(sampleArr);//sets instruction board
	cout << "Game Board: \n";
	board(gameArr);//sets instruction board
	cin.ignore();
	cin.ignore();//pauses the screen
}

//Sets the winner to the leaderboards
void setLeaderboard() {
	outLeader.open(file, fstream::app); // opens the text file to enter user name
	cout << "Winner Enter your first Name: ";
	cin >> name;
	outLeader << "\n" << name ;
	outLeader.close(); //closes the text fiel after user name is entered
}

//Uses the name to output the number of wins
void displayLeaderboard() {
	//Used to find name in the leaderboards
	string find;
	cout << "Enter your name exactly as you did before: ";
	cin >> find;
	system("cls");

	cin.ignore();

	cout << "            Tic-Tac-Toe \n            Leaderboard\n\n";
	cout << "Player Name                    Wins\n";

	inLeader.open(file);//Opens the text file
	if (inLeader.is_open()) {
		while (inLeader >> name) {//Reads all info from text file
			if (name == find) { score++; }//Score will only increment if name is the same as find
		}
		cout << find << "				" << score; //outputs the name of the player and the players total wins
		cout << "\n\n   Press Enter to return to Menu";
		inLeader.close();//closes the text file
		score = 0;
	}

	inLeader.close();//Closes the text file if the if statement was not executed
	cin.ignore();
}