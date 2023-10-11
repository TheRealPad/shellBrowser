#ifndef IPROMPT_HPP_
#define IPROMPT_HPP_

#include <vector>

namespace ShellBrowser {
    class IPrompt {
        public:
            virtual ~IPrompt() = default;
            virtual bool readUserInput() = 0;
            virtual std::string getInput() = 0;
            virtual void welcome() = 0;
            virtual std::string displayUrls(std::vector<std::string> const &urls) = 0;
            virtual void displayWebPage(std::string const &url) = 0;
    };
}

#endif /* !IPROMPT_HPP_ */