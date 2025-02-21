// C++GroupAnagrams.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

vector<vector<string>> groupAnagrams(vector<string>&);

int main() 
{
    vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
    vector<vector<string>> groupedAnagrams = groupAnagrams(strs);

    for (const auto& group : groupedAnagrams) 
    {
        for (const auto& word : group) 
        {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) 
{
    unordered_map<string, vector<string>> anagramMap;

    for (const auto& str : strs) 
    {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());
        anagramMap[sortedStr].push_back(str); 
    }

    vector<vector<string>> result;
    
    for (const auto& pair : anagramMap) 
    {
        result.push_back(pair.second);
    }

    return result;
}


