#include <iostream>
#include "prompt/Prompt.hpp"
#include "error/Error.hpp"
#include "utils.hpp"

ShellBrowser::Prompt::Prompt()
{
    this->_prompt = "";
}

ShellBrowser::Prompt::Prompt(std::string prompt)
{
    this->_prompt = prompt;
}

ShellBrowser::Prompt::~Prompt()
{
}

bool ShellBrowser::Prompt::readUserInput()
{
    std::cout << this->_prompt;
    return std::getline(std::cin, this->_userInput) ? true : false;
}

std::string ShellBrowser::Prompt::getInput()
{
    return this->_userInput;
}

void ShellBrowser::Prompt::start()
{
    std::cout << "Welcome to the browser for shell" << std::endl;
    std::cout << "Use CTRL+CLICK if you want to access the link in a web browser" << std::endl;
}

void ShellBrowser::Prompt::end()
{
    std::cout << "See you!!" << std::endl;
}