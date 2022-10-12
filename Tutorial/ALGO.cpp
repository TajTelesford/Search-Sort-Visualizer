//
//  ALGO.cpp
//  Tutorial
//
//  Created by Taj Telesford on 10/4/22.
//

#include "ALGO.hpp"

SDL_Color GREEN = {0, 0, 255, 0};
SDL_Color RED = {255, 0, 0, 0};
SDL_Color AMBER = {255, 191, 200, 0};

void DrawArray(std::vector<Block>& blockArr, SDL_Renderer* ren, SDL_Window* window, int size)
{
    
    for(auto block : blockArr)
    {
        
        //The block in a iteration gives the color of itself
        SDL_Color color = block.getColor();
        //Then renders the color
        SDL_SetRenderDrawColor(ren, color.r, color.b, color.g, color.a);
        //Need to create a temp rect
        SDL_Rect temp = block.getRect();
        //Then gets drawn to the screen with the color above gotten from itself
        SDL_RenderFillRect(ren, &temp);
    }
}

void BinarySearch(std::vector<Block>& blockArr, int size, int targetNum, SDL_Renderer* ren, SDL_Window* window)
{
    int start = 0, end = size, mid;
    while(start <= end)
    {
        mid = (end+start)/2;
        if(blockArr[mid].getVal() == targetNum)
        {
            //Changes the of the block to green the renders out a update Block Array
            blockArr[mid].setColor(GREEN);
            return;
        }
        else if(blockArr[mid].getVal() < targetNum)
        {
            //Changes the of the block to red the renders out a update Block Array
            blockArr[mid].setColor(RED);
            start = mid + 1;
        }
        else if(blockArr[mid].getVal() > targetNum)
        {
            //Changes the of the block to red the renders out a update Block Array
            blockArr[mid].setColor(RED);
            //DrawArray(blockArr, ren, window, size);
            end = mid;
        }
        else{
            //Changes the of the block to Amber the renders out a update Block Array
            blockArr[mid].setColor(AMBER);
            return;
        }
    }
}

void LinearSearch(std::vector<Block>& block, int size, int val)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << block[i].getVal() <<std::endl;
        if (block[i].getVal() == val)
            block[i].setColor(GREEN);
        else
            block[i].setColor(RED);
    }
}

void SWAP(Block& a, Block& b, SDL_Window* w, SDL_Renderer* ren)
{
    int changeA = a.getX();
    int changeB = b.getX();
    
    while(a.getX() != changeB || b.getX() != changeA)
    {
        if(changeA < changeB)
        {
            int prex = a.getX();
            int prevb = b.getX();
           
            while(prex < changeB)
            {
                prex+= 25;
                a.setX(prex);
            }
            while(prevb > changeA)
            {
                prevb-= 25;
                b.setX(prevb);
            }
        }
        else{
            int prex = a.getX();
            int prevb = b.getX();
            while(prex > changeB)
            {
                prex-= 25;
                a.setX(prex);
                std::cout << a.getX() << std::endl;
            }
            while(prevb < changeA)
            {
                prevb+= 25;
                b.setX(prevb);
                std::cout << a.getX() << std::endl;
            }
        }
    }
    Block temp = a;
    a = b;
    b = temp;
}

void SelectionSort(std::vector<Block>& blockArr, int size, SDL_Window* w, SDL_Renderer* ren)
{
    for(int i = 0; i < blockArr.size() - 1; i++)
    {
        int imin = i;
        std::cout << i << std::endl;
        for(int j = i+1; j < blockArr.size(); j++)
        {
            if(blockArr[imin].getVal() > blockArr[j].getVal())
            {
                imin = j;
            }
        }
        SWAP(blockArr[imin], blockArr[i], w, ren);
        
    }
    DrawArray(blockArr, ren, w, size);
}
void BubbleSort(std::vector<Block>& block, int size, SDL_Window* w, SDL_Renderer *ren)
{
    bool swap;
    do{
        swap = false;
        for(int i = 0; i < size-1; i++)
        {
            if(block[i].getVal() > block[i+1].getVal())
            {
                SWAP(block[i], block[i+1], w, ren);
                swap = true;
            }
        }
    }while(swap);
}
