#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty)
{
	//Print welcome messages
	std::cout <<"Difficulty level is " << Difficulty << std::endl;
	std::cout << "You are trying to access your safe.\n";
	std::cout << "In order to access the safe, you need to enter the codes correctly\n\n";
}

bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;


	std::cout << "- There are 3 numbers in the code";
	std::cout << "\n- The numbers total is " << CodeSum;
	std::cout << "\n- The product of the numbers is " << CodeProduct <<	std::endl;

	//Store the player guess
	int GuessA, GuessB, GuessC;
	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	//Check if the guess is correct
	if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
		std::cout << "\nCorrect! Next level!\n\n";
		return true;
	}
	else {
		std::cout << "\nWrong! Retrying!\n\n";
		return false;
	}
}

int main() 
{
	srand(time(NULL)); //create a new random sequence based on time of the pc

	int LevelDifficulty=1;
	const int MaxDifficulty = 5;
	 
	while (MaxDifficulty >= LevelDifficulty) //Loop the game until the all levels are completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear(); //Clears any errors
		std::cin.ignore(); //Discards the buffer
		
		if (bLevelComplete)
		{
			// Increase the level difficulty
			LevelDifficulty++;
		}
	}
	std::cout << "You succesfully opened your safe!";
	return 0;
}