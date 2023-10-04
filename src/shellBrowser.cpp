#include <iostream>
#include "prompt/IPrompt.hpp"
#include "prompt/Prompt.hpp"

bool shellBrowser()
{
    std::unique_ptr<ShellBrowser::IPrompt> prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::Prompt("=> "));
    
    prompt->welcome();
    try {
        prompt->run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}