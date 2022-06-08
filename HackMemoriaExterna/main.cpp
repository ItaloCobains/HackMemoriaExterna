#include <Windows.h>

int main(int argc, char** argv) {
	HWND wesnoth_window = FindWindow(NULL, L"BrawlhallaGame");

	DWORD process_id = 0;
	GetWindowThreadProcessId(wesnoth_window, &process_id);

	HANDLE wesnoth_process = OpenProcess(PROCESS_ALL_ACCESS, true, process_id);

	DWORD gold_value = 0;
	SIZE_T bytes_read = 0;
	ReadProcessMemory(wesnoth_process, (void*)0x31570D64, &gold_value, 4, &bytes_read);
	return 0;
}