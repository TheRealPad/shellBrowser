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
    std::cout << "Use CTRL+CLICK if you want to access the link in a web browser" << std::endl;
    std::cout << "Write exit to leave" << std::endl;
}

std::string ShellBrowser::Prompt::displayUrls(std::vector<std::string> const &urls)
{
    std::string entry;
    unsigned int index;

    for (int i = 0; i != urls.size(); ++i)
        std::cout << i + 1 << ". " << urls.at(i).c_str() << std::endl;
    std::cout << "Please select and url [1" << "-" << urls.size() << "] or use q to stop research: ";
    std::getline(std::cin, entry);
    std::cout << entry << std::endl;
    try {
        index = stoi(entry);
    } catch(const std::exception& e) {
        return "";
    }
    if (index > urls.size())
        return "";
    return urls.at(index - 1);
}

void ShellBrowser::Prompt::displayWebPage(std::string const &url)
{
    std::cout << url << std::endl;
}