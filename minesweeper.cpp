#include <windows.h>
#include <iostream>
#include <conio.h>
int main()
{
HWND hWnd;
DWORD pID;
HANDLE hProcess;
DWORD adres=0x1005194;
int buffer;
printf("How many flags?\n");
scanf("%d",&buffer);
hWnd=FindWindow(NULL,"Minesweeper");
GetWindowThreadProcessId(hWnd,&pID);
hProcess=OpenProcess(PROCESS_ALL_ACCESS,false,pID);
if (WriteProcessMemory(hProcess,(LPVOID)adres,&buffer,4,NULL)==0)
{
printf("Error\n");
}
else
{
printf("Success\n");
}
CloseHandle(hProcess);
getch();
return 0;
}
