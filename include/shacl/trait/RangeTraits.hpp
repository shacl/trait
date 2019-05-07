template<typename T, std::enable_if_t< IsRange_v<T>, bool > = true >
struct RangeTraits {
  
  using iterator_type = decltype( std::begin( std::declval<T>() ) );
  using sentinel_type = decltype( std::end( std::declval<T>() ) );

  using value_type = typename std::iterator_traits<iterator_type>::value_type;
};
