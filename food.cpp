#include "food.h"

vector<pair<int, int>> nibbles;

pair<int, int> make_food() {
    return {experimental::randint(1, LINES - 2), experimental::randint(1, COLS - 2)};
}

void init_food() {
    nibbles.clear();
    for(int i = 0; i < FOOD_COUNT; i++)
        nibbles.push_back(make_food());
}

void paint_food() {
    for(int i = 0; i < nibbles.size(); i++) {
        pair<int, int> location = nibbles[i];
        move(location.first, location.second);
        addstr("x");
    }
}

bool try_comsume_food(pair<int, int> head) {
    // if there is food at head location, consume it, generate new food, and return true
    // if no food at head location, return false
    for(int i = 0; i < nibbles.size(); i++) {
        if(head.first == nibbles[i].first and head.second == nibbles[i].second) {
            // yes, there is a food item at head
            nibbles.erase(nibbles.begin() + i); // remove the ith food item from the vector
            nibbles.push_back(make_food());
            return true;
        }
    }
    return false;
}