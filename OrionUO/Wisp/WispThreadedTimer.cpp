﻿//----------------------------------------------------------------------------------
#include "stdafx.h"

namespace WISP_THREADED_TIMER
{
//----------------------------------------------------------------------------------
CThreadedTimer::CThreadedTimer(uint id, HWND windowHandle, bool wairForProcessMessage)
: WISP_THREAD::CThread(), m_TimerID(id), m_WindowHandle(windowHandle),
m_WairForProcessMessage(wairForProcessMessage)
{
}
//----------------------------------------------------------------------------------
CThreadedTimer::~CThreadedTimer()
{
}
//----------------------------------------------------------------------------------
void CThreadedTimer::OnExecute(uint nowTime)
{
	WISPFUN_DEBUG("c13_f1");
	if (IsActive())
	{
		if (m_WairForProcessMessage)
			SendMessage(m_WindowHandle, MessageID, nowTime, (LPARAM)this);
		else
			PostMessage(m_WindowHandle, MessageID, nowTime, (LPARAM)this);
	}
}
//----------------------------------------------------------------------------------
void CThreadedTimer::OnDestroy()
{
	WISPFUN_DEBUG("c13_f2");
	if (WISP_WINDOW::g_WispWindow != NULL)
		WISP_WINDOW::g_WispWindow->RemoveThreadedTimer(m_TimerID);
}
//----------------------------------------------------------------------------------
}; //namespace
//----------------------------------------------------------------------------------
