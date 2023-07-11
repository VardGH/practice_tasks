#include "recipe_finder.hpp"

void RecipeFinder::add_recipe(const Recipe& recipe)
{
    m_recipes.push_back(recipe);
    save_recipes_to_file();
}

void RecipeFinder::print_recipe() const
{
    for (int i = 0; i < m_recipes.size(); ++i) {
        std::cout << "Name: " << m_recipes[i].get_name() << std::endl;

        std::cout << "Ingredients: ";
        const std::vector<std::string>& ingredients = m_recipes[i].get_ingredients();
        for (int j = 0; j < ingredients.size(); ++j) {
            std::cout << ingredients[j] << " ";
        }
        std::cout << std::endl;

        std::cout << "Instructions: " << m_recipes[i].get_instructions() << std::endl;
        std::cout << std::endl;
    }
}

void RecipeFinder::save_recipes_to_file() const
{
    std::ofstream file("recipes.txt");
    if (file.is_open()) {
        for (const auto& recipe : m_recipes) {
            file << "Name: " << recipe.get_name() << std::endl;

            file << "Ingredients: ";
            const std::vector<std::string>& ingredients = recipe.get_ingredients();
            for (int j = 0; j < ingredients.size(); ++j) {
                file << ingredients[j] << " ";
            }
            file << std::endl;

            file << "Instructions: " << recipe.get_instructions() << std::endl;
            file << std::endl;
        }
        file.close();
        std::cout << "Recipe added successfully and saved to file!" << std::endl;
    } else {
        std::cout << "Unable to open file for saving recipes." << std::endl;
    }
}

void RecipeFinder::load_recipes() 
{
    std::ifstream file("recipes.txt");
    if (file.is_open()) {
        std::string line;
        Recipe recipe("", {}, "");
        while (getline(file, line)) {
            if (!line.empty()) {
                if (line.find("Name: ") != std::string::npos) {
                    recipe.set_name(line.substr(6));
                } else if (line.find("Ingredients: ") != std::string::npos) {
                    std::vector<std::string> ingredients;
                    std::istringstream iss(line.substr(13));
                    std::string ingredient;
                    while (iss >> ingredient) {
                        ingredients.push_back(ingredient);
                    }
                    recipe.set_ingredients(ingredients);
                } else if (line.find("Instructions: ") != std::string::npos) {
                    recipe.set_instructions(line.substr(14));
                }
            } else {
                m_recipes.push_back(recipe);
                recipe = Recipe("", {}, "");
            }
        }
        file.close();
        std::cout << "Recipes loaded successfully!" << std::endl;
    } else {
        std::cout << "Unable to open file for loading recipes. Starting with an empty recipe collection." << std::endl;
    }
}

std::vector<Recipe> RecipeFinder::find_recipes_by_ingredients(const std::vector<std::string>& ingredients) const 
{
    std::vector<Recipe> matching_recipes;
    for (const auto& recipe : m_recipes) {
        const std::vector<std::string>& recipe_ingredients = recipe.get_ingredients();
        bool all_ingredients_found = true;
        for (const auto& ingredient : ingredients) {
            if (std::find(recipe_ingredients.begin(), recipe_ingredients.end(), ingredient) == recipe_ingredients.end()) {
                all_ingredients_found = false;
                break;
            }
        }
        if (all_ingredients_found) {
            matching_recipes.push_back(recipe);
        }
    }
    return matching_recipes;
}

std::vector<std::string> RecipeFinder::split_string(const std::string& str, char delimiter) 
{
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

Recipe RecipeFinder::create_recipe() const {
    std::string name;
    std::vector<std::string> ingredients;
    std::string instructions;

    std::cout << "Enter recipe name: ";
    std::getline(std::cin >> std::ws, name);

    std::cout << "Enter ingredients (comma-separated): ";
    std::string ingredientsInput;
    std::getline(std::cin >> std::ws, ingredientsInput);
    ingredients = RecipeFinder::split_string(ingredientsInput, ',');

    std::cout << "Enter instructions: ";
    std::getline(std::cin >> std::ws, instructions);

    Recipe new_recipe(name, ingredients, instructions);
    return new_recipe;
}

void RecipeFinder::run() {
    while (true) {
        std::cout << "====== Recipe Finder ======" << std::endl;
        std::cout << "1. Search for recipes by ingredients" << std::endl;
        std::cout << "2. Add a new recipe" << std::endl;
        std::cout << "3. Print all recipes" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                std::cout << "Enter ingredients (comma-separated): ";
                std::string ingredientsInput;
                std::getline(std::cin, ingredientsInput);
                std::vector<std::string> ingredients = RecipeFinder::split_string(ingredientsInput, ',');
                std::vector<Recipe> matchingRecipes = find_recipes_by_ingredients(ingredients);
                if (!matchingRecipes.empty()) {
                    std::cout << "Matching recipes:" << std::endl;
                    for (const auto& recipe : matchingRecipes) {
                        recipe.display_recipe();
                    }
                } else {
                    std::cout << "No recipes found for the entered ingredients." << std::endl;
                }
                break;
            }
            case 2: {
                Recipe new_recipe = create_recipe();
                add_recipe(new_recipe);
                std::cout << "Recipe added successfully!" << std::endl;
                break;
            }
            case 3:
                if (!m_recipes.empty()) {
                    std::cout << "All recipes:" << std::endl;
                    print_recipe();
                } else {
                    std::cout << "No recipes found." << std::endl;
                }
                break;
            case 4:
                //save_recipes_to_file();
                std::cout << "Exiting the Recipe Finder. Goodbye!" << std::endl;
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        std::cout << std::endl;
    }
}
