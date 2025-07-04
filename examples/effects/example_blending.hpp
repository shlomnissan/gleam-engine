/*
===========================================================================
  GLEAM ENGINE https://gleamengine.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#pragma once

#include <gleam/nodes.hpp>
#include <gleam/materials.hpp>

#include <array>
#include <memory>

#include "example_scene.hpp"

class ExampleBlending : public ExampleScene {
public:
    explicit ExampleBlending(std::shared_ptr<gleam::Camera>);

    auto ContextMenu() -> void override;

private:
    std::shared_ptr<gleam::PhongMaterial> transparent_material_;
};