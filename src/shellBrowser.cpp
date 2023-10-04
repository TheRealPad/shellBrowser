#include <iostream>
#include "prompt/IPrompt.hpp"
#include "prompt/Prompt.hpp"

void init(std::unique_ptr<ShellBrowser::IPrompt> &prompt)
{
    prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::Prompt("=> "));
}

bool shellBrowser()
{
    std::unique_ptr<ShellBrowser::IPrompt> prompt;

    
    init(prompt);
    prompt->welcome();
    try {
        while (prompt->readUserInput()) {
            std::cout << prompt->getInput() << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}