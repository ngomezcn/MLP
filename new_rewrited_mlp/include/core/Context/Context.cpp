
#pragma once
#include "Context.h"
#include <iostream>

#ifdef _WIN32
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#endif

#ifdef linux
// No support
#endif

namespace MLP {

    Context::Context(
        std::string windowName,
        std::string moduleName
        ): windowName(windowName), moduleName(moduleName) {

            #ifdef _WIN32

                std::string s = windowName;
                std::wstring stemp = std::wstring(s.begin(), s.end());
                LPCWSTR sw = stemp.c_str();


                // Building contest stage
                GetWindowThreadProcessId(FindWindow(NULL, sw), &pID);
                pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
                moduleAddress = getModuleBaseAddress();
                
            #endif
                        
            #ifdef linux
             // No support
            #endif

    }

    void Context::getInfo()
    {
        //std::cout << 

    }

    unsigned __int64 Context::getModuleBaseAddress()
    {
        #ifdef _WIN32
            HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID);
            MODULEENTRY32 ModuleEntry32 = { 0 };
            ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

            std::string s = moduleName;
            std::wstring stemp = std::wstring(s.begin(), s.end());
            LPCWSTR sw = stemp.c_str();

            /*if (Module32First(hSnapshot, &ModuleEntry32))
            {
                do {

                    if (_tcscmp(ModuleEntry32.szModule, sw) == 0)
                    {
                        return (DWORD_PTR)ModuleEntry32.modBaseAddr;
                        break;
                    }
                } while (Module32Next(hSnapshot, &ModuleEntry32));

            }*/
            CloseHandle(hSnapshot);
        #endif
        #ifdef linux
        // No support
        #endif

            return 0;
    }
};