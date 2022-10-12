//
//  Block.cpp
//  Tutorial
//
//  Created by Taj Telesford on 10/4/22.
//

#include "Block.hpp"

Block::Block(int posx, int posy, int val, SDL_Color color)
{
    setX(posx);
    setY(posy);
    setValue(val);
    setColor(color);
    rect.x = posx;
    rect.y = posy;
    this->height = -(val * factorValue);
    rect.w = width;
    rect.h = this->height;
}

void Block::setX(int x)
{
    this->posx = x;
    this->rect.x = this->posx;
}

void Block::setY(int y)
{
    this->posy = y;
}

void Block::setWidth(int x)
{
    
}

void Block::setColor(SDL_Color NewColor)
{
    this->color = NewColor;
    
}

void Block::setValue(int newValue)
{
    this->value = newValue;
}

SDL_Color Block::getColor()
{
    return color;
}

SDL_Rect Block::getRect()
{
    return rect;
}

int Block::getVal()
{
    return value;
}

int Block::getX()
{
    return this->posx;
}

int Block::getY()
{
    return this->posy;
}

int Block::getWidth()
{
    return this->width;
}

int Block::getHeight()
{
    return this->height;
}
