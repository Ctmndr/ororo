#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream.h>
#include <Registry.hpp>
#include <Windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	try {
	char text[20] = " ";
	//HKEY hKey;

	// TRegistry *reg = new TRegistry();
	  //	reg->RootKey = HKEY_LOCAL_MACHINE;
      HKEY Key;
	char buf[256];
	DWORD dws = 0x100;
	DWORD dwt = 0;
	LONG result = 0;

	result = RegOpenKeyEx(HKEY_CLASSES_ROOT, "Applications\\MyProg.exe\\command", 0, KEY_ALL_ACCESS, &Key);

	RegQueryValueEx(Key, "param2",0, 0, (LPBYTE)buf, &dws); //читается, все хорошо, а как считать (default) ?

	RegCloseKey(Key);
    RegQueryValueEx(Key, NULL,0, 0, (LPBYTE)buf, &dws);
	} catch (...) { cout<<"Ошибка"<<endl;
	}
	system ("pause");
	return 0;
}
