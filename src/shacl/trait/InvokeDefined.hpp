#if __cplusplus < 201703L

namespace detail {

template<class T, class Type, class T1, class... Args,
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and std::is_base_of<T, std::decay_t<T1>>::value, bool> = true>
auto INVOKE(Type T::* f, T1&& t1, Args&&... args)
  -> decltype((std::forward<T1>(t1).*f)(std::forward<Args>(args)...)) {
  return (std::forward<T1>(t1).*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1, class... Args,
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
auto INVOKE(Type T::* f, T1&& t1, Args&&... args)
  -> decltype((t1.get().*f)(std::forward<Args>(args)...)) {
  return (t1.get().*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1, class... Args,
         std::enable_if_t
         <std::is_member_function_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and not IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
auto INVOKE(Type T::* f, T1&& t1, Args&&... args)
  -> decltype(((*std::forward<T1>(t1)).*f)(std::forward<Args>(args)...)) {
  return ((*std::forward<T1>(t1)).*f)(std::forward<Args>(args)...);
}

template<class T, class Type, class T1,
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and std::is_base_of<T, std::decay_t<T1>>::value, bool> = true>
auto INVOKE(Type T::* f, T1&& t1)
  -> decltype(std::forward<T1>(t1).*f){
  return std::forward<T1>(t1).*f;
}

template<class T, class Type, class T1,
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
auto INVOKE(Type T::* f, T1&& t1)
  -> decltype(t1.get().*f) {
  return t1.get().*f;
}

template<class T, class Type, class T1,
         std::enable_if_t
         <std::is_member_object_pointer<Type T::*>::value
          and not std::is_base_of<T, std::decay_t<T1>>::value
          and not IsReferenceWrapper_v<std::decay_t<T1>>, bool> = true>
auto INVOKE(Type T::* f, T1&& t1)
  -> decltype((*std::forward<T1>(t1)).*f){
  return (*std::forward<T1>(t1)).*f;
}

template <class F, class... Args,
          std::enable_if_t
          <not std::is_member_object_pointer<F>::value
           and not std::is_member_function_pointer<F>::value, bool> = true>
auto INVOKE(F&& f, Args&&... args)
  -> decltype(std::forward<F>(f)(std::forward<Args>(args)...)) {
  return std::forward<F>(f)(std::forward<Args>(args)...);
}

template<typename F, typename... Args>
struct InvokeDefinedImpl {
  template<typename G = F, typename = void>
  struct Type : std::false_type {};

  template<typename G>
  struct Type<G, void_t<decltype(INVOKE(std::declval<G>(),
                                        std::declval<Args>()...))>>
    : std::true_type {};
};

}

template<typename F, typename... Args>
using InvokeDefined =
  typename detail::InvokeDefinedImpl<F, Args...>::template Type<>;

#else

template<typename F, typename... Args>
using InvokeDefined = std::is_invocable<F, Args...>;

#endif

template<typename F, typename... Args>
static constexpr bool InvokeDefined_v = InvokeDefined<F, Args...>::value;

