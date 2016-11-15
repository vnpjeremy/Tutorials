/* Client */
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <iostream>

int main()
{
    WSAData wsadata;                     //Populate this by starting up winsock
    WORD    dllversion = MAKEWORD(2, 1); //Ugh okay so WORD == unsigned short. Useless typedef.
    if(WSAStartup(dllversion, &wsadata) != 0)
    {
        MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
        exit(1);
    }

    return 0;
}