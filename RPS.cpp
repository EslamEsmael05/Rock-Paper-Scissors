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

int ReadNumber(string message)
{
    int num;
    do
    {
        cout << message;
        cin >> num;
        return num;
    } while (num < 0);
    
}

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
    } while (NumberofRounds > 10);
    return NumberofRounds;

}

enGameResults CheckResults(stGameChoices Choice, stGameResults GameResults)
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

    default:
            return "Invalid";
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

void StartRound(short NumberofRounds,stGameChoices &Choices,stGameResults &GameResult)
{ 

    for (int i = 0; i < NumberofRounds;i++)
    {
        Choices.PlayerChoice = 0;
        Choices.ComputerChoice = 0;
        
        do
        {
            cout << "-------------------Round[" << i + 1 << "]" << "starts---------------------\n";
            cout << "Select a choice [1] Rock  [2] Paper  [3] Scissors\n";
            cin >> Choices.PlayerChoice;
            Choices.ComputerChoice = RandomNumber(1, 3);
        } while (Choices.PlayerChoice > 3);
        

        enGameResults Results = CheckResults(Choices,GameResult);

        cout << "-------------------Round[" << i + 1 << "]" << "---------------------\n";
        cout << "Player \tChoice: " << CheckPlayerChoice(Choices) << endl;
        cout << "Computer Choice: " << CheckComputerChoice(Choices) << endl;

        if (Results == PlayerWon)
        {

        cout << "Round Winner: Player" << endl;
        system("color 2f");
        GameResult.Wins++;

        }

        else if (Results == ComputerWon)
        {
        cout << "Round Winner: Computer\a" << endl;
        system("color 4f");
        GameResult.losses++;
        }

        else
        {
            cout << "Round Winner: No Winner" << endl;
            system("color 1f");
            GameResult.Draws++;
        }
    }
}


void ShowEndGameResults(short NumberofRounds, stGameChoices Choices, stGameResults GameResult)
{
    cout << "************************Game Over************************\n";
    cout << "Game rounds: " << NumberofRounds <<"\n";
    cout << "Player wins: " << GameResult.Wins << "\n";
    cout << "Player losses: " << GameResult.losses << "\n";
    cout << "Draw times: " << GameResult.Draws << "\n";

    if (GameResult.Wins > GameResult.losses)
    cout << "Final Winner: Player" << endl;

    else if (GameResult.Wins < GameResult.losses)
     cout << "Final Winner: Computer\a" << endl;

    else 
     cout << "Final Winner: No Winner" << endl;
    cout << "*********************************************************\n";
}



void RPS()
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
        int NumberofRounds = ReadNumberofRounds();
        StartRound(NumberofRounds, Choices, Results);
        ShowEndGameResults(NumberofRounds, Choices, Results);

        cout << "Want to play again ? (Y/N)\n";
        cin >> option;
        
        
    } while (option == 'y' || option == 'Y');
    
 }

int main()
{
    srand((unsigned)time(NULL));

    RPS();



    return 0;
}
