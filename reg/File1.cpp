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
 int x;
 DWORD pcbData = 255;
 DWORD regtype = 0;
 char* pvData = new char [pcbData];
 char* text = new char [30];
 cout<<"1 - HKEY_CLASSES_ROOT\n2 - HKEY_CURRENT_USER\n3 - HKEY_LOCAL_MACHINE\n4 - HKEY_USERS\n5 - HKEY_CURRENT_CONFIG "<<endl;
 cout<<"������� ����� ����������� �����: "<<endl;
 cin>>x;
 Key = HUMBER_CLASSES(x);

 cout<<"������� ����"<<endl;
 cin>>text;

 if( RegOpenKeyEx(Key,text, 0, KEY_QUERY_VALUE, &fKey) == ERROR_SUCCESS)//                 //��������� ���� HKEY_CLASSES_ROOT/...
 {
	if ( RegQueryValueEx(fKey, "", NULL, NULL, (LPBYTE)pvData, &pcbData) == ERROR_SUCCESS)                //������ ��� �������� (�� ���������)
	{   cout<<"�������� �� ���������: "<<pvData<<endl;
		RegCloseKey(fKey);																                 //��������� ����
	  if( RegOpenKeyEx(HKEY_CLASSES_ROOT, pvData, 0, KEY_QUERY_VALUE, &fKey) == ERROR_SUCCESS)          //��������� ���� HKEY_CLASSES_ROOT/....
		{
		 RegQueryValueEx (fKey, NULL, NULL, &regtype, NULL, &pcbData);
			if ( ERROR_SUCCESS==RegQueryValueEx (fKey, NULL, NULL, &regtype, (LPBYTE)pvData, &pcbData) )//������ ��� �������� (�� ���������) ...
				cout<<"�������� �� ���������: "<<pvData<<endl;
			else
				cout<<"�� ���� ��������� "<<pvData<<endl;
		}
		else
			cout<<"�� ���� �������"<<pvData<<endl;

	}
	else
		cout<<"�� ���� ��������� "<<text<<endl;
 }
 else
	cout<<"�� ���� ������� "<<text<<endl;

 delete[] pvData;
 system ("pause");
	return 0;
}
/*
		LONG RegOpenKeyEx(
	HKEY hKey,	// ���������� ���������� �����
	LPCTSTR lpSubKey,	// ����� ����� ������������ ��������
	DWORD ulOptions,	// ���������������
	REGSAM samDesired,	// ����� ������� ������������
	PHKEY phkResult 	// ����� ����������� ��������� �����
	);

	LONG RegQueryValueEx(
	HKEY hKey,		// ���������� �����
	LPTSTR lpValueName,	// ����� ����� ��������
	LPDWORD lpReserved,	// ���������������
	LPDWORD lpType,	// ����� ���������� ��� ���� ��������
	LPBYTE lpData,	// ����� ������ ��� ������
	LPDWORD lpcbData 	// ����� ���������� ��� ������ ������ ������
	);
	*/
