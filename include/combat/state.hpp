#pragma once

#include <Game/Core.hpp>

#include <string>
#include <vector>

#include "food.hpp"

namespace combat {
  class state {
  public:
    Area combat_area;
    std::vector<std::string> enemy_names;
  };
}