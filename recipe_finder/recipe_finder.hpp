#pragma once

#include "recipe.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

class RecipeFinder
{
public:
    RecipeFinder() { load_recipes(); }
    ~RecipeFinder() = default;

public:
    void add_recipe(const Recipe& recipe);
    void print_recipe() const;
    void save_recipes_to_file() const;
    std::vector<Recipe> find_recipes_by_ingredients(const std::vector<std::string>& ingredients) const;
    static std::vector<std::string> split_string(const std::string& str, char delimiter);
    Recipe create_recipe() const; 
    void run();
    
private:
    void load_recipes();
private:
    std::vector<Recipe> m_recipes;
};