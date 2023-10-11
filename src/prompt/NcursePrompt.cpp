#include <iostream>
#include <ncurses.h>
#include "prompt/NcursePrompt.hpp"
#include "error/Error.hpp"
#include "utils.hpp"

ShellBrowser::NcursePrompt::NcursePrompt()
{
    this->_prompt = "";
    this->_selectedUrl = 0;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

ShellBrowser::NcursePrompt::NcursePrompt(std::string prompt)
{
    this->_prompt = prompt;
    this->_selectedUrl = 0;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
}

ShellBrowser::NcursePrompt::~NcursePrompt()
{
    endwin();
}

std::string getstring()
{
    std::string input;
    int ch;

    nocbreak();
    echo();
    while ((ch = getch()) != '\n') {
        if (ch == EOF) {
            endwin();
            input.clear();
            return "";
        }
        //printf("%d", ch);
        input.push_back(ch);
    }
    cbreak();
    return input;
}

bool ShellBrowser::NcursePrompt::readUserInput()
{
    printw("%s", this->_prompt.c_str());
    this->_userInput.clear();
    this->_userInput = getstring();
    return true;
}

std::string ShellBrowser::NcursePrompt::getInput()
{
    return this->_userInput;
}

void ShellBrowser::NcursePrompt::welcome()
{
    printw("Welcome to the browser for shell\n");
    printw("Use CTRL+CLICK if you want to access the link in a web browser\n");
    printw("Write exit to leave\n");
    refresh();
}

std::string ShellBrowser::NcursePrompt::displayUrls(std::vector<std::string> const &urls)
{
    int ch = 0;

    clear();
    for (int i = 0; i != urls.size(); ++i) {
        if (i == this->_selectedUrl)
            printw("-> ");
        printw("%s\n", urls.at(i).c_str());
    }
    refresh();
    ch = getch();
    if (ch == KEY_UP && this->_selectedUrl == 0)
        this->_selectedUrl = urls.size();
    if (ch == KEY_UP && this->_selectedUrl != 0)
        --this->_selectedUrl;
    if (ch == KEY_DOWN && this->_selectedUrl != urls.size())
        ++this->_selectedUrl;
    if (ch == KEY_DOWN && this->_selectedUrl == urls.size())
        this->_selectedUrl = 0;
    if (ch == '\n') {
        clear();
        return urls.at(this->_selectedUrl);
    }
    return this->displayUrls(urls);
}

void ShellBrowser::NcursePrompt::displayWebPage(std::string const &url)
{
    printw("display: %s\n", url.c_str());
    getch();
    clear();
}
