namespace detail {
template<typename Left, typename Right = Left, typename = void>
constexpr const bool EqualityDefined_v = false;

template<typename Left, typename Right>
constexpr const bool EqualityDefined_v
<Left, Right, void_t<decltype(std::declval<Left>()
                              == std::declval<Right>())>> = true;
}

template<typename Left, typename Right>
using EqualityDefined = bool_t<detail::EqualityDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
constexpr const bool EqualityDefined_v =
  detail::EqualityDefined_v<Left, Right>;
