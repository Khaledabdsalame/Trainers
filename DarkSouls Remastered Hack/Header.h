#pragma once
#include<Windows.h>
#include<TlHelp32.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include <WinUser.h>
using namespace std;

LPVOID Win32ReturnModuleBaseAddress(DWORD dwProcessID, const std::wstring& lpszModuleName) {

    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessID);
    LPVOID dwModuleBaseAddress;

    if (hSnapshot != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 ModuleEntry32 = { 0 };
        ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
        if (Module32First(hSnapshot, &ModuleEntry32)) {
            do
            {
                if (!wcscmp(ModuleEntry32.szModule, lpszModuleName.c_str()))
                {
                    dwModuleBaseAddress = ModuleEntry32.modBaseAddr;
                    CloseHandle(hSnapshot);
                    return dwModuleBaseAddress;
                }
            } while (Module32Next(hSnapshot, &ModuleEntry32));
        }
    }

    return 0;

}
bool GetPid(const wchar_t* targetProcess, DWORD* procID)
{
    HANDLE snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snap && snap != INVALID_HANDLE_VALUE)
    {
        PROCESSENTRY32 pe;
        pe.dwSize = sizeof(pe);
        if (Process32First(snap, &pe))
        {
            do
            {
                if (!wcscmp(pe.szExeFile, targetProcess))
                {
                    CloseHandle(snap);
                    *procID = pe.th32ProcessID;
                    return true;
                }
            } while (Process32Next(snap, &pe));
        }
    }
    return false;
}

void injection1() {


    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t healthAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C77E50), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x68;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x280;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x88;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x7B8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x78;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x58;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)healthAdress), &healthAdress, sizeof(LPVOID), NULL);
    healthAdress += 0x3E8;
    UINT32  healthNeeded = 999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)healthAdress), &healthNeeded, sizeof(healthNeeded), NULL);

   
}

void injection2() {
  

    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t staminaAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C77E50), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x68;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x468;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x7B8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x270;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x2F8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x48;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)staminaAdress), &staminaAdress, sizeof(LPVOID), NULL);
    staminaAdress += 0x3F8;
    UINT32 staminaNeeded =999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)staminaAdress), &staminaNeeded, sizeof(staminaNeeded), NULL);


 
}


void injection3() {

    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid,L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t soulsAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C8A530), &soulsAdress, sizeof(LPVOID), NULL);
    UINT32 soulsNeeded = 999999999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)soulsAdress+0xDA4), &soulsNeeded, sizeof(soulsNeeded), NULL);


}

void injection4() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C8A530), &varAdress, sizeof(LPVOID), NULL);
    UINT32 varNeeded = 9999999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress + 0xDA0), &varNeeded, sizeof(varNeeded), NULL);
}
void injection5() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01B690B0), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0xC0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x298;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x7E8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
   varAdress += 0x28;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x40;
    UINT32 varNeeded = 999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);
}

void injection6() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01A31768), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x78;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x7E8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x48;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x578;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x48;
    UINT32 varNeeded = 999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);

}
void injection7() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C77E50), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x68;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x7B8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x78;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x28;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x10;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x578;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x50;
    UINT32 varNeeded = 999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);
}
void injection8() {

    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C77E50), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x40;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x280;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x7D8;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0xB0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x60;
    UINT32 varNeeded = 999;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);

}

void injection10() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C77E50), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x40;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x28;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x250;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x80;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x88;
    UINT32 varNeeded = 99;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);
}
void injection11() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01A31768), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x468;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x578;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x68;
    UINT32 varNeeded = 99;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);

}
void injection12() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C8A530), &varAdress, sizeof(LPVOID), NULL);
    UINT32 varNeeded =99;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress + 0xD80), &varNeeded, sizeof(varNeeded), NULL);

}
void injection13() {
    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01C7C5F0), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x218;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0xFCC;
    UINT32 varNeeded =99;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);

}
void injection14() {

    DWORD pid = NULL;
    GetPid(L"DarkSoulsRemastered.exe", &pid);
    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);
    LPVOID gamebaseadress = Win32ReturnModuleBaseAddress(pid, L"DarkSoulsRemastered.exe");//GetMoudleAdress
    uintptr_t varAdress = 0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)gamebaseadress + (UINT64)0x01A31768), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x0;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x18;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x28;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x250;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x80;
    ReadProcessMemory(phandle, (LPCTSTR)((UINT64)varAdress), &varAdress, sizeof(LPVOID), NULL);
    varAdress += 0x58;
    UINT32 varNeeded = 99;
    WriteProcessMemory(phandle, (LPVOID)((UINT64)varAdress), &varNeeded, sizeof(varNeeded), NULL);
}
