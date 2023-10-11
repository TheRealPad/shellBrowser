#include <iostream>
#include <memory>
#include "prompt/IPrompt.hpp"
#include "prompt/Prompt.hpp"
#include "prompt/NcursePrompt.hpp"
#include "browser/Browser.hpp"
#include "shellBrowser.hpp"

void init(std::unique_ptr<ShellBrowser::IPrompt> &prompt, std::string const &params)
{
    if (params == NO_LIB)
        prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::Prompt("=> "));
    else if (params == NCURSES_LIB)
        prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::NcursePrompt("=> "));
    else
        prompt = std::unique_ptr<ShellBrowser::IPrompt>(new ShellBrowser::Prompt("=> "));
}

void help()
{
    std::cout << "Welcome to shellBrowser!" << std::endl;
    std::cout << "run:\t./shellBrowser [lib]" << std::endl << std::endl;
    std::cout << "\tnothing or unknow: run directly on the shell" << std::endl;
    std::cout << "\t--ncurses: use ncurses" << std::endl;
}

bool shellBrowser(std::string const &params)
{
    std::unique_ptr<ShellBrowser::IPrompt> prompt;
    ShellBrowser::Browser browser;
    std::string selectedUrl;

    if (params == "--help" || params == "-h") {
        help();
        return true;
    }
    init(prompt, params);
    prompt->welcome();
    try {
        while (prompt->readUserInput() && prompt->getInput() != "exit") {
            browser.research(prompt->getInput());
            selectedUrl = prompt->displayUrls(browser.getUrls());
            if (selectedUrl.size())
                prompt->displayWebPage(selectedUrl);
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}