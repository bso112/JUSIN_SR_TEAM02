#include "stdafx.h"
#include "..\Headers\Scene_Stage3.h"
#include "Management.h"
#include "Camera_Free.h"
#include "KeyMgr.h"
#include "MyButton.h"
#include "GameManager.h"
#include "Cube.h"

CScene_Stage3::CScene_Stage3(PDIRECT3DDEVICE9 pGraphic_Device)
	: CScene(pGraphic_Device)
{

}

HRESULT CScene_Stage3::Ready_Scene()
{
	CManagement*	pManagement = CManagement::Get_Instance();
	if (nullptr == pManagement)
		return E_FAIL;

	CCamera::STATEDESC			StateDesc;
	StateDesc.vEye = _float3(5.f, 5.f, -5.f);
	StateDesc.vAt = _float3(0.f, 0.f, 0.f);
	StateDesc.vAxisY = _float3(0.f, 1.f, 0.f);

	StateDesc.fFovy = D3DXToRadian(90.0f);
	StateDesc.fAspect = _float(g_iWinSizeX) / g_iWinSizeY;
	StateDesc.fNear = 0.2f;
	StateDesc.fFar = 300.f;

	StateDesc.TransformDesc.SpeedPerSec = 5.f;
	StateDesc.TransformDesc.RotatePerSec = D3DXToRadian(90.0f);


	return S_OK;
}

_int CScene_Stage3::Update_Scene(_double TimeDelta)
{
	CKeyMgr::Get_Instance()->Key_Down(VK_LBUTTON, SCENE_STAGE3);
	CKeyMgr::Get_Instance()->Key_Up(VK_LBUTTON, SCENE_STAGE3);

	CKeyMgr::Get_Instance()->Key_Update();

	return _int();
}

HRESULT CScene_Stage3::Render_Scene()
{
	return S_OK;
}

CScene_Stage3 * CScene_Stage3::Create(PDIRECT3DDEVICE9 pGraphic_Device)
{
	CScene_Stage3*	pInstance = new CScene_Stage3(pGraphic_Device);

	if (FAILED(pInstance->Ready_Scene()))
	{
		MSG_BOX("Failed To Create CScene_Stage3");
		Safe_Release(pInstance);
	}
	return pInstance;
}

void CScene_Stage3::Free()
{


	CScene::Free();
}
