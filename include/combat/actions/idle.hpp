#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include "../state.hpp"

namespace combat {
class idle : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    return 0.25;
  }

  void execute(state &ws) override {
    std::cout << "Idling\n";
  }
};
} // namespace combat