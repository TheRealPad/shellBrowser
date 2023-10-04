#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <functional>
#include <string>

class Error : public std::exception {
    public:
        enum ErrorType {
            CUSTOM,
            PROMPT
        };
        Error() {};
        Error(std::string const &msg);
        Error(ErrorType const &type);
        ~Error() {};

        const char *what() const noexcept override;
    private:
        ErrorType _error;
        std::string _error_msg;
};

#endif /* !ERROR_HPP_ */