#ifndef PROMPT_HPP_
#define PROMPT_HPP_

#include "IPrompt.hpp"

namespace ShellBrowser {
    class Prompt : public ShellBrowser::IPrompt {
        public:
            Prompt();
            Prompt(std::string prompt);
            ~Prompt();
            void run();
            void welcome();

        private:
            std::string _prompt;
    };
}

#endif /* !PROMPT_HPP_ */