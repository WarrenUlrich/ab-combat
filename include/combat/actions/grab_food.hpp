#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include "../state.hpp"

namespace combat {
class grab_food : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    if (_has_food()) {
      return -1.0;
    }

    return 1.0;
  }

  void execute(state &ws) override {
    std::cout << "Grabbing food\n";
  }

private:
  bool _has_food() {
    for (const auto &[name, _] : food::food_name_map) {
      if (Inventory::Contains(name)) {
        return true;
      }
    }

    return false;
  }
};
} // namespace combat