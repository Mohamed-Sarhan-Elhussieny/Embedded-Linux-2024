#include <iostream>
#include <string>
#include <iostream>
#include <cstdlib> // For system()
#include <thread>  // For sleep simulation
#include <chrono>  // For duration
#include "curl.h"
#include "command.hpp"
#include "server.hpp"

void restartSystem()
{
    // Windows restart command
    system("shutdown /r /t 0");
}

void sleepSystem()
{
    // Windows sleep command
    system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0");
}

COMMAND::COMMAND() {}
COMMAND::~COMMAND() {}

bool COMMAND::open_website(const std::string &website)
{
    std::string command;

    if (website == "Google")
    {
        command = "start \"\" \"https://www.google.com\""; 
    }
    else if (website == "YouTube")
    {
        command = "start \"\" \"https://www.youtube.com\"";
    }
    else if (website == "LinkedIn")
    {
        command = "start \"\" \"https://www.linkedin.com\"";
    }
    else if (website == "github")
    {
        command = "start \"\" \"https://github.com/Mohamed-Sarhan-Elhussieny\"";
    }
    else
    {
        return false;
    }

    int result = std::system(command.c_str());

    if (result == 0)
    {
        std::cout << "Successfully opened " << website << std::endl;
        return true;
    }
 
}

void COMMAND::pc_orders(const std::string &cmd)
{
    cmd.c_str();
    if (cmd == "terminal")
    {
        system("cmd.exe /c start");

        std::cout << "Opening terminal" << std::endl;
    }
    else if (cmd == "shutdown")
    {

        std::cout << "Shutting down PC" << std::endl;
    }
    else if (cmd == "sleep")
    {
        sleepSystem();
        std::cout << "Putting PC to sleep" << std::endl;
    }
    else if (cmd == "restart")
    {

        std::cout << "Restarting PC" << std::endl;
        restartSystem();
    }
  
}
