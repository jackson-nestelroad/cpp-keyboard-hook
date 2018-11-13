// Definition file for Error class
#ifndef ERROR_H
#define ERROR_H
#include <iostream>
#include <string>

class Error 
{
   private:
      int code;
      std::string reason;
   public:
      Error(int code = 0, std::string reason = "An unknown error occurred.");
      friend std::ostream &operator<<(std::ostream &stream, const Error &error);
};

#endif