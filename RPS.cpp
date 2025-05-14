// Rock-Paper-Scissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

struct stGameChoices
{
    short PlayerChoice = 0;
    short ComputerChoice = 0;
   
};

struct stGameResults
{
    short Wins = 0;
    short losses = 0;
    short Draws = 0;
};
enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };
enum enGameResults {PlayerWon = 1 , ComputerWon = 2,Draw = 3};

int RandomNumber(int from, int to)
{
    int randomnum = rand() % (to - from + 1) + from;
    return randomnum;
}



short ReadNumberofRounds()
{
    short NumberofRounds = 0;
    do
    {
        cout << "How many rounds do you want to play? (10 Maximum)\n";
        cin >> NumberofRounds;
    } while (NumberofRounds > 10 || NumberofRounds < 1);
    return NumberofRounds;

}

enGameResults RoundWinner(stGameChoices Choice, stGameResults GameResults)
{

    if (Choice.PlayerChoice == Rock && Choice.ComputerChoice == Scissors)
            return PlayerWon;

    else if (Choice.PlayerChoice == Rock && Choice.ComputerChoice == Paper) 
            return ComputerWon;
   
    else if (Choice.PlayerChoice == Paper && Choice.ComputerChoice == Rock)
            return PlayerWon;
    
    else if (Choice.PlayerChoice == Paper && Choice.ComputerChoice == Scissors)
        return ComputerWon;
    
    else if (Choice.PlayerChoice == Scissors && Choice.ComputerChoice == Paper)
            return PlayerWon;
    
    else if (Choice.PlayerChoice == Scissors && Choice.ComputerChoice == Rock)
            return ComputerWon;
   
    else
        return Draw;

}

string CheckPlayerChoice(stGameChoices Choice)
{
    switch (Choice.PlayerChoice)
    {
    case (Rock):
            return "Rock";

    case (Paper):
        return "Paper";

    case (Scissors):
            return "Scissors";


    }
}

string CheckComputerChoice(stGameChoices Choice)
{

    switch (Choice.ComputerChoice)
    {
    case (Rock):
        return "Rock";

    case (Paper):
        return "Paper";

    case (Scissors):
        return "Scissors";


    }

}


enChoice ReadPlayerChoice(stGameChoices Choices)
{
 
    do
    {
        
        cout << "Select a choice [1] Rock  [2] Paper  [3] Scissors\n";
        cin >> Choices.PlayerChoice;
        
    } while (Choices.PlayerChoice > 3 || Choices.PlayerChoice < 1);
    
    return enChoice(Choices.PlayerChoice);
}

enChoice SelectComputerChoice(stGameChoices Choices)
{
    Choices.ComputerChoice = RandomNumber(1, 3);
    return enChoice(Choices.ComputerChoice);
}

void PrintRoundResults(stGameResults &GameResults, stGameChoices Choices)
{

    cout << "Player \tChoice: " << CheckPlayerChoice(Choices) << endl;
    cout << "Computer Choice: " << CheckComputerChoice(Choices) << endl;
    enGameResults Winner = RoundWinner(Choices, GameResults);
    
    if (Winner == PlayerWon)
    {

        cout << "Round Winner: Player" << endl;
        system("color 2f");
        GameResults.Wins++;

    }

    else if (Winner == ComputerWon)
    {
        cout << "Round Winner: Computer\a" << endl;
        system("color 4f");
        GameResults.losses++;
    }

    else
    {
        cout << "Round Winner: No Winner" << endl;
        system("color 1f");
        GameResults.Draws++;
    }
}

void StartRound(short NumberofRounds,stGameResults &GameResult)
{ 

    for (short i = 0; i < NumberofRounds;i++)
    {
        stGameChoices Choices;
        cout << "-------------------Round[" << i + 1 << "]" << "starts---------------------\n";
        Choices.PlayerChoice = ReadPlayerChoice(Choices);
        Choices.ComputerChoice = SelectComputerChoice(Choices);
        cout << "\n-------------------Round[" << i + 1 << "]" << "---------------------\n";
        PrintRoundResults(GameResult, Choices);

    }
}

string GameWinner(stGameResults GameResult)
{
    if (GameResult.Wins > GameResult.losses)
        return "\t\t\tFinal Winner: Player";
                

    else if (GameResult.Wins < GameResult.losses)
        return "\t\t\tFinal Winner: Computer\a" ;

    else
        return "\t\t\tFinal Winner: No Winner" ;
}

void PrintGameOver()
{
    cout << "\t\t\t======================================\t\t\t";
    cout << "\n\t\t\t\t +++Game Over+++ \t\t\t\t\n";
    cout << "\t\t\t======================================\t\t\t\n";
}

void ShowEndGameResults(short NumberofRounds, stGameChoices Choices, stGameResults GameResult)
{
    PrintGameOver();
    cout << "\t\t\tGame rounds: " << NumberofRounds <<"\n";
    cout << "\t\t\tPlayer wins: " << GameResult.Wins << "\n";
    cout << "\t\t\tPlayer losses: " << GameResult.losses << "\n";
    cout << "\t\t\tDraw times: " << GameResult.Draws << "\n";
    cout << GameWinner(GameResult) << endl;
    cout << "\t\t\t=====================================\n";
}



void RockPaperScissors()
{
    
    stGameChoices Choices;
    stGameResults Results;
    char option;
    do
    {
        system("cls");
        Results.Wins = 0;
        Results.losses = 0;
        Results.Draws = 0;
        short NumberofRounds = ReadNumberofRounds();
        StartRound(NumberofRounds, Results);
        ShowEndGameResults(NumberofRounds, Choices, Results);

        cout << "Want to play again ? (Y/N)\n";
        cin >> option;
        
        
    } while (option == 'y' || option == 'Y');
    
 }

int main()
{
    srand((unsigned)time(NULL));

    RockPaperScissors();



    return 0;
}