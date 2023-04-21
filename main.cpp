#include "objects.h"



int main()
{
    
    Referee pat; // initalizeing the ref obj for patolli game
do 
{
    if (pat.GameCounter() != 0) //* grabs the game count variable.  only executes when higher than 0. meaning new game. 
    {
        pat.NewGame(); //* resets all variables 
    }
    do  // round loop that terminates when a player has won 
    {
        for (int i = 0; i < 2; i++) // turn loop for each player. 
        {
            
            do // special condition if the piece lands on a red square and gets another turn. 
            {   
                if (pat.GetRound() != 0) //* grabs the round count variable. executes when not on first round. 
                {
                    pat.NewTurn(); //* resets all important conditions. 
                    
                    pat.RollDice(i); //* rolls the dice in the player obj and sets the player roll.
                    
                    pat.PickPiece(i); //* generates legal options for player then prompts for action. sets the current action option. 
                
                if (pat.Forfeit() == false) //* checks if player decided to forfeit turn. if not then executes rest of tasks. 
                {
                    pat.GameAction(i); //* does action based on current action variable. 
                }   
                }
                else
                {
                    pat.FirstTurn(i); //* each player gets the same action for the first turn of the game. 
                }

                // executes if the game has moved past the first round. round > 0.

               
            } while (pat.GetChangeTurn() == false); //* should always be turn at the start of the loop. 
            
            pat.CheckScoreboard(i); //* checks if a player has reached the scorelimit. then updates winner variable. 

        }
        pat.NextRound(); //*  Increaments the round counter. 

    }
    while (pat.CheckWin() == false); //* checks if anyone has won the game. 
    
    pat.UserOptions(); //* prompts the user for next action.  then sets the exit condition based off user input. 
} 
while (pat.Exit()==false); //* grabs the exit conditon variable.  if true exits the program. 

    return 0; 
}