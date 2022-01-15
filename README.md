# Greatest-Puzzler-Battle

Contents
---------------------
* File Contents
* Introduction
* Algorithm
* Requirements

## File Contents
	
	Puzzler_Battle.cpp  (program file containing code)

## Introduction
Book practice project from Problem Solving With C++ Chapter 5. Project 6.
This program follows the steps of creation in the book, rather than traditional algorithm design (See "Algorithm" Section). Demonstrates ability to use multiple functions, loops, randomizing functions, and provided algorithms in c++.
Written using Microsoft Visual Studio. 

## Algorithm

		1. Write a function to simulate a single shot, with the following dec: void shoot(bool& targetAlive, double accuracy)
			1a. generates a random number between 0 and 1; if number < accuracy, target is dead and bool = false
		2. Write a function to simulate the entire duel called startDuel that loops until a winner is decided and returns win
			2a. Follows the strategy of "shoot the most accurate duelist first", thus:
				2aa. While Charlie is alive, Aaron and Bob will shoot at him first, and Charlie will continue to shoot at Bob
				2ab. While Bob is alive, Charlie will attempt to shoot him; after Bob dies, Charlie will try to shoot Aaron.
				2ac. After Charlie dies, Aaron will try to shoot Bob, and Bob will try to shoot Aaron.
			2ab. Thus, the person with the highest accuracy will try to shoot the second highest, while the others
				will attempt to shoot the person with the highest accuracy.
		3. Loop startDuel 1000 times and output the probability of each duelist winning based on the results.
			3a. place in loop with condition counter < 1000; iterate counter at end of each loop;
			3b. record results into variables for aaron's wins, bob's wins, and charlie's wins
			3c. bring the duelists BACK FROM THE GRAVE by returning their isAlive variables to true.
		4. Do above, but with the strategy of Aaron intentionally missing his first shot.
			4a. add variable firstRound to startDuel; every time it is called is a new duel, so first round happens once
			4b. if it is the first round, have aaron shoot at charlie with accuracy 0; else, proceed normally.

## Requirements
No requirements or modules needed for running this program.
