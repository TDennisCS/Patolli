#include "objects.h"



int main()
{
    
    Referee pat; // initalizeing the ref obj for patolli game

    do  // round loop that terminates when a player has won 
    {
        for (int i = 0; i < 2; i++) // turn loop for each player. 
        {
            
            do // special condition if the piece lands on a red square and gets another turn. 
            {
                pat.NewTurn(); // resets all important conditions. 
                
                if (pat.GetRound() == 0) // only executes if the game is on the first round. round == 0.
                {
                    pat.FirstTurn(i); // each player gets the same action for the first turn of the game. 
                }

                // executes if the game has moved past the first round. round > 0.

                pat.RollDice(i); // rolls the dice in the player obj and sets the player roll.
                pat.PickPiece(i);
                if (pat.Forfeit() == false) // checks if player decided to forfeit turn. if not then executes rest of tasks. 
                {
                    pat.GameAction(i);
                }
            } while (pat.GetChangeTurn() == false); // should always be turn at the start of the loop. 
            
            pat.CheckScoreboard(i)

        }

    }
    while (pat.CheckWin() == false);

    return 0; 
}