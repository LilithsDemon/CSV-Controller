#include <iostream>
#include <cstring>
#include <string.h>
#include <vector>

int main()
{
    std::vector<std::string> commands;
    std::string seperator = " -";
    std::string file = "";
    std::string user_input = "";

    bool run = true;

    std::cout << ":<==< CSV Controller >==>:\n";
    while(run == true)
    {
        user_input = "";
        std::cout << ">>: ";
        std::getline(std::cin, user_input);

        if (user_input == "q" || user_input == "quit")
        {
            exit(0);
        }

        int last_stop = 0;
        std::string current_text = "";
                break;

        for (int i = 0; i < (user_input.length() - seperator.length()); i++)
        {
            current_text = user_input.substr(i, seperator.length());
            if(current_text == seperator)
            {
                commands.push_back(user_input.substr(last_stop, i - last_stop));
                current_command++;
                last_stop = i+seperator.length();
            }
            commands.push_back(user_input.substr(last_stop, i - last_stop + seperator.length() + 1));
        }

        std::string file_name = "";

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i].substr(0, 4) == "file")
            {
                file_name = commands[i].substr(3);
            }
        }
                
        std::cout << file_name;

        for (int i = 0; i < 16; i++)
        {
            if(commands[i] == "")
            {
                break;
            }

            std::cout << commands[i] << "\n";
        }
    }
    std::cout << "\n";
}