#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	
	// �T���v���R�[�h
	//TCHAR chStr[128];
	// TEXT()�Ń��C�h������ɑΉ�
	//wsprintf(chStr, TEXT("hInstance : %d"), hInstance);
	//MessageBox(NULL, chStr, TEXT("�J��߂�"), MB_OK | MB_ICONINFORMATION);
	
	// �E�B���h�E�^�C�g���擾
	//GetWindowTextA();

	// �O�i�E�B���h�Ehandle�擾
	// GetForegroundWindow();

	// �t�H�[�J�X���������E�B���h�Ehandle�擾 
	// GetActiveWindow();
	


	HWND hwnd = NULL;
	CHAR lpstr[128];
	// �e�X�g�pSleep() : ForegroundWindow��ύX���邽�߂̎��� 
	Sleep(3000);
	hwnd = GetForegroundWindow();
	TCHAR chStr[128];
	// TEXT()�Ń��C�h������ɑΉ�
	wsprintf(chStr, TEXT("hInstance : %d"), hInstance);

	if (hwnd != NULL) {
		if (GetWindowTextA(hwnd, lpstr, sizeof(lpstr)) != 0) {
			MessageBoxA(NULL, lpstr, "�A�N�e�B�u�E�B���h�E", MB_OK);
		}
	}
	else {
		MessageBox(NULL, chStr, TEXT("�J��߂�"), MB_OK | MB_ICONINFORMATION);
	}
	

	return 0;
}








/*
�N��/��~/�m�F
	�J�n: �A�v���N���ŃX�^�[�g
	��~: �A�v���I��/�V���b�g�_�E�����ɎZ�o�������L�^���I��
		  �d���؂�ɂ���~�͍ċN�����Ƀ��O����Z�o�������s���Ă���J�n

���z
	�A�v���N�������~�܂ł̃E�B���h�E��Ԃ��L�^
	�L�^���e���犈�����e�������I�ɔ��肵�Ċ������e���Ƃ̊������Ԃ��Z�o
	���Ȃ��ƕK�v�Ȋ�����ʒm

	�A�h�I��:�Z�o���e����ɓ��v�����Z�o

�ۑ�
	�E�B���h�E�ƃ^�X�N�̕R�Â�
		��
			�蓮
				��Έ�, ��Α�(�I��)
			����
				muri
		���蓮. �ǂ��ݒ肷�邩.
			��
				�A�v����~���Ɏ蓮�őI��/����




		����A�v���ňقȂ��Ƃ��s�����Ƃ�����ꍇ
			��
				(?)�f�t�H���g�͌����ɂ��ĈႤ�ꍇ�̂ݎ蓮�ŋL�^����


		��ʂ������܂܋x�e�Ȃǂ�ʂ̍s�������Ă���ꍇ
			��

�@�\
	�A�N�e�B�u�E�B���h�E�̏�Ԃ����O�ɋL�^���A�������e���Ƃ̊������Ԃ��Z�o����

��
	Discord��VisualStudio��Chrome��VisualStudio��Mattermost��WSL��Chrome��WSL��
	
	�悭�g���A�v��
		�J�e�S���@ : ����
		�J�e�S���A : �l�J��(�),�T�u�v���W�F�N�g
		�J�e�S���B : �G��
		�J�e�S���C : �V��

		RocketChat : �B > �@
		Discord    : �C >> �A
		Mattermost : �B
		(Outlook   : )
		(Teams     : )
		VSC        : �@ - �A
		WSL        : �@ - �A
		Chrome     : �@ - �A - �B - �C
		������     : �B
		VM         : �A > �@

		���P�`����MM, WSL��Chrome�Ȃǂ̎g�p���Ԃ̕��ޕ��@
			��
				����؂�
				���z
				���̑��ɕ���
				���Ƃ���L�^

�����@
	�J�e�S�����蓮�Œǉ����Ă����āA�A�v����~���Ƀy�^�y�^
		�߂�ǂ�������
		�A�v���̈Ӗ��������


�����A
	

*/
