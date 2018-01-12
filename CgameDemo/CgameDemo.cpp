// CgameDemo.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "CgameDemo.h"
#include <ddraw.h>
#include <iostream>
#define MAX_LOADSTRING 100


// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������

// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: �ڴ˷��ô��롣
	MSG msg;
	HACCEL hAccelTable;

	// ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_CGAMEDEMO, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CGAMEDEMO));

	// ����Ϣѭ��:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
//  ע��:
//
//    ����ϣ��
//    �˴�������ӵ� Windows 95 �еġ�RegisterClassEx��
//    ����֮ǰ�� Win32 ϵͳ����ʱ������Ҫ�˺��������÷������ô˺���ʮ����Ҫ��
//    ����Ӧ�ó���Ϳ��Ի�ù�����
//    ����ʽ��ȷ�ġ�Сͼ�ꡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;////���ڵķ��
	wcex.lpfnWndProc	= WndProc;////������Ϣ��������ָ��
	wcex.cbClsExtra		= 0;////�����������ṹ֮��Ķ����ֽ���
	wcex.cbWndExtra		= 0;////���������ʵ��֮��Ķ����ֽ���
	wcex.hInstance		= hInstance;////��������Ӧ��Ӧ�ó�����
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CGAMEDEMO));////���ڵ�����
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);////���ڵ����
	wcex.hbrBackground	= CreateSolidBrush(RGB(100,0,0));//(HBRUSH)(COLOR_WINDOW-1);////���ڵı���
	wcex.lpszMenuName	= NULL,//MAKEINTRESOURCE(IDC_CGAMEDEMO);////���ڵĲ˵���Դ����
	wcex.lpszClassName	= szWindowClass;////�����������
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);////ע�ᴰ��
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

   hWnd = CreateWindow(
	   szWindowClass,////�����������õĴ����������
	  NULL,// szTitle, ////���ڱ���
	   WS_POPUP | WS_MAXIMIZE,//WS_OVERLAPPEDWINDOW,////���ڷ�񣬶���Ϊ��ͨ��
      0,////����λ�õ�X����
	  0,////����λ�õ�Y����
	  1000,////���ڵĿ��
	  1000, ////���ڵĸ߶�
	  NULL,////�����ھ��
	  NULL, ////�˵����
	  hInstance,////Ӧ�ó�����
	  NULL);////һ��ΪNULL

   if (!hWnd)
   {
      return FALSE;
   }
   ////����ϵͳ��ʾ����
   ShowWindow(hWnd, nCmdShow);

   ////������ʾ����
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//

int a ,b;

		char ac[25];
		char bc[25];
		char ret[50];
		

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	////�����ַ���
	std::wstring strShow(_T("Test String"));
	RECT rcText;
	rcText.left = 10;
	rcText.right=100;
	rcText.top = 20;
	rcText.bottom=300;

	switch (message)
	{
	
 	case WM_KEYDOWN:
		switch(wParam){
	case VK_SPACE:
		//MessageBox(hWnd,_T("�����˿ո��"),_T("test"),MB_OK);
		////��ʾ�ַ���

		hdc = BeginPaint(hWnd, &ps);

		HBRUSH brush = CreateSolidBrush(RGB(66,66,66));
		FillRect(hdc,&rcText,brush);
		DeleteObject(brush);////�ǵü�ʱ�ͷ��ڴ�

	    DrawText(hdc,strShow.c_str(),(int)strShow.length(),
			&rcText,DT_SINGLELINE|DT_LEFT|DT_END_ELLIPSIS);


		// TODO: �ڴ���������ͼ����...
		EndPaint(hWnd, &ps);

		
		break;
		}
		break;

	////�Ҽ�����
	case WM_RBUTTONDOWN:
		
		a = LOWORD(lParam);
		b = HIWORD(lParam);
		itoa(a,ac,10);
	    itoa(b,bc,10);

		strcat(ret,ac);
		strcat(ret,",");
		strcat(ret,bc);

		MessageBoxA(hWnd,ret,"test",MB_OK);
		strcpy(ret,"");

		break;
	////�������
	case WM_LBUTTONDOWN:

		

		//MessageBoxA(hWnd,"���������","test",MB_YESNO|MB_HELP|MB_ICONERROR);
	//	ShowWindow(hWnd,SW_SHOWMAXIMIZED);
		break;


	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



///////////////////////
// �����ڡ������Ϣ�������
///////////////////////
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
