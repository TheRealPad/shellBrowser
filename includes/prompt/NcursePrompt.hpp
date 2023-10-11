#ifndef NCURSEPROMPT_HPP_
#define NCURSEPROMPT_HPP_

#include <string>
#include "IPrompt.hpp"

namespace ShellBrowser {
    class NcursePrompt : public ShellBrowser::IPrompt {
        public:
            NcursePrompt();
            NcursePrompt(std::string prompt);
            ~NcursePrompt();
            bool readUserInput();
            std::string getInput();
            void welcome();
            std::string displayUrls(std::vector<std::string> const &urls);
            void displayWebPage(std::string const &url);

        private:
            std::string _prompt;
            std::string _userInput;
            unsigned int _selectedUrl;
    };
}

#endif /* !NCURSEPROMPT_HPP_ */