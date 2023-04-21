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

array<Piece,6> Player::Player::ShowPieces() {
    
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

void Player::Player::Dice() {
    
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
