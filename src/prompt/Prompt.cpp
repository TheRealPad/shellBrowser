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

void ShellBrowser::Prompt::welcome()
{
    std::cout << "Welcome to the browser for shell" << std::endl;
}