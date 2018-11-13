// Definition file for KeyboardHook class
#ifndef KEYBOARDHOOK_H
#define KEYBOARDHOOK_H
#include <Windows.h>
#include "MessageHandler.h"
#define WM_KEYINPUT (WM_USER + 102)

class KeyboardHook
{
   private:
      static HHOOK m_hHook;
      static HWND m_hWnd;

      HMODULE WINAPI ModuleFromAddress(PVOID pv);
      static LRESULT CALLBACK HookCallback(int nCode, WPARAM wParam, LPARAM lParam);
      BOOL WINAPI SetLowKeyboardHook(BOOL bInstall, DWORD dwThreadId, HWND hWndCaller);

      HOOKPROC hookproc = &HookCallback;

   public:
      KeyboardHook();

      BOOL __stdcall setHook();
      BOOL __stdcall removeHook();

      friend void MessageHandler::handle();
};

#endif
