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

void ShellBrowser::Prompt::run()
{
    std::string input;

    std::cout << this->_prompt;
    while (std::getline(std::cin, input)) {
        std::cout << input << std::endl;
        std::cout << this->_prompt;
        std::cout << getRequest("www.google.com/search?q=pad") << std::endl;
    }
}

void ShellBrowser::Prompt::welcome()
{
    std::cout << "Welcome to the browser for shell" << std::endl;
}