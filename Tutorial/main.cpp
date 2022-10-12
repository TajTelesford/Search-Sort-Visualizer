//
//  main.cpp
//  Tutorial
//
//  Created by Taj Telesford on 10/2/22.
//

#define WIDTH 625
#define HEIGHT 625
#define TITLE "SEARCH AND SORTING VISUALIZER"

//#include <iostream>
#include <random>
#include "GLOBALS.hpp"
#include "ALGO.hpp"
#include <vector>

using namespace std;

int cell_size = 25, grid_width = 25, grid_height = 25;
int yOfOriginOfBlocks = 550;
SDL_Color WHITE = {255, 255, 255, 0};
SDL_Color BLACK = {0,0,0,0};
int numOfBlocks = 19;

void makeGrid(SDL_Renderer* ren)
{
    for(int x = 0; x < grid_width * cell_size + 1; x+=cell_size)
    {
        for(int y = 0; y < grid_height * cell_size + 1; y+=cell_size)
        {
            //cout << x << " : " << y << endl;
            if(y == yOfOriginOfBlocks)
            {
                SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
                SDL_RenderDrawLine(ren, x, 0, x, HEIGHT);
                SDL_RenderDrawLine(ren, 0, y, WIDTH, y);
            }
            else{
                SDL_SetRenderDrawColor(ren, 255, 255, 255, 0);
                SDL_RenderDrawLine(ren, x, 0, x, HEIGHT);
                SDL_RenderDrawLine(ren, 0, y, WIDTH, y);
            }
            
        }
    }
}

void initializeBlockArr(vector<Block>& BLOCKARR)
{
    //Pushes the x values in steps of 30 to fit the grid
    for(int x = 75; x < (grid_width * cell_size) - 75; x+=25)
    {
        int newRandomNum = rand() % 20 + 1;
        Block newBlock(x, yOfOriginOfBlocks, newRandomNum, WHITE);
        BLOCKARR.push_back(newBlock);
    }
}

void displaySortedNum(vector<Block>& b)
{
    for(Block block : b)
    {
        cout << block.getVal() << endl;
    }
    cout << "{END}" << endl;
}

void display(SDL_Window* w, std::vector<Block> &block, SDL_Renderer *ren, int size)
{
    DrawArray(block, ren,  w, size);
    makeGrid(ren);
    SDL_RenderPresent(ren);
}

void update(SDL_Window* w, std::vector<Block> &block, SDL_Renderer *ren, int size)
{
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    SDL_RenderClear(ren);
    display(w, block, ren, size);
    
}

int main(int argc, const char * argv[]) {
    
   
    
    SDL_Init(SDL_INIT_VIDEO);
    if( SDL_Init( SDL_INIT_EVERYTHING ) == 0 ){
        std::cout<< "SDL has been initializaed..." << std::endl;
    }
    else{
        std::cout << "SDL has failed.. Errors: " << SDL_GetError() << std::endl;
    }
    
    //Creating Window
   SDL_Window *window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    
    bool running = true;
    SDL_Event e;
    
    vector<Block> STACKOFBLOCKS;
    initializeBlockArr(STACKOFBLOCKS);
    
        while(running)
    {
        while(SDL_PollEvent(&e))
        {
            if( e.type == SDL_QUIT ) { running = false; }
            switch (e.type) {
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_SPACE)
                    {
                        //SelectionSort(STACKOFBLOCKS, numOfBlocks, window, renderer);
                        //BinarySearch(STACKOFBLOCKS, numOfBlocks, 5,renderer, window);
                        //LinearSearch(STACKOFBLOCKS, numOfBlocks, 5);
                        BubbleSort(STACKOFBLOCKS, numOfBlocks, window, renderer);
                    }
                    break;
                default:
                    break;
            }
        }

        display(window, STACKOFBLOCKS, renderer, numOfBlocks);
        update(window, STACKOFBLOCKS, renderer, numOfBlocks);
        SDL_Delay(10);
    }
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
