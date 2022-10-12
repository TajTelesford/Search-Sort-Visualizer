//
//  ALGO.hpp
//  Tutorial
//
//  Created by Taj Telesford on 10/4/22.
//

#ifndef ALGO_hpp
#define ALGO_hpp

#include "GLOBALS.hpp"
#include <vector>
#include <tuple>
#include "Block.hpp"

void DrawArray(std::vector<Block>& block, SDL_Renderer* ren, SDL_Window* surface, int size);
void BinarySearch(std::vector<Block>& block, int size, int target,SDL_Renderer* ren, SDL_Window* window);
void LinearSearch(std::vector<Block>& block, int size, int val);
void SelectionSort(std::vector<Block>& block, int size, SDL_Window* w, SDL_Renderer* ren);
void BubbleSort(std::vector<Block>& block, int size, SDL_Window* w, SDL_Renderer *ren);

#endif /* ALGO_hpp */
