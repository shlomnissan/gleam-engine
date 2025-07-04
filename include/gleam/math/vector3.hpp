/*
===========================================================================
  GLEAM ENGINE https://gleamengine.org
  Copyright © 2024 - Present, Shlomi Nissan
===========================================================================
*/

#pragma once

#include "gleam_export.h"

#include <cassert>

namespace gleam {

class Vector4;

/**
 * @brief A 3D vector class for mathematical operations.
 */
class GLEAM_EXPORT Vector3 {
public:
    /// @brief The x component of the vector.
    float x;
    /// @brief The y component of the vector.
    float y;
    /// @brief The z component of the vector.
    float z;

    /**
     * @brief Default constructor.
     */
    Vector3() = default;

    /**
     * @brief Constructs a vector with all components initialized to the given value.
     *
     * @param value The value to initialize all components of the vector.
     */
    Vector3(float value);

    /**
     * @brief Constructs a vector with the specified x, y, and z components.
     *
     * @param x The x component of the vector.
     * @param y The y component of the vector.
     * @param z The z component of the vector.
     */
    Vector3(float x, float y, float z);

    /**
     * @brief Constructs a Vector3 object from a Vector4 object.
     *
     * @param v The Vector4 object from which to extract the x, y, and z components.
     */
    explicit Vector3(const Vector4& v);

    /**
     * @brief Returns a unit vector along the X axis.
     *
     * @return Vector3 A `Vector3` instance representing the X unit vector.
     */
    [[nodiscard]] static auto Right() { return Vector3 {1.0f, 0.0f, 0.0f}; }

    /**
     * @brief Returns a unit vector along the Y axis.
     *
     * @return Vector3 A `Vector3` instance representing the Y unit vector.
     */
    [[nodiscard]] static auto Up() { return Vector3 {0.0f, 1.0f, 0.0f}; }

    /**
     * @brief Returns a unit vector along the Z axis.
     *
     * @return Vector3 A `Vector3` instance representing the Z unit vector.
     */
    [[nodiscard]] static auto Forward() { return Vector3 {0.0f, 0.0f, 1.0f}; }

    /**
     * @brief Returns a zero vector.
     *
     * @return Vector3 A `Vector3` instance representing the zero vector.
     */
    [[nodiscard]] static auto Zero() { return Vector3 {0.0f}; }

    /**
     * @brief Calculates the length (magnitude) of the vector.
     *
     * @return float The length of the vector.
     */
    [[nodiscard]] auto Length() const -> float;

    /**
     * @brief Calculates the squared length of the vector.
     *
     * @return float The squared length of the vector.
     */
    [[nodiscard]] auto LengthSquared() const -> float;

    /**
     * @brief Accesses the component at the specified index.
     *
     * @param i The index of the component to access (0, 1, or 2).
     * @return float& A reference to the component at the specified index.
     */
    [[nodiscard]] auto& operator[](int i) {
        assert(i >= 0 && i < 3);
        return (reinterpret_cast<float*>(this))[i];
    }

    /**
     * @brief Accesses the component at the specified index (const version).
     *
     * @param i The index of the component to access (0, 1, or 2).
     * @return const float& A const reference to the component at the specified index.
     */
    [[nodiscard]] const auto& operator[](int i) const {
        assert(i >= 0 && i < 3);
        return (reinterpret_cast<const float*>(this))[i];
    }

    /**
     * @brief Multiplies the vector by a scalar value.
     *
     * @param n The scalar value to multiply with.
     * @return Vector3& A reference to the updated vector.
     */
    auto operator*=(float n) -> Vector3& {
        x *= n;
        y *= n;
        z *= n;
        return *this;
    }

    /**
     * @brief Multiplies the vector by another vector.
     *
     * @param v The Vector to multiply with.
     * @return Vector3& A reference to the updated vector.
     */
    auto operator*=(const Vector3& v) -> Vector3& {
        x *= v.x;
        y *= v.y;
        z *= v.z;
        return *this;
    }

    /**
     * @brief Adds a vector to the current vector.
     *
     * @param v The vector to add.
     * @return Vector3& A reference to the updated vector.
     */
    auto operator+=(const Vector3& v) -> Vector3& {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    /**
     * @brief Subtracts a vector from the current vector.
     *
     * @param v The vector to subtract.
     * @return Vector3& A reference to the updated vector.
     */
    auto operator-=(const Vector3& v) -> Vector3& {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return *this;
    }

    /**
     * @brief Normalizes the vector.
     *
     * @return Vector3& A reference to the normalized vector.
     */
    auto Normalize() -> Vector3& {
        const auto len = Length();
        if (len == 0.0f) {
            return *this;
        }
        return *this *= (1.0f / len);
    }

private:
    /**
     * @brief Checks if two vectors are equal, component-wise.
     *
     * @param a The first vector to compare.
     * @param b The second vector to compare.
     * @return bool `true` if the vectors are equal, `false` otherwise.
     */
    [[nodiscard]] friend auto operator==(const Vector3& a, const Vector3& b) -> bool = default;

    /**
     * @brief Adds two vectors component-wise.
     * @related Vector3
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return Vector3 A new vector that is the component-wise sum of the two vectors.
     */
    [[nodiscard]] friend auto operator+(const Vector3& a, const Vector3& b) {
        return Vector3 {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    /**
     * @brief Subtracts the second vector from the first vector component-wise.
     * @related Vector3
     *
     * @param a The vector to subtract from.
     * @param b The vector to subtract.
     * @return Vector3 A new vector that is the component-wise difference of the two vectors.
     */
    [[nodiscard]] friend auto operator-(const Vector3& a, const Vector3& b) {
        return Vector3 {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    /**
     * @brief Multiplies the vector by a scalar value.
     * @related Vector3
     *
     * @param v The vector to be scaled.
     * @param n The scalar value to multiply with.
     * @return Vector3 A new vector that is the result of scaling the original vector.
     */
    [[nodiscard]] friend auto operator*(const Vector3& v, float n) {
        return Vector3 {v.x * n, v.y * n, v.z * n};
    }

    /**
     * @brief Multiplies a scalar value by a vector.
     * @related Vector3
     *
     * @param n The scalar value to multiply with.
     * @param v The vector to be scaled.
     * @return Vector3 A new vector that is the result of scaling the original vector.
     */
    [[nodiscard]] friend auto operator*(float n, const Vector3& v) {
        return v * n;
    }

    /**
     * @brief Multiplies two vectors component-wise.
     * @related Vector3
     *
     * @param a The first vector.
     * @param b The second vector.
     * @return Vector3 A new vector that is the component-wise product of the two input vectors.
     */
    [[nodiscard]] friend auto operator*(const Vector3& a, const Vector3& b) {
        return Vector3 {a.x * b.x, a.y * b.y, a.z * b.z};
    }

    /**
     * @brief Divides the vector by a scalar value.
     * @related Vector3
     *
     * @param v The vector to be divided.
     * @param n The scalar value to divide by.
     * @return Vector3 A new vector that is the result of dividing the original vector by the scalar.
     */
    [[nodiscard]] friend auto operator/(const Vector3& v, float n) {
        n = 1.0f / n;
        return Vector3 {v.x * n, v.y * n, v.z * n};
    }
};

/**
 * @brief Computes the cross product of two vectors.
 * @related Vector3
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return Vector3 A new vector that is the result of the cross product of the two input vectors.
 */
[[nodiscard]] inline auto Cross(const Vector3& a, const Vector3& b) {
    return Vector3 {
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}

/**
 * @brief Computes the dot product of two vectors.
 * @related Vector3
 *
 * @param a The first vector.
 * @param b The second vector.
 * @return float A scalar value that is the result of the dot product of the two input vectors.
 */
[[nodiscard]] inline auto Dot(const Vector3& a, const Vector3& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

/**
 * @brief Normalizes the vector.
 * @related Vector3
 *
 * @param v The vector to normalize.
 * @return Vector3 A new vector that is the normalized version of the input vector.
 */
[[nodiscard]] inline auto Normalize(const Vector3& v) {
    const auto len = v.Length();
    if (len == 0.0f) {
        return Vector3::Zero();
    }
    return v * (1.0f / len);
}

/**
 * @brief Performs linear interpolation between two vectors.
 * @related Vector3
 *
 * @param v1 The starting vector.
 * @param v2 The ending vector.
 * @param f The interpolation factor (0.0 to 1.0).
 * @return Vector3 A new vector that is the result of the linear interpolation.
 */
[[nodiscard]] inline auto Lerp(const Vector3& v1, const Vector3& v2, float f) {
    return v1 + (v2 - v1) * f;
}

}