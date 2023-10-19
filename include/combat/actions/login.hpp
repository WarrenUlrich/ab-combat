#pragma once

#include <Game/Core.hpp>

#include <util-ai/util-ai.hpp>

#include "../state.hpp"

namespace combat {
class login : public util_ai::base_action<state> {
public:
  double utility(const state &ws) override {
    return Mainscreen::IsLoggedIn() ? -1.0 : 1.0;
  }

  void execute(state &ws) override {
    std::cout << "Logging in...\n";
    if (!Login::LoginPlayer()) {
      std::cout << "Failed to login, retrying\n";
      if (!Login::LoginPlayer()) {
        std::cout << "Failed to login, terminating\n";
        Terminate = true;
      }
    }
  }
};
} // namespace skiller