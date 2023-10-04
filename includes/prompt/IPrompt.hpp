#ifndef IPROMPT_HPP_
#define IPROMPT_HPP_

namespace ShellBrowser {
    class IPrompt {
        public:
            virtual ~IPrompt() = default;
            virtual void run() = 0;
            virtual void welcome() = 0;
    };
}

#endif /* !IPROMPT_HPP_ */