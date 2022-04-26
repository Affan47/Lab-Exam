// Imports
#include "stdafx.h"
#include <string>
// Imports End


#define BUF_SIZE 0x200
DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[])
{



	HANDLE keyboard_handle = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (argc < 2)
	{
		ReportError(_T("\nThis Program requires a file as an input"), 0, TRUE);
		exit(0);
	}
	else
	{

		// Opening Existing File
		hStdOut = CreateFile(argv[1], FILE_APPEND_DATA, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (hStdOut == INVALID_HANDLE_VALUE) {

			// To Print the Message of the error also

			DWORD eMsgLen, errNum = GetLastError();
			LPTSTR lpvSysMsg;
			eMsgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM,
				NULL, errNum, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
				(LPTSTR)&lpvSysMsg, 0, NULL);
			_ftprintf(stderr, _T("%s\n"), lpvSysMsg);
			if (lpvSysMsg != NULL) LocalFree(lpvSysMsg);
			printf("Creating New File");
			hStdOut = CreateFile(argv[1], GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL);
			// Write data to the file
			DWORD nIn, nOut;
			BYTE buffer[BUF_SIZE];
			ReadFile(keyboard_handle, buffer, BUF_SIZE, &nIn, NULL) && (nIn != 0);
			WriteFile(hStdOut, buffer, nIn, &nOut, NULL);


		}
		else {
			DWORD nIn, nOut;
			BYTE buffer[BUF_SIZE];
			ReadFile(keyboard_handle, buffer, BUF_SIZE, &nIn, NULL) && (nIn != 0);
			WriteFile(hStdOut, buffer, nIn, &nOut, NULL);

		}

	}
	CloseHandle(hStdOut);

	return 1;
}