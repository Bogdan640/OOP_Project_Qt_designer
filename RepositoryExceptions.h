#pragma once
#include <exception>
#include <string>

class FileException : public std::exception
{
protected:
    std::string message;

public:
    FileException(const std::string& msg);
    virtual const char* what();
};

class RepositoryException : public std::exception
{
protected:
    std::string message;

public:
    RepositoryException();
    RepositoryException(const std::string& msg);
    virtual ~RepositoryException() {}
    virtual const char* what();
};

class DuplicateCoatException : public RepositoryException
{
    const char* what();
};



class InvalidInputException : public std::exception {
private:
    std::string message;

public:
    InvalidInputException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};
