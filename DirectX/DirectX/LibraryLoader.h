// Copyright (c) Microsoft Corporation.  All rights reserved.

#pragma once
#include <map>
#include <string>

// using namespace std;

namespace Microsoft { namespace WindowsAPICodePack { namespace DirectX {

enum DirectXLibrary
{
    D2DLibrary,
    D3D11Library,
    D3D10Library,
    D3D10_1Library,
    DXGILibrary,
    DWriteLibrary,
};

/// <summary>
/// A private class supporting dll and functions loading.
/// Loaded dlls and functions are cached in a hash table.
/// </summary>
private class LibraryLoader
{

public:
    static LibraryLoader* Instance();
    HINSTANCE LoadDll(DirectXLibrary library);
    FARPROC GetFunctionFromDll(DirectXLibrary library, LPCSTR functionName);

private:

    // Make it private to prevent construction
   _STD map<DirectXLibrary, HINSTANCE> m_libraries;
   _STD map<DirectXLibrary, _STD wstring> m_libraryNames;

   _STD map<_STD string, FARPROC> m_loadedMethods;
    LibraryLoader();

};
} } }
