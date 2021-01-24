//Console app to shine a user defined sequence of red, blue, green, white LED

#include <iostream>
#include <wiringPi.h>
#include <vector>

#define RED 0
#define GREEN 1
#define BLUE 2
#define YELLOW 3
#define WHITE 4

int parse_sequence(std::string string_sequence, std::vector<int> &color_sequence)
{

    int string_length = string_sequence.length();

    int error = 0;
    if(string_length == color_sequence.size())
    {        
        int color = -1;
        for(int i = 0; i < string_length; i++)
        {
            switch (string_sequence[i])
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

            case 'y':
                color = YELLOW;
                break;

            case 'w':
                color = WHITE;
                break;

            default:
                error = 1; 
                break;
            }

            color_sequence[i] = color;
        }
    }
    else
    {
        error = 2;
    }

    return error;
}

int play_sequence(std::vector<int> &color_sequence, int interval_time)
{
    for(int color : color_sequence)
    {
        for(int i = 0; i < 5; i++)
        {
            if(i == color)
            {
                digitalWrite(i, HIGH);
            }
            else
            {
                digitalWrite(i, LOW);
            }
        }
        delay(interval_time);
    }
}

void set_all_low()
{
    for(int i = 0; i < 5; i++)
    {
        digitalWrite(i, LOW);
    }
}

int main()
{
    if(wiringPiSetup() != 0)
    {
        std::cout << "wiringPi failed to setup correctly.. Exiting RGBSequence.\n";
    }
    else
    {
        std::cout << "wiringPi Initialized succesfully.. Welcome to RGBSequence! \n";
    

        pinMode (RED, OUTPUT);
        pinMode (GREEN, OUTPUT);
        pinMode (BLUE, OUTPUT);
        pinMode (YELLOW, OUTPUT);
        pinMode (WHITE, OUTPUT);

        std::string sequence;
        std::string time_input;
        int interval_time = -1;
        int color = -1;
        int error = 0;

        while(sequence != "q")
        {
            set_all_low();

            std::cout << "Please input the sequence of colors which you would like to play. \nr: red \ng: green \nb: blue\ny: yellow \nw: white \nq: quit \n";
            std::cin >> sequence;
            
            if(sequence != "q")
            {
                std::cout << "Please input how long (in ms) you would like each color in the sequence to shine for\n";
                std::cin >> time_input;

                std::vector<int> color_sequence(sequence.length(), 0);
                error = parse_sequence(sequence, color_sequence);
                interval_time = std::stoi(time_input);

                if(error == 0)
                {
                    play_sequence(color_sequence, interval_time);
                }
                else
                {
                    std::cout << "Error of code " << error << " occured \n"; 
                }
            }
            
            // for(int color : color_sequence)
            //     std::cout << std::to_string(color);
            
            set_all_low();
        }
    }

    return 0;
}