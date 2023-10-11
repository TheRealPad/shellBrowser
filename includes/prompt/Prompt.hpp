#ifndef PROMPT_HPP_
#define PROMPT_HPP_

#include "IPrompt.hpp"

namespace ShellBrowser {
    class Prompt : public ShellBrowser::IPrompt {
        public:
            Prompt();
            Prompt(std::string prompt);
            ~Prompt();
            bool readUserInput();
            std::string getInput();
            void welcome();
            std::string displayUrls(std::vector<std::string> const &urls);
            void displayWebPage(std::string const &url);

        private:
            std::string _prompt;
            std::string _userInput;
    };
}

#endif /* !PROMPT_HPP_ */