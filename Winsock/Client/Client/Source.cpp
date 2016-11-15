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

    SOCKADDR_IN sockIn; //Has a Port, Address, and character zero signature. (buffer?)
                        //              VV ugly way of doing unions. Ends up being a long, looks like.
    sockIn.sin_addr.s_addr = inet_addr("127.0.0.1"); //Broadcast locally
    sockIn.sin_port = htons(1111);                   //port
    sockIn.sin_family = AF_INET;                     //IPv4 socket
    int         sockInLen = sizeof(sockIn);                  //not size_t? dear God microsoft. What were the 80s like?

    return 0;
}