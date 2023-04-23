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

void Player::Player::ResetPieces() 
{
   for (int i = 0; i< 6; i++)
    {
        pieces[i].reset();
    }    
}

void Player::Player::ClearScore() 
{
    score = 0;     
}

void Player::Player::NewPiece(char pieceSymbol) 
{
    for (int i = 0; i< 6; i++)
    {
        if(pieces[i].symbol == pieceSymbol)
        {
            pieces[i].location = start.location;  
        }
    }    
}

void Player::Player::MovePiece(Movement move) 
{
    // moves piece given using move parameter.

    for (int i = 0; i< 6; i++)
    {
        if(pieces[i].symbol == move.currentPiece.symbol)
        {
            pieces[i].location = move.newLocation;  
        }
    }    
}

void Player::Player::ResetPiece(char pieceSymbol) 
{
    
    for (int i = 0; i< 6; i++)
    {
        if(pieces[i].symbol == pieceSymbol)
        {
            pieces[i].reset();
        }
    }
     
}

Piece Player::Player::GetPiece(char pieceSymbol) 
{
    Piece target; 
        for (auto index: pieces)
        {
            if (index.symbol == pieceSymbol)
            {  
                target = index; 
            }
        } 
    return target; 
}

array<Piece,6> Player::Player::GetPieces() 
{
    return pieces;    
}

void Player::Player::IncrementScore() 
{
    score = score + 1; 

}


int Player::Player::ShowScore() 
{
    return score;    
}

Square Player::Player::GetStart()
{
    return start; 
}

Square Player::Player::GetEnd() 
{
    return end; 
}

int Player::Player::GetID() 
{
    return pID;     
}


Referee::Referee() 
{
    //constructor 
}

int Referee::GameCounter() 
{
    //* grabs the game count variable.  only executes when higher than 0. meaning new game.
    int counter = gameCount;
    return gameCount;
    
}
void Referee::NewGame() 
{
    //* resets all variables
        for (int i = 0; i < 2; i++)
        {
            players[i].ResetPieces();
        }

        gameBoard.Clear();

        winner = false;

        changeTurn = true;

        forfeitTurn = false;

        exitCondtion = false;

        roundCount = 0;    
        
        currentMove.reset();

        currentAction.reset();

        currentRoll.reset();

        gameCount++; 
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
    currentAction.reset();
    currentRoll.reset();

}
void Referee::RollDice(int playerID) 
{
    //* rolls a 6 sided dice then updates the roll variable.  
    int realPID = 1 + playerID; // gives the real playerID for the player. 
    int roll; 
    
    roll = rand() % 6 + 1;
    currentRoll.pID = realPID; 
    currentRoll.value = roll; 
}

void Referee::PickPiece(int playerID)
{
    //* generates legal options for player then prompts for action. sets the current action option.
   
    // portions of the prompt.
    string message1 = "Player ";
    string message2 = ", Please Input piece to move [";
    string message3 = "]: or Forfiet turn [0]";
    // variable given to the user for prompting. 
    string optionString = ""; // initalizes an empty string

    char answer;   // user input 
    bool promptCondition = true; // keeps asking the user for a valid piece to move. default true unless an vaild answer is given. 

    vector<Movement> moves = GenerateOptions(playerID); // loads moves avaiable for the player into a list; 
    vector<char> options; // option list of the piece symbol from move list.
    bool optionCondition = !(moves.empty()); // checks if moves list is empty or not.
    
    // converts option vector into string.  

    if (optionCondition == true) // checks if options are empty. if not then fills options string. 
    {
        
        for(auto move : moves)
        {
            options.push_back(move.currentPiece.symbol); // loads the piece symbol into the options list for processing. 
        }
        for (auto option : options) 
        {
            optionString = optionString + " " + option; // concatenates the optionspring with every option in the option vector. 
        }
    }
    else // if it is then gives a altnerate option string. 
    {
        optionString = "No Piecees Available"; 
    }

    // concatenate all the portions into a prompt. 
    string prompt = message1 + to_string(playerID) + message2 + optionString + message3; 

    // loops till it gets a vaild input. 
    if (optionCondition == true) // option list is not empty 
    {
        do 
        {
            cout << prompt; // displays prompt message
            cin >> answer; // inputs respone into answer variable. 
            answer = toupper(answer); // converts input into uppercase
            if (find(options.begin(), options.end(),answer) !=options.end()) // checks if this was a vaild selection. 
            {
                promptCondition == false; // breaks loop. 
            }
            else if (answer == '0') // player wishes to forfiet turn 
            {
                promptCondition == false; 
            }
            else // bad input 
            {
                cout << "Invaild selection " << endl; // error message. 
            }
        } while (promptCondition == true); // loop conditon for input. 
    }
    else // option list is empty. 
    {
        do 
        {
            cout << prompt; // displays prompt message
            cin >> answer; // inputs respone into answer variable. 
            if (answer == '0') // unless the user inputs 0 the loop won't break. 
            {
                promptCondition == false;
            }

        } while (promptCondition == true);
    }

    if(answer == '0') // if the player choose "0' than it updates forfeit condition. 
    {
        forfeitTurn = true; // update. 
    }
    else // if the player choose a piece then calls movepiece to update piece slected. 
    {
         // updates current move variable by matching answer to moves list.  
        for (auto move: moves)
        {
            if (move.currentPiece.symbol == answer)
            {
                currentMove = move; 
            }
        }

        MovePiece(playerID); // moves the piece of the player given using the currentMove variable. 

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



void Referee::MovePiece(int playerID)
{
    players[playerID].MovePiece(currentMove);
}

vector<Movement> Referee::GenerateOptions(int playerID)
{
    // generates options for the player based on roll and board state.
    vector<Movement> options; // initalizes the options that will be returned.

    int roll = currentRoll.value; // loads the currentroll  to roll variable. 

    array<Piece,6> piecelist = players[playerID].GetPieces(); // loads player piece array into piecelist.

    Movement move; // struct to load variables into before pushing back into the vector. 

    bool legal; 

    int start = players[playerID].GetStart().location; // start location for a new piece. 


    if (roll == 1) // if the player rolls a 1, they can add a new piece to the board. so one piece in the bank can be added. or one piece can moved one space. 
    {
        for(auto i: piecelist)
        {
            if (i.location == 0) // if the piece is in the bank loc = 0, then if it checks if the start spot is blocked if not then the move is added to options. 
            {
                move.currentPiece = i; 
                move.newLocation = start;
                legal = JudgeMove(move); // checks if a movement is legal. 
                if (legal == true)
                {
                    options.push_back(move);
                }

            }
            else // of the piece isn't in the bank loc > 0 then if checks its movement at the new location by adding the roll to it's previous loc. 
            {
                move.currentPiece = i; 
                move.newLocation = i.location + roll; 
                if (move.newLocation > 60) // accounts for a looping situation to see if on the loop around the piece would be blocked. 
                {
                    move.newLocation - 60;
                }
                legal = JudgeMove(move); // checks if a movement is legal. 
                if (legal == true)
                {
                    options.push_back(move);
                }
            }
        }
    }
    else // player rolls higher than a one meaning that they can not add new pieces. 
    {
        for(auto i: piecelist)
        {
           
            move.currentPiece = i; 
            move.newLocation = i.location + roll; 
            if (move.newLocation > 60) // accounts for a looping situation to see if on the loop around the piece would be blocked. 
            {
                move.newLocation - 60;
            }
            legal = JudgeMove(move); // checks if a movement is legal. 
            if (legal == true)
            {
                    options.push_back(move);
            }
            
        }
    }


    return options; 

}
void Referee::NewPiece(int playerID) 
{
    // used on the first turn method. to put first piece on the board.
    int realPID = 1 + playerID;
    
    if (realPID == 1) 
    {
        players[playerID].NewPiece('A'); // places piece 'A' for player 1. 
    }
    else 
    {
        players[playerID].NewPiece('1'); // places piece '1' for player 2.
    }
}

bool Referee::JudgeMove(Movement newMove) 
{
    
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
