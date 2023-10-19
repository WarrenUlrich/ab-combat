#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include "../state.hpp"

namespace combat {
class attack_enemy : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    auto player = Players::GetLocal();
    if (!player) {
      return -1.0;
    }

    auto location = player.GetTile();
    if (!ws.combat_area.Contains(location)) {
      return -1.0;
    }

    auto interacting = player.GetInteracting();
    if (interacting)
      return -1.0;

    auto to_attack =
        NPCs::GetAll([&](const Interactable::NPC &npc) {
          if (std::find(ws.enemy_names.begin(),
                        ws.enemy_names.end(),
                        npc.GetName()) ==
              ws.enemy_names.end())
            return false;

          auto npc_location = npc.GetTile();
          if (!ws.combat_area.Contains(npc_location))
            return false;

          return true;
        });

    if (to_attack.empty())
      return -1.0;

    _to_attack = to_attack.front();
    return 1.0;
  }

  void execute(state &ws) override {
    std::cout << "Attacking enemy\n";
    if (_to_attack.GetVisibility() < .75) {
      if (!Camera::RotateTo(_to_attack.GetTile(),
                            Camera::NORTH))
        return;
    }

    _to_attack.Interact("Attack");
  }

private:
  Interactable::NPC _to_attack;
};
} // namespace combat