#include "objects.h"



int main()
{
    // Dice object 
    default_random_engine generator;
    uniform_int_distribution<int> distribution(1,6);
    auto dice = bind( distribution, generator);

    int roll = dice();

    for (int i = 0; i < 10; i++)
    {
        cout << roll << endl;
    }
 


    return 0; 
}