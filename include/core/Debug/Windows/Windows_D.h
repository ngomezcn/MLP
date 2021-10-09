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

namespace mlp
{
    namespace debug
    {
        class Windows_D
        {

        public:
                std::vector<std::wstring> getList(std::wstring separator = L"\n");
                void printList(bool numerated=false);
                bool isThisWindow(std::wstring tWindow);
        };     
    }
}
