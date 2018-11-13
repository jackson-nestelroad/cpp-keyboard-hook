// Implementation file for MessageHandler class
#include "MessageHandler.h"
#include "KeyboardHook.h"

// Infinite loop to handle messages
void MessageHandler::handle()
{
   MSG msg;
   while (GetMessage(&msg, KeyboardHook::m_hWnd, 0, 0))
   {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
   }
}

// Handle messages and choose what to do with them
// Return false to intercept them
// Return true to let them through
bool MessageHandler::handleKey(DWORD key)
{
   Sleep(250);
   return true;
}