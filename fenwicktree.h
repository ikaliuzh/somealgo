#include <iostream>
#include <cassert>
#include <limits>
#include <vector>


namespace algo {
    template<typename T>
    class FenwickTree {
        using value_type = T;
    public:
        FenwickTree(const std::vector<value_type> &array)
                : tree(array.size() + 1, 0) {
            assert(std::numeric_limits<value_type>::is_specialized);
            for (int32_t i = 0; i < array.size(); ++i) {
                update(i, array[i]);
            }
        }

        FenwickTree(std::initializer_list<value_type> init)
                : tree(init.size() + 1, 0) {
            assert(std::numeric_limits<value_type>::is_specialized);
            int32_t i = 0;
            for (auto el : init) {
                update(i, el);
                ++i;
            }
        }

        void update(int32_t idx, value_type value) {
            ++idx;
            while (idx <= tree.size() - 1) {
                tree[idx] += value;
                idx += idx & -idx;
            }
        }

        value_type sum(int32_t idxl, int32_t idxr) {
            return sum(idxr) - sum(idxl - 1);
        }

    private:
        std::vector<value_type> tree;

        value_type sum(int32_t idx) {
            ++idx;
            value_type s(0);
            while (idx >= 1) {
                s += tree[idx];
                idx -= idx & -idx;
            }
            return s;
        }
    };
}
