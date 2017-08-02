﻿/***********************************************************************************
**
** ObjectOnCursor.h
**
** Copyright (C) August 2016 Hotride
**
************************************************************************************
*/
//----------------------------------------------------------------------------------
#ifndef OBJECTONCURSOR_H
#define OBJECTONCURSOR_H
//----------------------------------------------------------------------------------
//!Класс объекта на курсоре
class CObjectOnCursor
{
	//!Активен
	SETGET(bool, Enabled, false);
	//!Серийник объекта
	SETGET(uint, Serial, 0);
	//!Индекс картинки
	SETGET(ushort, Graphic, 0);
	//!Цвет
	SETGET(ushort, Color, 0);
	//!Количество для перемещения
	SETGET(ushort, Count, 0);
	//!Слой
	SETGET(uchar, Layer, 0);
	//!Флаги
	SETGET(uchar, Flags, 0);
	//!Контейнер
	SETGET(uint, Container, 0);
	//!Координата X
	SETGET(ushort, X, 0);
	//!Координата Y
	SETGET(ushort, Y, 0);
	//!Координата Z
	SETGET(char, Z, 0);
	//!Это игровая фигура
	SETGET(bool, IsGameFigure, false);
	//!Указатель на тайлдату для объекта
	SETGET(STATIC_TILES*, TiledataPtr, NULL);

public:
	CObjectOnCursor() {}
	virtual ~CObjectOnCursor() {}

	void Clear();

	ushort GetDrawGraphic(bool &doubleDraw);
};
//----------------------------------------------------------------------------------
//!Указатель на объект в руке (на курсоре)
extern CObjectOnCursor g_ObjectInHand;
//----------------------------------------------------------------------------------
#endif
