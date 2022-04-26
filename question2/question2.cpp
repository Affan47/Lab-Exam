// Imports
#include "stdafx.h"
#include <string>
// Imports End


#define BUF_SIZE 1024
DWORD Options(int argc, LPCTSTR argv[], LPCTSTR OptStr, ...);
VOID ReportError(LPCTSTR userMessage, DWORD exitCode, BOOL printErrorMessage);

int _tmain(int argc, LPCTSTR argv[])
{


	TCHAR b[BUF_SIZE] = TEXT("TThis is System Programming Class and we are learning to program using windows api and this will be successful and we will one day become very sucessfull programmers and the world will bow down to us... yeyyyyy...o the custom search engines / location bar shortcuts in your browser of choice. Whenever I want to check string length / byte count, I just enter len some string in my address bar.o the custom search engines / location bar shortcuts in your browser of choice. Whenever I want to check string length / byte count, I just enter len some string in my address bar.o the custom search engines / location bar shortcuts in your browser of choice. Whenever I want to check string length / byte count, I just enter len some string in my address bar.o the custom search engines / location bar shortcuts in your browser of choice. Whenever I want to check string length / byte count, I just enter len some string in my address bar.o the custom search engines / location bar shortcuts in your browser of choice.");
	b[0] = '\n';
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	// Create Handle for file
	hStdOut = CreateFile(argv[1], GENERIC_WRITE,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hStdOut == INVALID_HANDLE_VALUE) {
		ReportError(_T("\nError The File does not Exist"), 0, TRUE);
	}
	else {
		DWORD nOut;
		DWORD dwPos = SetFilePointer(hStdOut, -1024, NULL, FILE_END);
		WriteFile(hStdOut, b, BUF_SIZE, &nOut, NULL);

	}
	return 0;
}