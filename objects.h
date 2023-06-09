#include<iostream>
#include<string>
#include<array> 
#include<vector>
#include<cstdlib> 
#include<ctime> 
#include<functional>
#include<algorithm>

using namespace std; 

struct Space
{
    Square type; // char (“O” → starting position,”X” →ending postion,“R” → red square, ”C” → center square, ”_” → blank square)
    Piece ownership; // int (0  → empty, 1 → player1, 2 → player2)
    void Reset();
    bool Occupied(); // checks if space is unoccupied.
    bool Center(); // checks if space is a center square. 
    bool Red(); // checks if space is a red square. 
};

struct Square
{
    char symbol = ' '; // char (“O” → starting position,”X” →ending postion,“R” → red square, ”C” → center square, ' ' --> for blank)
    int location = 0; // int (1-60)
    void Reset();
};

struct Piece
{
    char symbol = ' '; // char (player 1 → A-F, player 2 → 1-6) ' '  == default
    int location = 0; // int (if on the board, 1-60, 0 == default)
      // is this piece in the center of the board. true for no.  false for yes. 
    void Reset();
    bool Blank(); 
};

struct Roll 
{
    int value = 0; //dice value. range (1-6), default(0) 
    int pID = 0; // player owns this roll. range (1-2) , default(0)
    void Reset();
}; 

struct Movement
{
    Piece currentPiece;
    int newLocation = 0; // location the piece is moving to. 0 is default setting for newLocation; 
    void Reset();
};

class Board
{
    private:
        array<Space,60> spaces;  // board array    
        array<Square,8> reds;
        array<Square,4> centers;
    public:
        Board(); // constructor
        void Clear(); // clears board
        array<Space,60> GetBoard(); // returns a copy of the board array
        // returns a copy of the squares array
        Space GetSpace(int spaceIndex); // grabs the space at this index on the board array
        void SetSpace(int spaceIndex); // sets the space at this index on the board array
        void ResetSpace(int spaceIndex); // resets the space at this index to it's default state. 



};

class Player
{
    private:
        array<Piece,6> pieces;
        int score;
        Square start; 
        Square end;
        int pID;  
        


    public:
        Player(int playerID);
        void ResetPieces(); 
        void ClearScore();
        void NewPiece(char pieceSymbol);
        void MovePiece(Movement move); // moves piece using the newMove parameter to find the piece in the piece list and update its new location. 
        void ResetPiece(char pieceSymbol);
        Piece GetPiece(char pieceSymbol);
        array<Piece,6> GetPieces();
        void IncrementScore();
        int ShowScore();
        Square GetStart();
        Square GetEnd();
        int GetID();
       

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
        Square currentAction;
        int gameCount = 0; 
        Roll currentRoll; 

        // low level functions

    public: 
        // High level functions
        Referee();
        int GameCounter(); //* gets the number of games played. 
        void NewGame(); //* resets all variables to default
        void NewTurn(); //* resets all important conditions related to turns. 
        void FirstTurn(int playerID); //* First turn actions. 
        void NewPiece(int playerID); //** used on the first turn method. to put first piece on the board.
        bool JudgeMove(Movement newMove);
        bool LegalMove(char pieceSymbol); 
        void MovePiece(int playerID); //** moves the piece of the player given using currentMove variable. 
        string GetPiecesString(int playerID); 
        char GetSquareActions();
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
        void PickPiece(int playerID); //* prompts player to pick a piece on the board to roll. uses generate options to prompt player. 
        vector<Movement> GenerateOptions(int playerID); //** generates options for the player based on roll and board state. 
        bool Forfeit(); // grabs forfeit bool variable. 
        void GameAction(int playerID); // rolling all possible actions into this method. 
        void CheckScoreboard(int playerID); // checks if player has reached 6 points. moditfies winner variable. 
        void UserOptions(); // option to end the program or start a new game. 
        bool Exit(); // grabs the exit condition for whether the new player wants a new game. 
};

