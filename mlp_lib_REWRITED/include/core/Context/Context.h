#pragma once
#include <iostream>

#ifdef _WIN32

#include <Windows.h>
#include <vector>
#include <Windows.h>
#include <TlHelp32.h>
#include <tchar.h>

#endif

#ifdef linux
// No support
#endif

namespace MLP {

    class Context {

        public:
            unsigned __int64  moduleAddress {NULL};
            std::string windowName;
            std::string moduleName;

            HANDLE  pHandle {NULL};
            unsigned long pID {NULL};
	        HWND hGameWindow {NULL};

            Context(std::string windowName, std::string moduleName);   // This is the constructor
            
            void getInfo();

        private:
            unsigned __int64 getModuleBaseAddress();

    };  
};
 

