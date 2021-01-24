//Console app to control RGB LED to shine Red, Green, or Blue

#include <iostream>
#include <wiringPi.h>

#define RED 0
#define BLUE 1
#define GREEN 2
#define YELLOW 3
#define WHITE 4

int main()
{
    if(wiringPiSetup() != 0)
    {
        std::cout << "wiringPi failed to setup correctly.. Exiting program.\n";
    }
    else
    {
        std::cout << "wiringPi Initialized succesfully.. Welcome \n";
    }

    pinMode (RED, OUTPUT);
    pinMode (BLUE, OUTPUT);
    pinMode (GREEN, OUTPUT);
    pinMode (YELLOW, OUTPUT);
    pinMode (WHITE, OUTPUT);

    char user_selection = 0;
    int color = -1;

    while(user_selection != 'q')
    {
        std::cout << "Please select which color you would like to shine or type q to quit. \n r: red \n g: green \n b: blue\n q: quit \n";
        std::cin >> user_selection;

        switch (user_selection)
        {
        case 'r':
            color = RED;
            break;
        
        case 'g':
            color = GREEN;
            break;

        case 'b':
            color = BLUE;
            break;

        case 'q':
            break;

        default:
            std::cout << "Invalid Input. Please select r, g, or b\n"; 
            break;
        }
        digitalWrite(RED, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(BLUE, LOW);

        digitalWrite(color, HIGH);

    }
    digitalWrite(RED, LOW);
    digitalWrite(GREEN, LOW);
    digitalWrite(BLUE, LOW);

    return 0;
}