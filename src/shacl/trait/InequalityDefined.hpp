namespace detail {
template<typename Left, typename Right = Left>
using InequalityResult_t =
  decltype(std::declval<Left>() != std::declval<Right>());

template<typename Left, typename Right = Left, typename = void>
constexpr const bool InequalityDefined_v = false;

template<typename Left, typename Right>
constexpr const bool InequalityDefined_v
<Left, Right, void_t<InequalityResult_t<Left, Right>>> = true;
}

template<typename Left, typename Right = Left>
constexpr const bool InequalityDefined_v =
  detail::InequalityDefined_v<Left, Right>;

template<typename... Args>
using InequalityDefined = bool_t<InequalityDefined_v<Args...>>;
