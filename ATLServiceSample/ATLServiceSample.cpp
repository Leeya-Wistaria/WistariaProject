// ATLServiceSample.cpp : WinMain の実装


#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "ATLServiceSample_i.h"

#include <Winbio.h>
#pragma comment(lib, "Winbio.lib")

using namespace ATL;

#include <stdio.h>

class CATLServiceSampleModule : public ATL::CAtlServiceModuleT< CATLServiceSampleModule, IDS_SERVICENAME >
{
public :
	DECLARE_LIBID(LIBID_ATLServiceSampleLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLSERVICESAMPLE, "{27f69add-ec90-438f-8ccd-79518e686c21}")
	HRESULT InitializeSecurity() throw()
	{
		// TODO: CoInitializeSecurity を呼び出し、サービスのための適切なセキュリティ設定を指定します
		// 推奨 - PKT レベルの認証、 
		// RPC_C_IMP_LEVEL_IDENTIFY の偽装レベル
		// および適切な非 NULL セキュリティ記述子。

		return S_OK;
	}

    // 初期化
    HRESULT PreMessageLoop(_In_ int nShowCmd) throw()
    {
        HRESULT hr = __super::PreMessageLoop(nShowCmd);
        if (SUCCEEDED(hr))
        {
            // ToDo: ここに初期化処理を実装する
        }
        return hr;
    }

    // メイン処理
    void RunMessageLoop() throw()
    {
        // ToDo: ここをサービスの内容に応じて変更する
        MSG msg;
        while (GetMessage(&msg, 0, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    // 終了処理
    HRESULT PostMessageLoop() throw()
    {
        // ToDo: ここに終了処理を実装する

        return __super::PostMessageLoop();
    }
};

CATLServiceSampleModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	return _AtlModule.WinMain(nShowCmd);
}

