# GuessingGame
This game attempts to guess what you're thinking about and you help it learn from its mistakes.

### Instructions
Completely text based and run at the command line. Just run the Makefile with the command "make" and then run the program with ./"guess".
It gets its guesses from the file "qa.db" which has been provided with a few simple guesses, but deleting that file will allow you to start from scratch.

### Code
Relies upon a binary search tree to model the guesses and the questions. When run, user input is what determines the path followed to traverse the tree.

