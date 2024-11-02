#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum Category {
    BOOK,
    MOVIE,
    MUSIC
};

string _name(Category category) {
    switch (category) {
    case Category::BOOK: return "BOOK";
    case Category::MOVIE: return "MOVIE";
    case Category::MUSIC: return "MUSIC";
    default: return "UNKNOWN";
    }
}

void _add(
    map<Category, map<string, vector<string>>>& collection,
    Category category,
    const string& subCategory,
    const string& item
) {
    collection[category][subCategory].push_back(item);
}

int main() {
    map<Category, map<string, vector<string>>> allCollections;

    _add(allCollections, Category::BOOK, "Fantasy", "The Lord of the Rings");
    _add(allCollections, Category::BOOK, "Fantasy", "The Hobbit");
    _add(allCollections, Category::MOVIE, "Adventure", "The Lord of the Rings");
    _add(allCollections, Category::MOVIE, "Adventure", "The Hobbit");
    _add(allCollections, Category::MUSIC, "Soundtrack", "The Lord of the Rings");
    _add(allCollections, Category::MUSIC, "Soundtrack", "The Hobbit");

    for (const auto& category : allCollections) {
        cout << "Category: " << _name(category.first) << endl;
        for (const auto& subCategory : category.second) {
            cout << "  SubCategory: " << subCategory.first << endl;
            for (const auto& item : subCategory.second) {
                cout << "    Item: " << item << endl;
            }
        }
    }

    system("pause");
    return 0;
}