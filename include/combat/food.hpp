#pragma once

#include <string>
#include <unordered_map>

namespace combat {
class food {
public:
  std::string name;
  std::int32_t restoration;

  food(std::string name, std::int32_t restoration)
      : name(std::move(name)), restoration(restoration) {}
  
  static std::unordered_map<std::string, food> food_name_map;
};

std::unordered_map<std::string, food> food::food_name_map = {
    {"Shrimps", food("Shrimps", 3)},
    {"Trout", food("Trout", 7)},
    {"Salmon", food("Salmon", 9)},
    {"Tuna", food("Tuna", 10)},
    {"Lobster", food("Lobster", 12)},
    {"Swordfish", food("Swordfish", 14)},
    {"Monkfish", food("Monkfish", 16)},
    {"Shark", food("Shark", 20)},
    {"Sea turtle", food("Sea turtle", 21)},
    {"Manta ray", food("Manta ray", 22)},
    {"Karambwan", food("Karambwan", 18)},
    {"Anglerfish", food("Anglerfish", 22)},
    {"Dark crab", food("Dark crab", 22)},
    {"Jug of wine", food("Jug of wine", 11)}
};
} // namespace combat