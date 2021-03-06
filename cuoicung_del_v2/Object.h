﻿#include "GCamera.h"
#include"GSprite.h"
#include "Sweet_AABB.h"
#include "Weapon.h"
#pragma once
class CObject
{
protected:

	float x;			 //Vị trí obj
	float y;
	int w;
	int h;
	int IsGoing;		// Đang di chuyển = 1; Đứng yên = 0;
	int IsAttacking;
	int IsStopping;
	int IsJumping;
	int IsSitting;
	int IsFalling;
	int DefaultTrend;
	int Trend;		// Phương hướng, trái = -1, phải = 1;
	int PreAtk;
	int IsHurting;
	int EndHurt;
	bool IsDie = 0;
public:
	GTexture *GTObject;
	GSprite *GSObject;
	float Vx;	// Vận tốc theo trục X
	float Vy;	// Vận tốc theo trục Y

	float GetVx();
	float GetVy();

	float		getx() { return this->x; }
	void		setx(float x1) { x = x1;}

	float		gety() { return this->y; }
	void		sety(float x1) { y = x1; }

	int			getw() { return this->w; }
	void		setw(int x1) { w = x1; }

	int			geth() { return this->h; }
	void		seth(int x1) { h = x1; }
	
	float		getVx() { return this->Vx; }
	void		setVX(int x1) { this->Vx = x1; }

	int			getIsHurrting() { return this->IsHurting; }

	//danh cho 
	int getHeight() { return GTObject->FrameHeight; }
	int getWidth() { return GTObject->FrameWidth; }
	int getTrend(){ return Trend; }
	void setTrend(int trend) { Trend = trend; }
	//Thiên thêm hàm này
	int			getIsDie() { return this->IsDie; }
	void		setIsDie(bool a) { IsDie = a; }
	int			getAttacking() { return this->IsAttacking; }
	int getIsJumping(){ return IsJumping; };
	int getIsFalling(){ return IsFalling; };
	//Tiền updated
	//int GetAttacking() {return IsAttacking;}
	//Tiền updated
	int getIsGoing(){ return IsGoing; };
	//end
	virtual void Update(int t);
	virtual void Draw(GCamera * cam);

	CObject();
	CObject(float x, float y, int w, int h);
	~CObject();
	virtual Box GetBox(GCamera *camera);

	virtual void StopFall(float y);
	virtual void Stop();
	virtual void Sit();
	virtual void StandUp();
	virtual void Fall();
	virtual void Jump();
	virtual void Go();
	virtual void MoveLeft();
	virtual void MoveRigh();
	///////////////////
	virtual void Attack(Weapon * weapon);
	virtual int CreateWeapon();
	int GetHurt();
	void SetHurt(int i = 30);
	void CObject::SetAnimation(float Vx, float Vy, int Frame);
	virtual void GetSMPositionForBoss(float x, float y, int Trend);
};
