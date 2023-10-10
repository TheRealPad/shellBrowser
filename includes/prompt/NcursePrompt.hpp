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
            void start();
            void end();

        private:
            std::string _prompt;
            std::string _userInput;
    };
}

#endif /* !NCURSEPROMPT_HPP_ */