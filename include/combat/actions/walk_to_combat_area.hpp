#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include "../state.hpp"

namespace combat {
class walk_to_combat_area : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    auto player = Players::GetLocal();
    if (!player)
      return -1.0;
    
    auto location = player.GetTile();
    if (ws.combat_area.Contains(location)) {
      return -1.0;
    }
  
    return 1.0;
  }

  void execute(state &ws) override {
    std::cout << "Walking to combat area\n";
  }
};
} // namespace combat