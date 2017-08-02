﻿/***********************************************************************************
**
** ConnectionScreen.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef CONNECTIONSCREEN_H
#define CONNECTIONSCREEN_H
//----------------------------------------------------------------------------------
class CConnectionScreen : public CBaseScreen
{
	SETGETE(bool, ConnectionFailed, false, OnChangeConnectionFailed);
	SETGETE(bool, Connected, false, OnChangeConnected);
	SETGETE(bool, Completed, false, OnChangeCompleted);
	SETGETE(int, ErrorCode, 0, OnChangeErrorCode);
	SETGETE(CONNECTION_SCREEN_TYPE, Type, CST_LOGIN, OnChangeType);
	SETGETE(string, Message, "", OnChangeMessage);

private:
	CGumpScreenConnection m_ConnectionGump;

public:
	CConnectionScreen();
	~CConnectionScreen();

	//!Идентификаторы событий для плавного перехода
	static const uchar ID_SMOOTH_CS_GO_SCREEN_MAIN = 1;
	static const uchar ID_SMOOTH_CS_GO_SCREEN_CHARACTER = 2;
	static const uchar ID_SMOOTH_CS_GO_SCREEN_PROFESSION = 3;
	static const uchar ID_SMOOTH_CS_SEND_DELETE = 4;

	/*!
	Инициализация
	@return 
	*/
	void Init();

	/*!
	Обработка события после плавного затемнения экрана
	@param [__in_opt] action Идентификатор действия
	@return 
	*/
	void ProcessSmoothAction(uchar action = 0xFF);



	virtual void OnKeyDown(const WPARAM &wParam, const LPARAM &lParam);
};
//----------------------------------------------------------------------------------
extern CConnectionScreen g_ConnectionScreen;
//----------------------------------------------------------------------------------
#endif
//----------------------------------------------------------------------------------
