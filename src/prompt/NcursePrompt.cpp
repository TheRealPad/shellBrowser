#include <iostream>
#include "prompt/NcursePrompt.hpp"
#include "error/Error.hpp"
#include "utils.hpp"

ShellBrowser::NcursePrompt::NcursePrompt()
{
    this->_prompt = "";
}

ShellBrowser::NcursePrompt::NcursePrompt(std::string prompt)
{
    this->_prompt = prompt;
}

ShellBrowser::NcursePrompt::~NcursePrompt()
{
}

bool ShellBrowser::NcursePrompt::readUserInput()
{
    std::cout << this->_prompt;
    return std::getline(std::cin, this->_userInput) ? true : false;
}

std::string ShellBrowser::NcursePrompt::getInput()
{
    return this->_userInput;
}

void ShellBrowser::NcursePrompt::start()
{
    std::cout << "Welcome to the browser for shell" << std::endl;
    std::cout << "Use CTRL+CLICK if you want to access the link in a web browser" << std::endl;
}

void ShellBrowser::NcursePrompt::end()
{
    std::cout << "See you!!" << std::endl;
}