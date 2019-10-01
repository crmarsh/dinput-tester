#include <iostream>

#define WIN32_LEAN_AND_MEAN
#define VC_EXTRALEAN
#include <windows.h>

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#pragma comment(lib, "dinput8")
#pragma comment(lib, "dxguid")

BOOL CALLBACK EnumDevicesCb(LPCDIDEVICEINSTANCE diDevice, LPVOID)
{
    wchar_t guid[40];
    if (StringFromGUID2(diDevice->guidProduct, guid, ARRAYSIZE(guid)))
    {
        std::wcout
            << L"Name: " << diDevice->tszProductName << L"\n"
            << L"GUID: " << guid << L"\n";
    }
    else {
        std::wcerr << L"Could not extract GUID for " << diDevice->tszProductName << L"\n";
    }
    return DIENUM_CONTINUE;
}

int main()
{
    IDirectInput8* di8;
    HRESULT hr = DirectInput8Create(GetModuleHandleW(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&di8, nullptr);
    if (FAILED(hr))
    {
        std::cerr << "Could not create DirectInput 8 handle\n";
        return 1;
    }

    if (di8->EnumDevices(DI8DEVCLASS_ALL, EnumDevicesCb, nullptr, DIEDFL_ATTACHEDONLY) != DI_OK)
    {
        std::cerr << "Could not enumerate devices.\n";
        return 2;
    }

    return 0;
}
