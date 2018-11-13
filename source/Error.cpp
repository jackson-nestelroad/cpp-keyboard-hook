// Implementation file for Error class
#include "Error.h"

// Constructor
Error::Error(int code, std::string reason)
{
   this->code = code;
   this->reason = reason;
}

// << operator overload
std::ostream &operator<<(std::ostream &stream, const Error &error)
{
   stream << "ERROR: " << error.reason;
   return stream;
}