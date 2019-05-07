namespace detail {
template<typename Left, typename Right>
using EqualityResult_t =
  decltype(std::declval<Left>() == std::declval<Right>());

template<typename Left, typename Right = Left, typename = void>
constexpr const bool EqualityDefined_v = false;

template<typename Left, typename Right>
constexpr const bool EqualityDefined_v
<Left, Right, void_t<EqualityResult_t<Left, Right>>> = true;
}

template<typename Left, typename Right = Left>
constexpr const bool EqualityDefined_v =
  detail::EqualityDefined_v<Left, Right>;

template<typename... Args>
using EqualityDefined = bool_t<EqualityDefined_v<Args...>>;
