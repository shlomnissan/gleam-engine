/*
===========================================================================
  GLEAM ENGINE https://gleamengine.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#include "gleam/resources/bounding_sphere.hpp"

#include "gleam/materials/flat_material.hpp"
#include "gleam/math/utilities.hpp"
#include "gleam/nodes/mesh.hpp"

#include <cmath>

namespace gleam {

BoundingSphere::BoundingSphere(const Sphere& sphere, const Color& color) {
    Add(Mesh::Create(CreateGeometry(sphere), FlatMaterial::Create(color)));
}

auto BoundingSphere::CreateGeometry(const Sphere& sphere) const -> std::shared_ptr<Geometry> {
    constexpr auto segments = 64.0f;

    std::vector<float> vertices;
    std::vector<unsigned> indices;

    const auto center = sphere.center;
    const auto radius = sphere.radius;

    enum class Axis { XY, XZ, YZ };

    for (auto axis = 0; axis < 3; ++axis) {
        auto offset = static_cast<unsigned int>(vertices.size() / 3);
        for (auto i = 0; i <= static_cast<unsigned>(segments); ++i) {
            auto p = center;
            auto theta = (static_cast<float>(i) / segments) * math::two_pi;

            if (axis == static_cast<unsigned>(Axis::XY)) {
                p.x += radius * std::cos(theta);
                p.y += radius * std::sin(theta);
            }
            if (axis == static_cast<unsigned>(Axis::XZ)) {
                p.x += radius * std::cos(theta);
                p.z += radius * std::sin(theta);
            }
            if (axis == static_cast<unsigned>(Axis::YZ)) {
                p.y += radius * std::cos(theta);
                p.z += radius * std::sin(theta);
            }

            vertices.emplace_back(p.x);
            vertices.emplace_back(p.y);
            vertices.emplace_back(p.z);

            if (i > 0) {
                indices.emplace_back(offset + i - 1);
                indices.emplace_back(offset + i);
            }
        }
    }

    auto geometry = Geometry::Create(vertices, indices);
    geometry->primitive = GeometryPrimitiveType::Lines;
    geometry->SetAttribute({
        .type = GeometryAttributeType::Position,
        .item_size = 3
    });

    return geometry;
}

}