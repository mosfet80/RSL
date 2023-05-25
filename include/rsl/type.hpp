#pragma once

namespace rsl {

/** @file */

/**
 * @brief Class template for creating strong type aliases
 *
 * @tparam T value type
 * @tparam Tag Tag type to diambiguate separate type aliases
 */
template <typename T, typename Tag>
class Type {
    T value_;

   public:
    using ValueType = T;

    explicit Type(const T& value) : value_(value) {}
    [[nodiscard]] T& get() { return value_; }
    [[nodiscard]] const T& get() const { return value_; }
    [[nodiscard]] explicit operator T() const { return value_; }
};

}  // namespace rsl
