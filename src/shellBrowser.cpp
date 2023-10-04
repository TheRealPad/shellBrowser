#include <iostream>
#include "prompt/IPrompt.hpp"
#include "prompt/Prompt.hpp"
#include "browser/Browser.hpp"

void init(std::unique_ptr<ShellBrowser::IPrompt> &prompt)
{
    prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::Prompt("=> "));
}

bool shellBrowser()
{
    std::unique_ptr<ShellBrowser::IPrompt> prompt;
    ShellBrowser::Browser browser;

    init(prompt);
    prompt->welcome();
    try {
        while (prompt->readUserInput() && prompt->getInput() != "exit") {
            //browser.research(prompt->getInput());
            browser.research("http://example.com/");
        }
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}