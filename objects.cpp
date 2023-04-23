#include "objects.h"


Board::Board() {
    
}

void Board::Clear() {
    
}

void Board::Place(int playerID) {
    
}

void Board::Remove(char pieceSymbol) {
    
}

void Board::Move(Movement newMove) {
    
}

array<Space,60> Board::ShowBoard() {
    
}

array<Square,16> Board::ShowSquares() {
    
}

Player::Player::Player(int playerID) {
    
}

void Player::Player::ResetPieces() {
    
}

void Player::Player::ClearScore() {
    
}

void Player::Player::NewPiece(char pieceSymbol) {
    
}

void Player::Player::MovePiece(Movement newMove) {
    
}

void Player::Player::ResetPiece(char pieceSymbol) {
    
}

void Player::Player::ShowPiece(char pieceSymbol) {
    
}

array<Piece,6> Player::Player::GetPieces() {
    
}

void Player::Player::IncrementScore() {
    
}

int Player::Player::ShowScore() {
    
}

Square Player::Player::ShowStart() {
    
}

Square Player::Player::ShowEnd() {
    
}

int Player::Player::GetID() {
    
}

void Player::Player::Dice() 
{
    // rolls a dice and sets the roll variable.     
}

void Player::Player::GetRoll() {
    
}

Referee::Referee() 
{
    
}

int Referee::GameCounter() 
{
    //* grabs the game count variable.  only executes when higher than 0. meaning new game.
    int counter = gameCount;
    return gameCount;
    
}
void Referee::NewGame() {
    //* resets all variables
        for (auto i: players)
        {
            i.ResetPieces();
        }

        gameBoard.Clear();

        winner = false;

        changeTurn = true;

        forfeitTurn = false;

        exitCondtion = false;

        roundCount = 0;    
        
        currentMove.reset();

        currentAction = ' ';

        int gameCount = 0;
}

int Referee::GetRound()
{
    //* grabs the round count variable. executes when not on first round.
    
    int count = roundCount;
    
    return count;
}

void Referee::NewTurn() 
{
    //* resets all important conditions. 
                    
    changeTurn = true; 
    forfeitTurn = false;
    currentMove.reset();
    currentAction = ' ';

}
void Referee::RollDice(int playerID) 
{

    //* rolls the dice in the player obj and sets the player roll.
    players[playerID].Dice();



}

void Referee::PickPiece(int playerID)
{
    //* generates legal options for player then prompts for action. sets the current action option.

    char answer;   // user input 
    bool promptCondition = true; // keeps asking the user for a valid piece to move. 


    vector<char> options = GenerateOptions(playerID); // options aviable for the player; 

    bool optionCondition = !(options.empty());

    // portions of the prompt.
    string message1 = "Player ";
    string message2 = ", Please Input piece to move [";
    string message3 = "]: or Forfiet turn [0]";

    // converts option vector into string.  
    
    string optionString = ""; // initalizes an empty string 
    if (optionCondition == true) // checks if options are empty. if not then fills options string. 
    {
        for (auto i : options) 
        {
            optionString = optionString + " " + i;
        }
    }
    else // if it is then gives a altnerate option string. 
    {
        optionString = "No Piecees Available"; 
    }




    // concatenate all the portions into a prompt. 
    string prompt = message1 + to_string(playerID) + message2 + optionString + message3; 

    // loops till it gets a vaild input. 
    if (optionCondition == true)
    {
        do 
        {
            cout << prompt; // displays prompt message
            cin >> answer; // inputs respone into answer variable. 
            answer = toupper(answer); // converts input into uppercase
            if (find(options.begin(), options.end(),answer) !=options.end())
            {
                promptCondition == false;
            }
            if (answer == '0')
            {
                promptCondition == false; 
            }

        } while (promptCondition == true);
    }
    else
    {
        do 
        {
            cout << prompt; // displays prompt message
            cin >> answer; // inputs respone into answer variable. 
            if (answer == '0')
            {
                promptCondition == false;
            }

        } while (promptCondition == true);
    }


    if(answer == '0') // if the player choose "0' than it updates forfeit condition. 
    {
        forfeitTurn = true;
    }
    else // if the player choose a piece then calls movepiece to update piece slected. 
    {
        MovePiece(playerID, answer); // moves the piece of the player given using the roll variable. 

    }
}

string Referee::GetPiecesString(int playerID)
{
    // gets the piece symbols for the player into a char array. 
 
    array<Piece,6> pieceList = players[playerID].GetPieces();
    array<char,6> pieceID;
    string playerPieceList = "";
    for (int i = 0; i < 6; i++)
    {
        pieceID[i] = pieceList[i].symbol;
    }

    for (int i = 0; i < 6; i++)
    {
        playerPieceList = playerPieceList + pieceID[i] +  ", " ;
    }

    return playerPieceList;
}



void Referee::MovePiece(int playerID, char pieceSymbol)
{
    players[playerID].MovePiece(pieceSymbol);
}

void Referee::NewPiece(int playerID) {
    
}

bool Referee::JudgeMove(Movement newMove) {
    
}

char Referee::GetSquareActions(Piece currentPiece) {
    
}

void Referee::RemovePiece(Piece removedPiece) {
    
}

void Referee::AnotherTurn() {
    
}

void Referee::ScoreEarned(Piece currentPiece) {
    
}

int Referee::GetScore(int playerID) {
    
}

bool Referee::CheckWin() {
    
}

void Referee::Display() {
    
}

void Referee::ClearScreen() {
    
}

int Referee::ShowRoll(int playerID) {
    
}
