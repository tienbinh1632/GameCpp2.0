#ifndef BASE_OBJECT_H
#define BASE_OBJECT_H

#include "CommonFuncion.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();
	
	void setRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; }
	SDL_Rect getRect() const { return rect_; }
	SDL_Texture* getObject() const { return p_object_; }
	
	void Free();
	bool LoadImg(std::string path, SDL_Renderer* screen); //upload image "path" to screen;
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;
};







#endif // !BASE_OBJECT_H


#pragma once
