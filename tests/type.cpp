#include <rsl/type.hpp>

#include <catch2/catch_test_macros.hpp>

TEST_CASE("rsl::Type") {
    using StrongInt = rsl::Type<int, struct StrongIntTag>;
    static_assert(std::is_same_v<StrongInt::ValueType, int>);

    SECTION("Construction") {
        auto const strong_int = StrongInt(42);
        CHECK(strong_int.get() == 42);
        CHECK(int{strong_int} == 42);
        CHECK(int(strong_int) == 42);
    }

    SECTION("get()") {
        auto strong_int = StrongInt(1337);
        strong_int.get() = 100;
        CHECK(strong_int.get() == 100);
    }
}
