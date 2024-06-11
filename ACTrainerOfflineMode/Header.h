#pragma once

#include<Windows.h>
#include<TlHelp32.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<tchar.h>
#include <limits>
using namespace std;
DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID) {
    DWORD dwModuleBaseAddress = 0;
    HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pID); // make snapshot of all modules within process
    MODULEENTRY32 ModuleEntry32 = { 0 };
    ModuleEntry32.dwSize = sizeof(MODULEENTRY32);

    if (Module32First(hSnapshot, &ModuleEntry32)) //store first Module in ModuleEntry32
    {
        do {
            if (_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0) // if Found Module matches Module we look for -> done!
            {
                dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
                break;
            }
        } while (Module32Next(hSnapshot, &ModuleEntry32)); // go through Module entries in Snapshot and store in ModuleEntry32


    }
    CloseHandle(hSnapshot);
    return dwModuleBaseAddress;
}

DWORD GetPointerAddress(HWND hwnd, DWORD gameBaseAddr, DWORD address, vector<DWORD> offsets)
{
    DWORD pID = NULL; // Game process ID
    GetWindowThreadProcessId(hwnd, &pID);
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pID);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    DWORD offset_null = NULL;
    ReadProcessMemory(phandle, (LPVOID*)(gameBaseAddr + address), &offset_null, sizeof(offset_null), 0);
    DWORD pointeraddress = offset_null; // the address we need
    for (int i = 0; i < offsets.size() - 1; i++) // we dont want to change the last offset value so we do -1
    {
        ReadProcessMemory(phandle, (LPVOID*)(pointeraddress + offsets.at(i)), &pointeraddress, sizeof(pointeraddress), 0);
    }
    return pointeraddress += offsets.at(offsets.size() - 1); // adding the last offset
}

void injection1() {
    HWND Ac_Handl = FindWindowA(NULL, "AssaultCube"); //Getting the handle of process
    if (Ac_Handl != FALSE);
    // getting process id
    DWORD pid = NULL;
    GetWindowThreadProcessId(Ac_Handl, &pid);

    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    char BaseAdressMoudle[] = "ac_client.exe";
    DWORD gamebaseadress = GetModuleBaseAddress(_T(BaseAdressMoudle), pid);//GetMoudleAdress

    //GetTheAdress
    DWORD AmmoAdress = 0x00183828;
    vector<DWORD> offsets = { 0x8,0x58,0x34,0x64,0x1B8 };
    DWORD PtrAdress = GetPointerAddress(Ac_Handl, gamebaseadress, AmmoAdress, offsets);
       int ammo = 99999999999;
       WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &ammo, 4, 0);
   
}

void injection2() {
    HWND Ac_Handl = FindWindowA(NULL, "AssaultCube"); //Getting the handle of process
    if (Ac_Handl != FALSE);
    // getting process id
    DWORD pid = NULL;
    GetWindowThreadProcessId(Ac_Handl, &pid);

    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    char BaseAdressMoudle[] = "ac_client.exe";
    DWORD gamebaseadress = GetModuleBaseAddress(_T(BaseAdressMoudle), pid);//GetMoudleAdress

    //GetTheAdress
    DWORD Health_Adress = 0x00195404;
    vector<DWORD> offsets = { 0xEC };
    DWORD PtrAdress = GetPointerAddress(Ac_Handl, gamebaseadress, Health_Adress, offsets);
    int Health = 99999999999;
    WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &Health, 4, 0);

}
   
void injection3() {


    HWND Ac_Handl = FindWindowA(NULL, "AssaultCube"); //Getting the handle of process
    if (Ac_Handl != FALSE);
    // getting process id
    DWORD pid = NULL;
    GetWindowThreadProcessId(Ac_Handl, &pid);

    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    char BaseAdressMoudle[] = "ac_client.exe";
    DWORD gamebaseadress = GetModuleBaseAddress(_T(BaseAdressMoudle), pid);//GetMoudleAdress

    //GetTheAdress
    DWORD Pistol_Adress = 0x00183828;
    vector<DWORD> offsets = { 0x8,0xFC4,0x98,0x98,0x30,0x30,0x694};
    DWORD PtrAdress = GetPointerAddress(Ac_Handl, gamebaseadress, Pistol_Adress, offsets);
    int Ammo = 99999999999;
    WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &Ammo, 4, 0);


}

void injection4() {
    HWND Ac_Handl = FindWindowA(NULL, "AssaultCube"); //Getting the handle of process
    if (Ac_Handl != FALSE);
    // getting process id
    DWORD pid = NULL;
    GetWindowThreadProcessId(Ac_Handl, &pid);

    //getting handle
    HANDLE phandle = NULL;
    phandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (phandle == INVALID_HANDLE_VALUE || phandle == NULL);

    char BaseAdressMoudle[] = "ac_client.exe";
    DWORD gamebaseadress = GetModuleBaseAddress(_T(BaseAdressMoudle), pid);//GetMoudleAdress

    //GetTheAdress
    DWORD Bomb_Adress = 0x00183828;
    vector<DWORD> offsets = { 0x8,0x98,0x30,0x2F4 };
    DWORD PtrAdress = GetPointerAddress(Ac_Handl, gamebaseadress, Bomb_Adress, offsets);
    int bomb = 99999999999;
    WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &bomb, 4, 0);

}