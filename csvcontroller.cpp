#include <iostream>
#include <fstream>
#include <cstring>
#include <string.h>
#include <vector>

std::vector<std::string> splitCommand(std::string command, std::string seperator)
{
    std::vector<std::string> commands;
    int last_stop = 0;
    std::string current_text = "";
    int current_command = 0;

    for (int i = 0; i < (command.length() - seperator.length()); i++)
    {
        current_text = command.substr(i, seperator.length());
        if(current_text == seperator)
        {
            commands.push_back(command.substr(last_stop, i - last_stop));
            current_command++;
            last_stop = i+seperator.length();
        }
    }
    commands.push_back(command.substr(last_stop));
    if (commands.size() == 0)
    {
        commands.push_back(command);
    }
    
    return commands;
}

void writeToFile(std::string text, std::string file_name)
{
    std::ofstream file(file_name);
    file << text;
    file.close();
}

std::vector<std::vector<std::string>> readFile(std::string file_name)
{
    std::vector<std::string> file_text;
    std::ifstream file(file_name);
    std::string text = "";
    std::string seperator = ",";
    std::vector<std::vector<std::string>> split_text;

    while (getline(file, text))
    {
        file_text.push_back(text);
    }

    file.close();

    for(int i = 0; i < file_text.size(); i++)
    {
        split_text.push_back(splitCommand(file_text[i], seperator));
    }

    return split_text;
}

int main()
{
    std::string file_name = "";
    std::string seperator = " -";
    std::string user_input = "";
    std::vector<std::vector<std::string>> file_data;
    bool last_updated = false;
    int col = 0;
    int row = 0;

    bool run = true;

    std::cout << ":<==< CSV Controller >==>:\n";
    while(run == true)
    {
        user_input = "";
        std::cout << ">>: ";
        std::getline(std::cin, user_input);

        std::vector<std::string> commands = splitCommand(user_input, seperator);

        
        std::string val = "";

        for (int i = 0; i < commands.size(); i++)
        {
            if (commands[i].substr(0, 4) == "file")
            {
                file_name = commands[i].substr(5);
                file_data = readFile(file_name);
            }
            if (commands[i].substr(0,4) == "read")
            {
                if(file_name == "")
                {
                    std::cout << "\nNo file selected please select a file and retry\n";
                    break;
                }
                else
                {
                    for(int i = 0; i < file_data.size(); i++)
                    {
                        for(int j = 0; j < file_data[i].size(); j++)
                        {
                            std::cout << file_data[i][j] << "\t";
                        }
                        std::cout << "\n";
                    }
                }
            }
            if (commands[i].substr(0, 6) == "append")
            {
                if(file_name == "")
                {
                    std::cout << "\nNo file selected please select a file and retry\n";
                    break;
                }
                if (last_updated == false && col != 0)
                {
                    //check column position
                    //if the next value does not exist or is a ,
                    //Then put the new value
                }
                if (last_updated == true)
                {
                    //if last value is, or does not exist
                    //Put the new value
                }
            }
            if (commands[i].substr(0,3) == "col")
            {
                col = stoi(commands[i].substr(4));
                last_updated = false;
            }
            if (commands[i].substr(0,3) == "row")
            {
                row = stoi(commands[i].substr(4));
                last_updated = true;
            }
            if (commands[i].substr(0, 3) == "val")
            {
                val = commands[i].substr(4);
            }
            if (commands[i] == "q" || commands[i] == "quit")
            {
                exit(0);
            }
        }
    }
    std::cout << "\n";
}