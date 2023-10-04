#include "error/Error.hpp"

Error::Error(std::string const &msg)
{
    this->_error_msg = msg;
    this->_error = ErrorType::CUSTOM;
}

Error::Error(ErrorType const &type)
{
    this->_error = type;
}

const char *Error::what() const noexcept
{
    if (this->_error == ErrorType::CUSTOM)
        return this->_error_msg.c_str();
    if (this->_error == ErrorType::PROMPT)
        return "Error with prompt";
    return "Unknow error";
}