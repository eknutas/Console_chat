/* main.cpp Console_chat */

#include "Chat.h"

int main()
{
    Chat chat;
    while (true)
    {
        char mode;
        std::cout << "\nEnter 1 to enter the chat \nEnter 2 to register in the chat \nEnter 3 to exit the program \n";
        std::cin >> mode;
        try
        {
            switch (mode)
            {
            case '1':   //Entering the chat
                chat.logIn();
                break;
            case '2':   //New User Registration
                chat.checkIn();
                break;
            case '3':   //Exiting the program
                std::cout << "Goodbye!" << '\n';
                return 0;
            default:
                throw "Wrong enter, please re-enter!";
            }
        }
        catch (const char* exception)
        {
            std::cerr << "Error: " << exception << '\n';
        }
    }
}
