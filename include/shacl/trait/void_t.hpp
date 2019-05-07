#if __cplusplus < 201703L
  namespace detail {

  template<typename... Ts>
  struct make_void { using type = void; };

  }

  template<typename... Ts>
  using void_t = typename detail::make_void<Ts...>::type;

#else
  template<typename... Ts>
  using void_t = std::void_t<Ts...>;
#endif
