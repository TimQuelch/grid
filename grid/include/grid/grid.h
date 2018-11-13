#ifndef GRID_GRID_H
#define GRID_GRID_H

namespace grid {
    template <typename T>
    class Grid {
    public:
        using value_type = typename std::vector<T>::value_type;
        using size_type = typename std::vector<T>::size_type;
        using difference_type = typename std::vector<T>::difference_type;
        using reference = typename std::vector<T>::reference;
        using const_reference = typename std::vector<T>::const_reference;
        using pointer = typename std::vector<T>::pointer;
        using const_pointer = typename std::vector<T>::const_pointer;
        using iterator = typename std::vector<T>::iterator;
        using const_iterator = typename std::vector<T>::const_iterator;
        using reverse_iterator = typename std::vector<T>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<T>::const_reverse_iterator;

        struct Dims {
            size_type rows;
            size_type cols;
            [[nodiscard]] constexpr auto nElems() const noexcept { return rows * cols; }
        };

        Grid() = default;
        explicit Grid(Dims dims) : data_(dims.nElems()){};

        void resize(Dims dims) { data_.resize(dims.nElems()); }

        [[nodiscard]] auto begin() noexcept { return data_.begin(); }
        [[nodiscard]] auto end() noexcept { return data_.end(); }
        [[nodiscard]] auto begin() const noexcept { return data_.cbegin(); }
        [[nodiscard]] auto end() const noexcept { return data_.cend(); }
        [[nodiscard]] auto cbegin() const noexcept { return data_.cbegin(); }
        [[nodiscard]] auto cend() const noexcept { return data_.cend(); }

        [[nodiscard]] auto rbegin() noexcept { return data_.rbegin(); }
        [[nodiscard]] auto rend() noexcept { return data_.rend(); }
        [[nodiscard]] auto rbegin() const noexcept { return data_.crbegin(); }
        [[nodiscard]] auto rend() const noexcept { return data_.crend(); }
        [[nodiscard]] auto crbegin() const noexcept { return data_.crbegin(); }
        [[nodiscard]] auto crend() const noexcept { return data_.crend(); }

        [[nodiscard]] constexpr auto size() const noexcept { return data_.size(); }
        [[nodiscard]] constexpr auto empty() const noexcept { return data_.empty(); }

    private:
        std::vector<T> data_ = {};
    };
} // namespace grid

#endif
