#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include <combat/combat.hpp>

void Setup() {
  ScriptInfo Info;
  Info.Name = "ab-combat";
  Info.Description = "";
  Info.Version = "1.00";
  Info.Category = "Combat";
  Info.Author = "Warren";
  Info.UID = "UID";
  Info.ForumPage = "forum.alpacabot.org";
  SetScriptInfo(Info);
}

combat::state state{
    .combat_area =
        Area(Tile(3203, 3468, 0), Tile(3222, 3459, 0)),
    .enemy_names = {"Guard"}};

util_ai::agent<combat::state> agent{};

bool OnStart() {
  agent.add_action(std::make_unique<combat::login>());
  agent.add_action(std::make_unique<combat::grab_food>());
  agent.add_action(std::make_unique<combat::eat_food>());
  agent.add_action(std::make_unique<combat::idle>());
  agent.add_action(
      std::make_unique<combat::attack_enemy>());
  agent.add_action(
      std::make_unique<combat::walk_to_combat_area>());
  return true;
}

bool Loop() {
  agent.decide_and_act(state);
  return true;
}

bool OnBreak() { return false; }

void OnEnd() {}