#include <windows.h>
#include <tchar.h>
#include "resource.h"

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

HWND hButton;
int TrueAnswer = 0, MaxAnswer = 8;

TCHAR str[50];
TCHAR percent[] = TEXT("%");

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
	return DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{	
	case WM_INITDIALOG: {
		SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_RADIO13, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_RADIO9, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_RADIO12, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_RADIO17, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);
		SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_UNCHECKED), 0);

		hButton = GetDlgItem(hWnd, IDC_BUTTON1);
	}
	return TRUE;

	case WM_COMMAND: {
		if (LOWORD(wParam) == IDC_RADIO3) {
			SendDlgItemMessage(hWnd, IDC_RADIO3, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_RADIO5) {
			SendDlgItemMessage(hWnd, IDC_RADIO5, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_RADIO9) {
			SendDlgItemMessage(hWnd, IDC_RADIO9, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_RADIO12) {
			SendDlgItemMessage(hWnd, IDC_RADIO12, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_RADIO13) {
			SendDlgItemMessage(hWnd, IDC_RADIO13, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_RADIO17) {
			SendDlgItemMessage(hWnd, IDC_RADIO17, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_CHECK1) {
			SendDlgItemMessage(hWnd, IDC_CHECK1, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_CHECK2) {
			SendDlgItemMessage(hWnd, IDC_CHECK2, BM_SETCHECK, WPARAM(BST_CHECKED), 0);
			TrueAnswer++;
		}
		if (LOWORD(wParam) == IDC_CHECK3 || LOWORD(wParam) ==  IDC_CHECK4) {
			TrueAnswer--;
		}
		

		if (LOWORD(wParam) == IDC_BUTTON1) {
			TrueAnswer = (double(TrueAnswer) / MaxAnswer) * 100;
			wsprintf(str, TEXT("Ваш результат = %d %hs"), TrueAnswer, percent);
			MessageBox(hWnd, str, TEXT("Result"), MB_OK);
			EndDialog(hWnd, 0);
		}
	}
	return TRUE;
					
	case WM_CLOSE:
		EndDialog(hWnd, 0); // закрываем модальный диалог
		return TRUE;
	}
	return FALSE;
}