// Main source file
#include "KeyboardHook.h"
#include "Error.h"

using namespace std;

// Using WinMain() removes any terminal opening
// int main()
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow)
{
   // SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);

   // The one and only... keyboard hook
   KeyboardHook hook;
   try {

      // Attach the hook
      if (!hook.setHook())
         throw Error{ 10, "Could not set hook." };
      cout << "Hook attached." << endl;

      // Start up the message handler
      MessageHandler handler;
      handler.handle();

      // Remove the hook completely
      if (!hook.removeHook())
         throw Error{ 20, "Could not remove hook." };
      cout << "Hook removed." << endl;
   }
   // Print error message
   catch (const Error error)
   {
      cout << error << endl;
   }

   return 0;
}