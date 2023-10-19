#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include <optional>

#include "../state.hpp"

namespace combat {
class eat_food : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    auto max_health = Stats::GetRealLevel(Stats::HITPOINTS);
    auto current_health =
        Stats::GetCurrentLevel(Stats::HITPOINTS);

    if (max_health == current_health)
      return -1.0;

    auto health_deficit = max_health - current_health;

    std::optional<std::pair<food, Interactable::Item>>
        best_food;
    double best_util =
        std::numeric_limits<double>::lowest();

    for (const auto &[name, food] : food::food_name_map) {
      auto item = Inventory::GetItem(name);
      if (!item) // not found
        continue;

      auto util =
          (food.restoration - health_deficit) / max_health;
      if (util > best_util) {
        best_food = std::make_pair(food, item);
        best_util = util;
      }
    }

    if (!best_food.has_value()) {
      return -1.0;
    }

    std::cout << "best food util: " << best_util << '\n';
    _to_eat = best_food.value().second;
    return std::max(-1.0, std::min(1.0, best_util));
  }

  void execute(state &ws) override {
    if (!_to_eat)
      return;

    std::cout << "Eating food\n";
  }

private:
  Interactable::Item _to_eat;
};
} // namespace combat