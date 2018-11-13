// Definition file MessageHandler class
#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H
#include <Windows.h>

class MessageHandler
{
   public:
      void handle();
      static bool handleKey(DWORD key);
};

#endif