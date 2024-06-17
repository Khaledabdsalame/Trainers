#include<Windows.h>
#include<TlHelp32.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<tchar.h>
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

int main() {


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

    //GetTheAdress y
    DWORD cordinates = 0x00183828;
    vector<DWORD> offsets = { 0x8,0x2F8,0x98,0x42C };
    DWORD PtrAdress = GetPointerAddress(Ac_Handl, gamebaseadress, cordinates, offsets);
    //Z
    DWORD cordinates2 = 0x00183828;
    vector<DWORD> offsets2 = { 0x8,0x20C,0x30,0x64,0x7E0 };
    DWORD PtrAdressz = GetPointerAddress(Ac_Handl, gamebaseadress, cordinates2, offsets2);

    DWORD cordinates3 = 0x0017E0A8;
    vector<DWORD> offsets3 = { 0x28 };
    DWORD PtrAdressx = GetPointerAddress(Ac_Handl, gamebaseadress, cordinates3, offsets3);


    //Modefication
    while (true)
    {
        float y = 0;
        float z = 0;
        float x = 0;
        while (GetAsyncKeyState(VK_SPACE) & 0x80000000) {
            ReadProcessMemory(phandle, (void*)PtrAdress, &y, 4, 0);
            y += 0.1;
            WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &y, 4, 0);
            Sleep(1);
        }

        while (GetAsyncKeyState(VK_UP) & 0x80000000) {
            ReadProcessMemory(phandle, (void*)PtrAdressz, &z, 4, 0);
            z += 0.1;
            WriteProcessMemory(phandle, (LPVOID*)(PtrAdressz), &z, 4, 0);
            Sleep(1);
        }

        while (GetAsyncKeyState(VK_DOWN) & 0x80000000) {
            ReadProcessMemory(phandle, (void*)PtrAdressz, &z, 4, 0);
            z -= 0.1;
            WriteProcessMemory(phandle, (LPVOID*)(PtrAdressz), &z, 4, 0);
            Sleep(1);
        }

        while (GetAsyncKeyState(VK_LEFT) & 0x80000000) {
            ReadProcessMemory(phandle, (void*)PtrAdressx, &x, 4, 0);
            x += 0.1;
            WriteProcessMemory(phandle, (LPVOID*)(PtrAdressx), &x, 4, 0);
            Sleep(1);
        }

        while (GetAsyncKeyState(VK_RIGHT) & 0x80000000) {
            ReadProcessMemory(phandle, (void*)PtrAdressx, &x, 4, 0);
            x -= 0.1;
            WriteProcessMemory(phandle, (LPVOID*)(PtrAdressx), &x, 4, 0);
            Sleep(1);
        }
        while (GetAsyncKeyState(VK_LCONTROL) & 0x8000)
            {
                ReadProcessMemory(phandle, (void*)PtrAdress, &y, 4, 0);
                y -= 0.1;
                WriteProcessMemory(phandle, (LPVOID*)(PtrAdress), &y, 4, 0);
                Sleep(1);
            }


        

    }
}