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
#include <Windows.h>

HKEY HUMBER_CLASSES(int number) {
switch (number) {
		case 1: return HKEY_CLASSES_ROOT;
		case 2: return HKEY_CURRENT_USER;
		case 3: return HKEY_LOCAL_MACHINE;
		case 4: return HKEY_USERS;
		case 5: return HKEY_CURRENT_CONFIG;
        }
}


int _tmain(int argc, _TCHAR* argv[])
{
 system("chcp 1251");
 system("cls");
HKEY Key;
HKEY fKey;
unsigned short int x;
DWORD pcbData = 255;
char* pvData = new char [pcbData];
DWORD regtype = 0;
char* text = new char[20];
cout<<"1 - HKEY_CLASSES_ROOT\n2 - HKEY_CURRENT_USER\n3 - HKEY_LOCAL_MACHINE\n4 - HKEY_USERS\n5 - HKEY_CURRENT_CONFIG "<<endl;
cout<<"Введите номер дескриптора ключа: "<<endl;
cin>>x;
Key = HUMBER_CLASSES(x);

cout<<"Введите путь"<<endl;
cin>>text;

 if(RegOpenKeyEx(HKEY_CLASSES_ROOT,text, 0, KEY_QUERY_VALUE, &fKey) == ERROR_SUCCESS)//                 //Открываем ключ HKEY_CLASSES_ROOT/...
 {
	if (RegQueryValueEx(fKey, "", NULL, NULL, (LPBYTE)pvData, &pcbData) == ERROR_SUCCESS)                //Читаем его значение (по умолчанию)
	{   cout<<"значение по умолчанию: "<<pvData<<endl;
		RegCloseKey(fKey);																                 //Закрываем ключ
	  if(RegOpenKeyEx(HKEY_CLASSES_ROOT, pvData, 0, KEY_QUERY_VALUE, &fKey) == ERROR_SUCCESS)          //Открываем ключ HKEY_CLASSES_ROOT/....
		{
		 RegQueryValueEx (fKey, NULL, NULL, &regtype, NULL, &pcbData);
			if (ERROR_SUCCESS==RegQueryValueEx (fKey, NULL, NULL, &regtype, (LPBYTE)pvData, &pcbData) )//Читаем его значение (по умолчанию) ...
				cout<<"значение по умолчанию: "<<pvData<<endl;
			else
				cout<<"Не могу прочитать HKEY_CLASSES_ROOT\\"<<pvData<<endl;
		}
		else
			cout<<"Не могу открыть HKEY_CLASSES_ROOT\\"<<pvData<<endl;

	}
	else
		cout<<"Не могу прочитать HKEY_CLASSES_ROOT\\"<<text<<endl;
 }
 else
	cout<<"Не могу открыть HKEY_CLASSES_ROOT\\"<<text<<endl;
 delete[] pvData;
 system ("pause");
	return 0;
		/*
		LONG RegOpenKeyEx(
	HKEY hKey,	// дескриптор указанного ключа
	LPCTSTR lpSubKey,	// адрес имени открываемого подключа
	DWORD ulOptions,	// зарезервировано
	REGSAM samDesired,	// маска доступа безопасности
	PHKEY phkResult 	// адрес дескриптора открытого ключа
	);

	LONG RegQueryValueEx(
	HKEY hKey,		// дескриптор ключа
	LPTSTR lpValueName,	// адерс имени значения
    LPDWORD lpReserved,	// зарезервировано
	LPDWORD lpType,	// адрес переменной для типа значения
	LPBYTE lpData,	// адрес буфера для данных
	LPDWORD lpcbData 	// адрес переменной для размер буфера данных
	);
	*/

	
}
