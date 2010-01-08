/*
 * FileAccessException.hpp
 * Author: Michal Kolodziejski
 */

#ifndef FILEACCESSEXCEPTION_HPP_
#define FILEACCESSEXCEPTION_HPP_

#include <exception>
#include <string>

namespace library {

    /**
     * Exception signalizing problems with access to a file
     * @author Michał Kołodziejski
     */
    class FileAccessException : public std::exception {
    public:
        /**
         * Creates exception
         */
        FileAccessException();

        /**
         * Destroys exception
         */
        virtual ~FileAccessException() throw();

        /**
         * Returns exception's description
         * @return exception's description
         */
        virtual std::string toString() const {
            return std::string("Cannot access the file");
        }
    };

}

#endif /* FILEACCESSEXCEPTION_HPP_ */
