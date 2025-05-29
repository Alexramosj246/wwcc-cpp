#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/*
Dish name and Recipe name might be the same but I used it as having multiple of the same category.


example: dish name: Lasagna
		 Recipe name: Three chesse lasagna, keto lasagna, three meat lasagna
if you search for lasagna, you shoud get all these if you input them

*/

class Recipe {
private:
	string dishName;
	string recipeName;
	vector<string> ingredients;
	vector<string> steps;

public:
	Recipe(string d, string r, const vector<string>& ing, const vector<string>& st)
		: dishName(d), recipeName(r), ingredients(ing), steps(st) {}

	string getDishName() const { return dishName; }
	string getRecipeName() const { return recipeName; }
	int getIngredientsCount() const { return ingredients.size(); }
	int getStepsCount() const { return steps.size(); }

	void display() const {
		cout << "\n--- " << recipeName << " ---" << endl;
		cout << "Dish: " << dishName << endl;

		cout << "\nIngredients (" << ingredients.size() << "):" << endl;
		for (size_t i = 0; i < ingredients.size(); ++i) {
			cout << i + 1 << ". " << ingredients[i] << endl;
		}

		cout << "\nSteps (" << steps.size() << "):" << endl;
		for (size_t i = 0; i < steps.size(); ++i) {
			cout << i + 1 << ". " << steps[i] << endl;
		}
	}
};

class RecipeManager {
private:
	vector<Recipe> recipes;

public:
	void addRecipe() {
		string dish, name;
		int numIngredients, numSteps;
		vector<string> ingredients, steps;

		cin.ignore(); // clear buffer
		cout << "\nEnter dish name: ";
		getline(cin, dish);
		cout << "Enter recipe name: ";
		getline(cin, name);

		cout << "How many ingredients? ";
		cin >> numIngredients;
		cin.ignore();

		for (int i = 0; i < numIngredients; ++i) {
			string ing;
			cout << "Enter ingredient " << i + 1 << ": ";
			getline(cin, ing);
			ingredients.push_back(ing);
		}

		cout << "How many steps? ";
		cin >> numSteps;
		cin.ignore();

		for (int i = 0; i < numSteps; ++i) {
			string step;
			cout << "Enter step " << i + 1 << ": ";
			getline(cin, step);
			steps.push_back(step);
		}

		recipes.emplace_back(dish, name, ingredients, steps);
		cout << "\nRecipe added successfully!\n";
	}

	void displayAll() const {
		if (recipes.empty()) {
			cout << "\nNo recipes to display.\n";
			return;
		}
		for (const Recipe& r : recipes) {
			r.display();
			cout << endl;
		}
	}

	void searchRecipe() const {
		if (recipes.empty()) {
			cout << "\nNo recipes in the collection.\n";
			return;
		}

		cin.ignore();
		string query;
		cout << "\nEnter dish name to search: ";
		getline(cin, query);

		bool found = false;
		for (const Recipe& r : recipes) {
			if (r.getDishName() == query) {
			r.display();
				found = true;
			}
		}

		if (!found) {
			cout << "\nRecipe not found.\n";
		}
	}

	void removeRecipe() {
		if (recipes.empty()) {
			cout << "\nNo recipes to remove.\n";
			return;
		}

		cin.ignore();
		string query;
		cout << "\nEnter dish name to remove: ";
		getline(cin, query);

		for (auto it = recipes.begin(); it != recipes.end(); ++it) {
			if (it->getDishName() == query) {
				recipes.erase(it);
				cout << "Recipe removed successfully.\n";
				return;
			}
		}

		cout << "Recipe not found.\n";
	}

	void showStatistics() const {
		cout << "\nCOLLECTION STATISTICS\n--------------------\n";
		int total = recipes.size();
		cout << "Total recipes: " << total << endl;

		if (total == 0) {
			cout << "Average ingredients per recipe: 0.0\n";
			cout << "Average steps per recipe: 0.0\n";
			return;
		}

		int totalIng = 0, totalSteps = 0;
		for (const Recipe& r : recipes) {
			totalIng += r.getIngredientsCount();
			totalSteps += r.getStepsCount();
		}

		cout << fixed << setprecision(1);
		cout << "Average ingredients per recipe: " << (float)totalIng / total << endl;
		cout << "Average steps per recipe: " << (float)totalSteps / total << endl;
    }
};

void displayMenu() {
	cout << "\nDYNAMIC RECIPE MANAGER\n---------------------\n";
	cout << "1. Add Recipe\n";
	cout << "2. Display All Recipes\n";
	cout << "3. Search Recipes\n";
	cout << "4. Remove Recipe\n";
	cout << "5. Show Statistics\n";
	cout << "6. Exit\n";
	cout << "\nEnter choice: ";
}

int main() {
	RecipeManager manager;
	int choice;

	do {
		displayMenu();
		cin >> choice;

		switch (choice) {
			case 1: manager.addRecipe(); break;
			case 2: manager.displayAll(); break;
			case 3: manager.searchRecipe(); break;
			case 4: manager.removeRecipe(); break;
			case 5: manager.showStatistics(); break;
			case 6: cout << "\nNow exiting...\n"; break;
			default: cout << "Invalid choice. Please enter a number between 1 and 6.\n";
		}

	} while (choice != 6);

	return 0;
}