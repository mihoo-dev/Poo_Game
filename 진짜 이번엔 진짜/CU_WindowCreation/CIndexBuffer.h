#pragma once
#ifndef CINDEXBUFFER_H_
#define CINDEXBUFFER_H_

#include "stdafx.h"

class CIndexBuffer
{
public:
	CIndexBuffer();
	~CIndexBuffer() { Release(); }
	BOOL CreateBuffer(LPDIRECT3DDEVICE9 pDevice, UINT numIndices, D3DFORMAT format, BOOL dynamic = FALSE);
	void Release();
	BOOL SetData(UINT numIndices, void *pIndices, DWORD flags = D3DLOCK_DISCARD);
	LPDIRECT3DINDEXBUFFER9 GetBuffer() { return m_pIB; }
	UINT GetNumIndices() { return m_numIndices; }

private:
	LPDIRECT3DINDEXBUFFER9  m_pIB;
	UINT                    m_numIndices;
};

#endif // !CINDEXBUFFER_H_