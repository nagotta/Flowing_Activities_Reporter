#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
	HWND hwnd = NULL;
	TCHAR lpstr[128]; // TCHAR 型に変更
	Sleep(3000);
	hwnd = GetForegroundWindow();
	TCHAR chStr[128]; // TCHAR 型に変更
	SYSTEMTIME lt; // ローカルの日付と時刻取得用変数
	GetLocalTime(&lt); // 直接 SYSTEMTIME 型を代入
	LPSYSTEMTIME lpSystemTime = &lt;

	// TEXT()でワイド文字列に対応
	wsprintf(chStr, TEXT("hInstance : %d"), hInstance);

	if (hwnd != NULL) {
		if (GetWindowText(hwnd, lpstr, sizeof(lpstr) / sizeof(TCHAR)) != 0) { // TCHAR 型を扱うよう修正
			wsprintf(chStr, TEXT("%s %02d:%02d:%02d"), lpstr, lt.wHour, lt.wMinute, lt.wSecond); // TCHAR 型を扱うよう修正
			MessageBox(NULL, chStr, TEXT("アクティブウィンドウ"), MB_OK); // TCHAR 型を扱うよう修正
		}
	}
	else {
		MessageBox(NULL, chStr, TEXT("雨やめて"), MB_OK | MB_ICONINFORMATION); // TCHAR 型を扱うよう修正
	}
	return 0;
}





// サンプルコード
//TCHAR chStr[128];
// TEXT()でワイド文字列に対応
//wsprintf(chStr, TEXT("hInstance : %d"), hInstance);
//MessageBox(NULL, chStr, TEXT("雨やめて"), MB_OK | MB_ICONINFORMATION);

// ウィンドウタイトル取得
//GetWindowTextA();

// 前景ウィンドウhandle取得
// GetForegroundWindow();

// フォーカスを持ったウィンドウhandle取得 
// GetActiveWindow();




/*
起動/停止/確認
	開始: アプリ起動でスタート
	停止: アプリ終了/シャットダウン時に算出処理→記録→終了
		  電源切れによる停止は再起動時にログから算出処理を行ってから開始

理想
	アプリ起動から停止までのウィンドウ状態を記録
	記録内容から活動内容を自動的に判定して活動内容ごとの活動時間を算出
	少ないと必要な活動を通知

	アドオン:算出内容を基に統計情報を算出

課題
	ウィンドウとタスクの紐づけ
		解
			手動
				一対一, 一対多(選択)
			自動
				muri
		→手動. どう設定するか.
			解
				アプリ停止時に手動で選択/入力




		同一アプリで異なる作業を行うことがある場合
			解
				(?)デフォルトは研究にして違う場合のみ手動で記録する


		画面をつけたまま休憩などを別の行動をしている場合
			解

機能
	アクティブウィンドウの状態をログに記録し、活動内容ごとの活動時間を算出する

例
	Discord→VisualStudio→Chrome→VisualStudio→Mattermost→WSL→Chrome→WSL→
	
	よく使うアプリ
		カテゴリ�@ : 研究
		カテゴリ�A : 個人開発(趣味),サブプロジェクト
		カテゴリ�B : 雑事
		カテゴリ�C : 遊び

		RocketChat : �B > �@
		Discord    : �C >> �A
		Mattermost : �B
		(Outlook   : )
		(Teams     : )
		VSC        : �@ - �A
		WSL        : �@ - �A
		Chrome     : �@ - �A - �B - �C
		メモ帳     : �B
		VM         : �A > �@

		ロケチャやMM, WSLとChromeなどの使用時間の分類方法
			解
				割り切り
				分配
				その他に分類
				あとから記録

実装�@
	カテゴリを手動で追加しておいて、アプリ停止時にペタペタ
		めんどうくさい
		アプリの意味が薄れる


実装�A
	

*/
