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
    Piece ownership; // int (0  → empty, 1 → player1, 2 → player2)
    int locID; // 1-60
    void reset();
};

struct Square
{
    char symbol; // char (“O” → starting position,”X” →ending postion,“R” → red square, ”C” → center square)
    int location; // int (0-59)
};

struct Piece
{
    char symbol = ' '; // char (player 1 → A-F, player 2 → 1-6) ' '  == default
    int location = 0; // int (if on the board, 1-60, 0 == default)
    void reset();
    
};

struct Movement
{
    Piece currentPiece;
    int newLocation = 0; // location the piece is moving to. 0 is default setting for newLocation; 
    void reset();
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
        int pID;
        int roll;


    public:
        Player(int playerID);
        void ResetPieces(); 
        void ClearScore();
        void NewPiece(char pieceSymbol);
        void MovePiece(Movement newMove);
        void ResetPiece(char pieceSymbol);
        void ShowPiece(char pieceSymbol);
        array<Piece,6> ShowPieces();
        void IncrementScore();
        int ShowScore();
        Square ShowStart();
        Square ShowEnd();
        int GetID();
        void Dice(); 
        void GetRoll(); 

};

class Referee
{
    private:
        // variables 
        array<Player,2> players;
        Board gameBoard;
        const int scoreLimit = 6;
        bool winner = false;
        bool changeTurn = true;
        bool forfeitTurn = false;
        bool exitCondtion = false;
        int roundCount = 0;    
        Movement currentMove;
        char currentAction = ' ';
        int gameCount = 0; 

        // low level functions

    public: 
        // High level functions
        Referee();
        int GameCounter(); //* gets the number of games played. 
        void NewGame(); //* resets all variables to default
        void NewTurn(); //* resets all important conditions related to turns. 
        void FirstTurn(int playerID); //* First turn actions. 
        void NewPiece(int playerID);
        bool JudgeMove(Movement newMove);
        char GetSquareActions(Piece currentPiece);
        void RemovePiece(Piece removedPiece);
        void AnotherTurn(); 
        void NextRound(); //* Increaments the round counter. 
        void ScoreEarned(Piece currentPiece);
        int GetScore(int playerID);
        bool CheckWin();
        void NewGame();
        void Display();
        void ClearScreen();
        bool GetChangeTurn(); // get the change turn bool variable to know if the player gets another turn. 
        void SetChangeTurn(); // sets change turn to true at the beginning of the player turn.
        int GetRound(); //* gets the round count variable. 
        void RollDice(int playerID); //* rolls the dice in the player obj and sets the player roll. 
        int ShowRoll(int playerID); // shows the player roll
        void PickPiece(int playerID); //* prompts player to pick a piece on the board to roll. uses generate options to prompt player. 
        vector<Piece> GenerateOptions(int playerID); // generates options for the player based on roll and board state. 
        bool Forfeit(); // grabs forfeit bool variable. 
        void GameAction(int playerID); // rolling all possible actions into this method. 
        void CheckScoreboard(int playerID); // checks if player has reached 6 points. moditfies winner variable. 
        void UserOptions(); // option to end the program or start a new game. 
        bool Exit(); // grabs the exit condition for whether the new player wants a new game. 
};

