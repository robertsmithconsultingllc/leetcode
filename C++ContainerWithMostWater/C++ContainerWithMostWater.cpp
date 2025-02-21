// C++ContainerWithMostWater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(vector<int>&);

int main() 
{
    vector<int> height = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << "The maximum area is: " << maxArea(height) << endl;
    return 0;
}

int maxArea(vector<int>& height) 
{
    int left = 0;
    int right = (int)height.size() - 1;
    int max_area = 0;

    while (left < right) 
    {
        int width = right - left;
        int current_height = min(height[left], height[right]);
        int current_area = width * current_height;
        max_area = max(max_area, current_area);

        if (height[left] < height[right]) 
        {
            left++;
        }
        else 
        {
            right--;
        }
    }

    return max_area;
}


