#ifndef BROWSER_HPP_
#define BROWSER_HPP_

#include <string>
#include <vector>

namespace ShellBrowser
{
    class Browser
    {
    public:
        Browser();
        ~Browser();
        void research(std::string subject);
        std::string getFullResult();
        std::vector<std::string> getUrls();

    private:
        std::string _result;
        std::vector<std::string> _urls;
    };
}

#endif /* !BROWSER_HPP_ */