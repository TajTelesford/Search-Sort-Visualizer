//
//  Block.hpp
//  Tutorial
//
//  Created by Taj Telesford on 10/4/22.
//

#ifndef Block_hpp
#define Block_hpp

#include "GLOBALS.hpp"
#include <tuple>

class Block{
  
public:
    //Initalizes a block object with postion x and y, also height and width, as well as gives it color
    Block(int posx, int posy, int val, SDL_Color color);
    
    //sets x position
    void setX(int x);
    
    //sets y position
    void setY(int y);
    
    //sets width of Block
    void setWidth(int x);
    
    //sets height of Block
    void setHeight(int x);
    
    //sets color of the block if conditions are met
    void setColor(SDL_Color color);
    
    //updates the color of the block if condtions are met
    //void changeColor(Uint8& r, Uint8& g, Uint8& b, SDL_Rect& rec, SDL_Renderer* ren);
    
    void setValue(int x);
    
    //returns the color of a block instance
    SDL_Color getColor();
    
    //returns the rect of a block instance
    SDL_Rect getRect();
    
    //returns the x postion of a block instance
    int getX();
    
    //returns the y position of a block instance
    int getY();
    
    int getWidth();
    int getHeight();
    
    int getVal();
    
private:
    int posx;
    int posy;
    int width = 25;
    SDL_Rect rect;
    int value;
    int height;
    SDL_Color color;
    int factorValue = 25;
    
    
};


#endif /* Block_hpp */
