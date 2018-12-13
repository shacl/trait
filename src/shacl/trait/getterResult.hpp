struct getterResult_fn {
  template<typename T>
  using Result =
    std::conditional_t
    <std::is_lvalue_reference<T>::value
     and std::is_const<std::remove_reference_t<T>>::value,
     std::conditional_t
     <std::is_trivially_copyable<std::decay_t<T>::value>
      and std::is_trivially_destructible<std::decay_t<T>::value>
      and (sizeof(std::decay_t<T>) < 9),
       std::decay_t<T>, const std::decay_t<T>&>,
      T>;

  template<typename T>
  constexpr Result<T> operator()(T&& t) const {
    return std::forward<T>(t);
  }
};

static constexpr getterResult_fn getterResult{};
