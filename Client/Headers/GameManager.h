#pragma once
#include "Base.h"
#include "Client_Defines.h"

BEGIN(Client)

class CLevel;
class CCube;
class CGameManager final : public CBase
{
	DECLARE_SINGLETON(CGameManager)
private:
	explicit CGameManager();
	virtual ~CGameManager() = default;

public:
	void	SetGameStart(_bool IsStart) { m_bGameStart = IsStart; }

public:
	_bool	IsGameStart() { return m_bGameStart; }
	

	HRESULT OnGameStart();
	HRESULT OnGameEnd();
private:
	_bool		m_bGameStart = false;
public:
	virtual void Free() override;
};

END