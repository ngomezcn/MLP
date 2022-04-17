#pragma once
#include "Windows_D.h"
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

namespace mlp
{
	namespace debug
	{
		BOOL CALLBACK enumVisiWindow(HWND hwnd, LPARAM lParam)
		{
			const DWORD TITLE_SIZE = 1024;
			WCHAR windowTitle[TITLE_SIZE];

			GetWindowTextW(hwnd, windowTitle, TITLE_SIZE);

			int length = ::GetWindowTextLength(hwnd);
			std::wstring title(&windowTitle[0]);
			if (!IsWindowVisible(hwnd) || length == 0 || title == L"Program Manager") {
				return TRUE;
			}

			// Retrieve the pointer passed into this callback, and re-'type' it.
			// The only way for a C API to pass arbitrary data is by means of a void*.
			std::vector<std::wstring>& titles =
				*reinterpret_cast<std::vector<std::wstring>*>(lParam);
			titles.push_back(title);

			return TRUE;
		}

		std::vector<std::wstring> Windows_D::getList(std::wstring separator)
		{
			std::vector<std::wstring> wList;
			EnumWindows(enumVisiWindow, reinterpret_cast<LPARAM>(&wList));
			return wList;
		}

		void Windows_D::printList(bool numerated)
		{
			std::vector<std::wstring> wList;
			EnumWindows(enumVisiWindow, reinterpret_cast<LPARAM>(&wList));
			std::cout << "[Windows found]" << std::endl;

			for (int i = 0; i < wList.size(); i++)
			{
				if (numerated)
				{
					std::wcout << i << L". " << wList[i] << std::endl;
				}
				else
				{
					std::wcout << wList[i] << std::endl;
				}
			}
			std::cout << "[A total of " << wList.size() << " windows have been found]" << std::endl;
		}

		bool Windows_D::isThisWindow(std::wstring tWindow)
		{
			std::vector<std::wstring> os_windows = getList();

			for (int i = 0; i < os_windows.size(); i++)
			{
				if (tWindow == os_windows[i])
				{
					return true;
				}
			}			

			return false;
		}	
	}
}