/*
===========================================================================
  GLEAM ENGINE https://gleamengine.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "renderer/gl/gl_programs.hpp"

#include "utilities/logger.hpp"

#include <vector>

namespace gleam {

auto GLPrograms::GetProgram(const ProgramAttributes& attrs) -> GLProgram* {
    const auto& key = attrs.key;
    if (!programs_.contains(key)) {
        auto sources = shader_lib_.GetShaderSource(attrs);
        if (sources.empty()) return nullptr;
        Logger::Log(LogLevel::Info, "Creating a new shader program {}", key);
        programs_[key] = std::make_unique<GLProgram>(sources);
    }
    return programs_[key].get();
}

}