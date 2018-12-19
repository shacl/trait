namespace detail {
template<typename Left, typename Right = Left, typename = void>
constexpr const bool InequalityDefined_v = false;

template<typename Left, typename Right>
constexpr const bool InequalityDefined_v
<Left, Right, void_t<decltype(std::declval<Left>()
                              != std::declval<Right>())>> = true;
}

template<typename Left, typename Right>
using InequalityDefined = bool_t<detail::InequalityDefined_v<Left, Right>>;

template<typename Left, typename Right = Left>
constexpr const bool InequalityDefined_v =
  detail::InequalityDefined_v<Left, Right>;
