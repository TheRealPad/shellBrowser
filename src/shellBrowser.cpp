#include <iostream>
#include <memory>
#include <ncurses.h>
#include "prompt/IPrompt.hpp"
#include "prompt/Prompt.hpp"
#include "prompt/NcursePrompt.hpp"
#include "browser/Browser.hpp"

void init(std::unique_ptr<ShellBrowser::IPrompt> &prompt)
{
    prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::NcursePrompt("=> "));
}

bool shellBrowser()
{
    std::unique_ptr<ShellBrowser::IPrompt> prompt;
    ShellBrowser::Browser browser;

    init(prompt);
    prompt->start();
    try {
        while (prompt->readUserInput() && prompt->getInput() != "exit") {
            browser.research(prompt->getInput());
            for (int i = 0; i != browser.getUrls().size(); ++i)
                std::cout << browser.getUrls().at(i) << std::endl;
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        prompt->end();
        return false;
    }
    prompt->end();
    return true;
}