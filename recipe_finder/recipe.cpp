#include "recipe.hpp"

Recipe::Recipe(const std::string& name, const std::vector<std::string>& ingredients, const std::string& instructions)
    : m_name(name)
    , m_ingredients(ingredients)
    , m_instructions(instructions)
{
}

std::string Recipe::get_name() const
{
    return m_name;
}

std::vector<std::string> Recipe::get_ingredients() const
{
    return m_ingredients;
}

std::string Recipe::get_instructions() const
{
    return m_instructions;
}

void Recipe::set_name(const std::string& name)
{
    m_name = name;
}

void Recipe::set_ingredients(const std::vector<std::string>& ingredients)
{
    m_ingredients = ingredients;
}

void Recipe::set_instructions(const std::string& instructions)
{
    m_instructions = instructions;
}

void Recipe::display_recipe() const 
{
    std::cout << "Recipe: " << m_name << std::endl;
    std::cout << "Ingredients:" << std::endl;
    for (const auto& ingredient : m_ingredients) {
        std::cout << "- " << ingredient << std::endl;
    }
    std::cout << "Instructions: " << m_instructions << std::endl;
    std::cout << std::endl;
}