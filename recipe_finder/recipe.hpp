#pragma once

#include <vector>
#include <string>
#include <iostream>

class Recipe
{
public:
    Recipe(const std::string& name, const std::vector<std::string>& ingredients, const std::string& instructions);
    ~Recipe() = default;

public:
    std::string get_name() const;
    std::vector<std::string> get_ingredients() const;
    std::string get_instructions() const;

    void set_name(const std::string&);
    void set_ingredients(const std::vector<std::string>&);
    void set_instructions(const std::string&);

    void display_recipe() const; 

private:
    std::string m_name;
    std::vector<std::string> m_ingredients;
    std::string m_instructions;
};