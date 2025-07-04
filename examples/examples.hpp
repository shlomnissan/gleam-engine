/*
===========================================================================
  GLEAM ENGINE https://gleamengine.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#pragma once

#include <vector>

#include <gleam/nodes.hpp>

#include "effects/example_blending.hpp"
#include "effects/example_fog.hpp"
#include "lights/example_directional_light.hpp"
#include "lights/example_point_light.hpp"
#include "lights/example_spot_light.hpp"
#include "materials/example_flat_material.hpp"
#include "materials/example_phong_material.hpp"
#include "materials/example_shader_material.hpp"
#include "meshes/example_arbitrary_mesh.hpp"
#include "meshes/example_primitive_mesh.hpp"
#include "resources/example_arrow_resource.hpp"
#include "resources/example_grid_resource.hpp"
#include "test/example_frustum_culling_test.hpp"
#include "test/example_lerp_animation_test.hpp"

static const auto examples = std::vector {
    "Flat Material",
    "Phong Material",
    "Shader Material",
    "",
    "Directional Light",
    "Point Light",
    "Spot Light",
    "",
    "Arbitrary Mesh",
    "Primitive Mesh",
    "",
    "Blending Effect",
    "Fog Effect",
    "",
    "Arrow Resource",
    "Grid Resource",
    "",
    "Frustum Culling Test",
    "Lerp Animation Test"
};