﻿#include "GCamera.h"

GCamera::GCamera(int x, int State)
{
	viewport.x = x-15;
	if (State == 2)
		viewport.y = G_ScreenHeight + 416;
	else
	if (State == 3)
		viewport.y = G_ScreenHeight + 1152;
	else
		viewport.y = G_ScreenHeight;
}
void GCamera::SetSizeMap(int _min, int _max)
{
	_maxSize = _max;
	_minSize = _min;
}

D3DXVECTOR2 GCamera::Transform(int x, int y)
{
	D3DXMATRIX matrix;
	D3DXMatrixIdentity(&matrix);
	matrix._22 = -1;
	matrix._41 = -viewport.x;
	matrix._42 = viewport.y;

	D3DXVECTOR3 pos3(x, y, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrix);

	D3DXVECTOR2 result = D3DXVECTOR2(MatrixResult.x, MatrixResult.y);
	return result;
}

D3DXVECTOR3 GCamera::CenterSprite(int x, int y)
{
	D3DXVECTOR3 pCenter = D3DXVECTOR3(x / 2, y / 2, 0);
	return pCenter;
}

void GCamera::UpdateCamerax(int x)
{
	viewport.x = viewport.x + x;
	//Cái này chỉ dùng để test thử khi sang trái phải camera khi nào gắn simon thì bỏ hàm này sử dụng hàm UpdateCamera bên dưới(Tiền update)
	if (viewport.x + G_ScreenWidth > _maxSize)
		viewport.x = _maxSize - G_ScreenWidth;
	if (viewport.x < _minSize) 
		viewport.x = _minSize;
}

void GCamera::UpdateCameray(int x)
{
	viewport.y = viewport.y + x;
}
void GCamera::UpdateCamera(int &w, int &h)
{
	
}

/////////////////////////////////////////////
//Source code bổ sung
void GCamera::SetVCam(float vcamX, float vcamY) {
	_VCameraX = vcamX;
}
void GCamera::UpdateCamera(){
	if ((_FolowPosX >= G_ScreenWidth / 2 + viewport.x && _VCameraX>0) || (_FolowPosX <= viewport.x + G_ScreenWidth / 2 && _VCameraX<0))
	{
		
		viewport.x += _VCameraX;
	}

	if (viewport.x + G_ScreenWidth > _maxSize) 
		viewport.x = _maxSize - G_ScreenWidth;
	if (viewport.x < _minSize) viewport.x = _minSize;
}

void GCamera::SetFolowPos(float x, float y)
{
	_FolowPosX = x;
	_FolowPosY = y;
}