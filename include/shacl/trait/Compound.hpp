namespace detail {
namespace adl {

using std::get;

template<std::size_t, typename>
std::false_type can_get(...);

template<std::size_t index, typename T,
         typename = decltype(get<index>(std::declval<T>()))>
std::true_type can_get(int);

}

/**
 * The std::array overload of std::get does not fail in an SFINAE friendly way
 * if the index parameter is out of bounds. We check this ourselves using
 * std::tuple_size (if the template is defined) before trying to instantiate
 * the adl-based get. If std::tuple_size is not defined for the parameter type,
 * we can't check beforehand and just hope for the best.
 */
template<std::size_t index, typename T, typename = void>
struct Inbounds : std::true_type {};

template<std::size_t index, typename T>
struct Inbounds<index, T,
                void_t<std::integral_constant
                       <std::size_t, std::tuple_size<T>::value>>> :
    std::integral_constant<bool, (index < std::tuple_size<T>::value)> {};

template<typename T, std::size_t index = 0, bool = Inbounds<index, T>::value>
struct GetDefined : std::false_type {};

template<typename T, std::size_t index>
struct GetDefined<T, index, true> : decltype(adl::can_get<index, T>(0)) {};

template<typename T, std::size_t index = 0>
constexpr const bool GetDefined_v = GetDefined<T, index>::value;

}

namespace compound {
template<long index>
struct get_fn {
  template<typename Compound,
           std::enable_if_t
           <detail::GetDefined_v<Compound, index>, bool> = true>
  constexpr decltype(auto) operator()(Compound&& c) const {
    using std::get;
    return get<index>(std::forward<Compound>(c));
  }

  template<typename Compound,
           std::enable_if_t
           <(not detail::GetDefined_v<Compound> or index < 0)
            and SubscriptDefined_v<Compound, std::size_t>, bool> = true>
  constexpr decltype(auto) operator()(Compound&& c) const {
    return std::forward<Compound>(c)[index];
  }

  template<typename Compound,
           std::enable_if_t
           <(not detail::GetDefined_v<Compound> or index < 0)
            and not SubscriptDefined_v<Compound, std::size_t>
            and InvokeDefined_v<Compound, std::size_t>, bool> = true>
  constexpr decltype(auto) operator()(Compound&& c) const {
    return std::forward<Compound>(c)(index);
  }
};

template<long index>
constexpr const get_fn<index> get{};

}

template<typename T, typename... Ts>
using Compound =
  std::conditional<Conjunction_v<std::is_same<T, Ts>...>,
                   std::array<T, sizeof...(Ts) + 1>,
                   std::tuple<T, Ts...>>;

template<typename T, typename... Ts>
using Compound_t = typename Compound<T, Ts...>::type;
