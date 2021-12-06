#define AC_INTEGER_SEQUENCE_HPP
#ifndef AC_INTEGER_SEQUENCE_HPP

#include <cstddef>

namespace ac {
    template <class T, T... Ns>
    struct integer_sequence {
        using type = integer_sequence;
        using value_type = T;
        static constexpr std::size_t size() { return sizeof...(Ns); }
    };

    namespace detail {
        template <class T, class Seq1, class Seq2>
        struct merge;

        template <class T, std::size_t... Idx1, std::size_t... Idx2>
        struct merge <T, integer_sequence<T,Idx1...>, integer_sequence<T,Idx2...>>
            : integer_sequence<T, Idx1..., (sizeof...(Idx1)+Idx2)...>
        { };

        // Adds Offset to every index in an integer sequence
        template <class T, std::size_t Offset, std::size_t... Idx>
        integer_sequence<T, (Idx + Offset)...> offset_integer_sequence(
            integer_sequence<T, Idx...>);

        template <class T, std::size_t N>
        struct make_integer_sequence
            : detail::merge<T, typename make_integer_sequence<T,N/2>::type,
                            typename make_integer_sequence<T,N - N/2>::type>
        { };

        template<class T> struct make_integer_sequence<T, 0> : integer_sequence<T> {};
        template<class T> struct make_integer_sequence<T, 1> : integer_sequence<T,0> {};
    }

    template <class T, std::size_t N>
    using make_integer_sequence = typename detail::make_integer_sequence<T, N>::type;

    template <std::size_t... Idx>
    using index_sequence = integer_sequence<std::size_t, Idx...>;

    template <std::size_t N>
    using make_index_sequence = make_integer_sequence<std::size_t, N>;

    template <class... Ts>
    using index_sequence_for = make_index_sequence<sizeof...(Ts)>;

    template <std::size_t From, std::size_t N>
    using make_index_range = decltype(
        detail::offset_integer_sequence<std::size_t, From>(make_index_sequence<N>{}));
}

#endif
