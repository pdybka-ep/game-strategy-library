/*
 * FileAccessException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef FILEACCESSEXCEPTION_HPP_
#define FILEACCESSEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    class FileAccessException : public std::exception {
    public:
        FileAccessException();
        virtual ~FileAccessException() throw();

        virtual std::string toString() const {
            return std::string("Cannot access the file");
        }
    };

}

#endif /* FILEACCESSEXCEPTION_HPP_ */
