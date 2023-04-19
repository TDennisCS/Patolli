#include<iostream>
#include<string>
#include<array> 
#include<vector>
#include<random> 
#include<functional>

using namespace std; 

struct Space
{
    char symbol; // char (“O” → starting position,”X” →ending postion,“R” → red square, ”C” → center square, ”_” → blank square)
    int ownership; // int (0  → empty, 1 → player1, 2 → player2)
}; 

struct Square
{
    char symbol; // char (“O” → starting position,”X” →ending postion,“R” → red square, ”C” → center square)
    int location; // int (0-59)
};

struct Piece
{
    char symbol; // char (player 1 → A-F, player 2 → 1-6) 
    int location; // int (if on the board, 0-59, else NULL)
    
};

struct Movement
{
    Piece currentPiece;
    int newLocation; 
    
};

class Board
{
    private:
        array<Space,60> spaces;  // board array  
        array<Square,16> squares; // red squares('r')(0-7), center squares('c')(8-11), start ('o')(12 -13), end ('x')(14-15) 
    
    public:
        Board(); // constructor
        void Clear(); // clears board
        void Place(int playerID); // places new piece on the board 
       void Remove(char pieceSymbol); // removes piece from the board
        void Move(Movement newMove); // moves piece on board 
        array<Space,60> ShowBoard(); // returns a copy of the board array
        array<Square,16> ShowSquares(); // returns a copy of the squares array



};

class Player
{
    private:
        array<Piece,6> pieces;
        int score;
        Square start; 
        Square end; 


    public:
        Player(int playerID);
        void ClearPieces(); 
        void ClearScore();
        void NewPiece(char pieceSymbol);
        void MovePiece(Movement newMove);
        void RemovePiece(char pieceSymbol);
        void ShowPiece(char pieceSymbol);
        array<Piece,6> ShowPieces();
        void IncrementScore();
        int ShowScore();
        Square ShowStart();
        Square ShowEnd();

};

class Referee
{
    private:
        array<Player,2> players;
        Board gameBoard;
        int scoreLimit;
        bool winner = false;
        bool changeTurn = true;
        int round = 0;    
        

    public: 
        Referee();
        void FirstTurn(int playerID);
        void NewPiece(int playerID);
        bool JudgeMove(Movement newMove);
        char GetGameAction(Piece currentPiece);
        void RemovePiece(Piece removedPiece);
        void AnotherTurn();
        void NextRound();
        void ScoreEarned(Piece currentPiece);
        int GetScore(int playerID);
        void CheckWin(int playerID);
        void NewGame();
        void Display();
        void ClearScreen();





};