#include <iostream>
#include <ctime>;
//declare constants
const double AARON_ACC = 0.33, BOB_ACC = 0.5, CHARLIE_ACC = 1.0;
//declare functions
void shoot(bool& targetAlive, double accuracy);
//precondition: there is a living target, and the shooter is alive and his accuracy is known
//postcondition: Checks a random value against the shooter's accuracy to determine if they hit.
// If they do, kills the target (setting targetAlive to false.)
int startDuel(bool& firstDuelist, bool& secondDuelist, bool& thirdDuelist);
//precondition: three duelists are alive and listed from lowest accuracy to highest
//postcondition: the duelists duel to the death; the winner is returned as 1, 2, or 3, representing the
//first, second, and third duelists respectively.

//main
int main()
{
	using namespace std;
	//seed random
	srand(time(0));
	//initialize variables
	bool aaronAlive = true, bobAlive = true, charlieAlive = true, oneAlive = false;
	int c = 0, aaronWins = 0, bobWins = 0, charlieWins = 0;
	//greet user
	cout << "This program will determine the greatest puzzler of all time.\n";
	//D-D-D-D-D-DUEL!
	while (c < 1000)
	{
		int winner = startDuel(aaronAlive, bobAlive, charlieAlive);
		if (winner == 1)
			aaronWins++;
		else if (winner == 2)
			bobWins++;
		else if (winner == 3)
			charlieWins++;
		else
			cout << "Nobody won.\n";
		c++;
		aaronAlive = true, bobAlive = true, charlieAlive = true;
	}
	cout << "Aaron wins: " << aaronWins << endl << "Aaron probability: " << aaronWins / 1000.0 << endl
		<< "Bob wins: " << bobWins << endl << "Bob probability: " << bobWins / 1000.0 << endl
		<< "Charlie wins: " << charlieWins << endl << "Charlie probability: " << charlieWins / 1000.0 << endl;
	cout << "Goodbye!\n";
	return 0;
}

//define functions
//uses iostream
void shoot(bool& targetAlive, double accuracy)
{
	using namespace std;
	int random = rand() % 100;
	if (accuracy >= (static_cast<double>(random) / 100.0))
		targetAlive = false;
	if (targetAlive)
		cout << "the shot missed!\n";
	else
		cout << "the shot hit!\n";
	return;
}
int startDuel(bool& firstDuelist, bool& secondDuelist, bool& thirdDuelist)
{
	bool firstRound = true;
	while ((firstDuelist + secondDuelist + thirdDuelist > 1))
	{
		if (firstRound)
		{
			shoot(thirdDuelist, 0.0);
			firstRound = false;
		}
		if (firstDuelist)
		{
			if (thirdDuelist)
				shoot(thirdDuelist, AARON_ACC);
			else if (secondDuelist)
				shoot(secondDuelist, AARON_ACC);
		}
		if (secondDuelist)
		{
			if (thirdDuelist)
				shoot(thirdDuelist, BOB_ACC);
			else if (secondDuelist)
				shoot(firstDuelist, BOB_ACC);
		}
		if (thirdDuelist)
		{
			if (secondDuelist)
				shoot(secondDuelist, CHARLIE_ACC);
			else if (firstDuelist)
				shoot(firstDuelist, CHARLIE_ACC);
		}
	}
	if (firstDuelist)
		return 1;
	else if (secondDuelist)
		return 2;
	else if (thirdDuelist)
		return 3;
	else
		return 0;
}