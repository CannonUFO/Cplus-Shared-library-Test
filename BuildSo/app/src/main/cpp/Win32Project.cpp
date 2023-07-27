// Win32Project.cpp : Defines the exported functions for the DLL application.
//#include "stdafx.h" // use pch.h in Visual Studio 2019 and later
#include <utility>
#include <iostream>
// Test HelloWorld
std::string helloWorldFun()
{
	return "helloWorldFun";
}


unsigned char *m_textureData;
int m_width;
int m_height;



unsigned char* Init(int width, int height)
{
	srand(time(NULL));

	m_width = width;
	m_height = height;

	auto dataLen = m_width * m_height * 4;
	m_textureData = new unsigned char[dataLen];

	int w = 4 * m_width;
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++)
		{
			m_textureData[i * w + j * 4 + 0] = 255;
			m_textureData[i * w + j * 4 + 1] = 255;
			m_textureData[i * w + j * 4 + 2] = 255;
			m_textureData[i * w + j * 4 + 3] = 255;
		}
	}

	return m_textureData;
}

void InputXY(int x, int y)
{
	if (x < 0 || x > m_width || y < 0 || y > m_height)
	{
		return;
	}

	int w = 4 * m_width;
	y = m_height - y;
	int thickness = 10;

	int min = 0;
	int max = 255;
	int color_r = rand() % (max - min + 1) + min;
	int color_g = rand() % (max - min + 1) + min;
	int color_b = rand() % (max - min + 1) + min;

	for (int i = x - thickness; i < x + thickness; i++)
	{
		for (int j = y - thickness; j < y + thickness; j++)
		{
			if (i < 0 || i > m_width || j < 0 || j > m_height)
			{
				continue;
			}
			m_textureData[j * w + i * 4 + 0] = color_r;
			m_textureData[j * w + i * 4 + 1] = color_g;
			m_textureData[j * w + i * 4 + 2] = color_b;
			m_textureData[j * w + i * 4 + 3] = 255;
		}
	}
}