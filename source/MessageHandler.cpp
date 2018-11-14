// Implementation file for MessageHandler class
#include "MessageHandler.h"
#include "KeyboardHook.h"
#include <iostream>
BOOL MessageHandler::ctrlKey;
BOOL MessageHandler::interceptKeys;

// Constructor
MessageHandler::MessageHandler()
{
   ctrlKey = FALSE;
   interceptKeys = TRUE;
}

// Infinite loop to run the loop
void MessageHandler::handle()
{
   MSG msg;

   // We can send messages here if we want from KeyboardHook::HookCallBack using ::PostMessage
   while (::GetMessage(&msg, KeyboardHook::m_hWnd, 0, 0))
   {
      // -1 means kill the hook
      if (msg.wParam == -1)
         break;

      ::TranslateMessage(&msg);
      ::DispatchMessage(&msg);
   }
}

// Choose what to do with key events
WORD MessageHandler::handleKey(DWORD key)
{
   // CTRL command is being sent
   if (ctrlKey)
      return MessageHandler::ctrlCommand(key);

   // keyAction() tells us how the key impacts the internal code
   WORD action = MessageHandler::keyAction(key);

   // We are intercepting keys
   if (interceptKeys)
   {
      // keyAction() tells us what to do
      if(action != NA_KEY)
         return action;

      // Intercept the key in a default manner
      return MessageHandler::interceptKey(key);
   }
      
   // Send the key as normal
   return PASS_KEY;
}

// Function to decide what to do with individual key events
WORD MessageHandler::keyAction(DWORD key)
{
   switch (key)
   {
      // CTRL (Starts a command)
      case 162: ctrlKey = TRUE; return EAT_KEY;

      // Any other key
      default: return NA_KEY; break;
   }
}
// Function to intercept the key however we want
WORD MessageHandler::interceptKey(DWORD key)
{
   // Sleep(100);
   srand((unsigned int) time(NULL));
   if (!(rand() % 2))
      return EAT_KEY;

   return PASS_KEY;
}

// Commands prompted by the CTRL key being pressed
WORD MessageHandler::ctrlCommand(DWORD key)
{
   ctrlKey = FALSE;
   switch (key)
   {
      // ~ (Kills the hook and stops the program)
      case 192: return KILL_KEY; break;

      // - (Stops intercepting keys)
      case 189: interceptKeys = FALSE; return EAT_KEY; break;

      // + (Starts intercepting keys)
      case 187: interceptKeys = TRUE; return EAT_KEY;  break;

      // Any other key
      default: return PASS_KEY; break;
   }
}