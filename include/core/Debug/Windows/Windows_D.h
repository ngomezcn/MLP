/**
 * @file Windows_D.h
 * @author ngomez
 * @date 90/10/2021
 * @brief File containing example of doxygen usage for quick reference.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

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
        /**
         * @brief Library for debugging open operating system windows
         * 
         * @code
         * // Initialization example
         * MLP::debug::Windows_D wDebug();
         * @endcode
         * 
         * @warning  Only Windows 7 and above supported
         */
        class Windows_D
        {

        public:
            
                /**
                   * @brief Returns a list containing all open windows.
                   * 
                   * @code
                   *  // usage example
                   *  MLP::debug::Windows_D wDebug();
                   *  wDebug.getList(L"\n");                   * 
                   * @endcode
                   * 
                   * @param param1 Optional parameter to determine if you want to add some character at the end of each element, by default it is (L ",")
                   * @return std::vector<std::wstring>
                   */
                std::vector<std::wstring> getList(std::wstring separator = L",");

                /**
                   * @brief Print all open windows.
                   *
                   * @code
                   *  // usage example
                   *  MLP::debug::Windows_D wDebug();
                   *  wDebug.printList(true);                   
                   * @endcode
                   *
                   * @param param1 Optional parameter, true to enumarte windows [0..N], by default is false
                   */
                void printList(bool numerated=false); 

                /**
                   * @brief Check if window is opened.
                   *
                   * 
                   * @code
                   *  // usage example
                   *  MLP::debug::Windows_D wDebug();
                   *  bool isOpen wDebug.isOpen(L"Spotify");
                   * @endcode
                   *
                   * @param param1 Get the name of the window to check as a parameter
                   * @warning The name must be the same to the window to search. (character by character)
                   * @return bool
                   */
                bool isOpen(std::wstring tWindow); 
        };     
    }
}
