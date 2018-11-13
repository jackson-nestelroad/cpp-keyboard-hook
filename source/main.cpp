// Main source file
#include "KeyboardHook.h"
#include "Error.h"

using namespace std;

int main()
{
   // Change text color to green
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

   // The one and only... keyboard hook
   KeyboardHook hook;
   try {

      // Attach the hook
      if (!hook.setHook())
         throw Error{ 10, "Could not set hook." };
      cout << "Success" << endl;

      // Start up the message handler
      MessageHandler handler;
      handler.handle();

      // Remove the hook
      if (!hook.removeHook())
         throw Error{ 20, "Could not remove hook." };
      cout << "Success" << endl;

      system("pause");
   }
   // Print error message
   catch (const Error error)
   {
      cout << error << endl;
   }
}