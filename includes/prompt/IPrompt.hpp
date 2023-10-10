#ifndef IPROMPT_HPP_
#define IPROMPT_HPP_

namespace ShellBrowser {
    class IPrompt {
        public:
            virtual ~IPrompt() = default;
            virtual bool readUserInput() = 0;
            virtual std::string getInput() = 0;
            virtual void start() = 0;
            virtual void end() = 0;
    };
}

#endif /* !IPROMPT_HPP_ */