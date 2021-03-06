//=====================================================================================================================================
//The MIT License (MIT)
//Copyright (c) 2015 Austin Salgat
//
//Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files
//(the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify,
//merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished
//to do so, subject to the following conditions:
//The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
//IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//=====================================================================================================================================

#ifndef ENUM_ITERATOR_ENUMIT_HPP
#define ENUM_ITERATOR_ENUMIT_HPP

namespace enumit {
    /**
     * Supports iteration of enumerations (and enumeration classes).
     */
    template<class enum_class>
    class Iterate {
    public:
        enum_class last;

        Iterate() = default;

        Iterate(enum_class last_) {
            last = static_cast<enum_class>(static_cast<int>(last_)+1);
        }

        class Iterator {
        private:
            int current_position;

        public:
            Iterator(Iterator const& iter) = default;

            Iterator(int index = 0) {
                current_position = index;
            }

            ~Iterator(){}

            Iterator& operator=(Iterator const& iter) = default;

            Iterator operator+(int const value) {
                auto temp(*this);
                temp.current_position += value;
                return temp;
            }

            Iterator& operator+=(int const value) {
                current_position += value;
                return *this;
            }

            Iterator operator-(int const value) {
                auto temp(*this);
                temp.current_position -= value;
                return temp;
            }

            Iterator& operator-=(int const value) {
                current_position -= value;
                return *this;
            }

            Iterator& operator++() {
                ++current_position;
                return *this;
            }

            Iterator operator++(int) {
                auto temp(*this);
                ++current_position;
                return temp;
            }

            Iterator& operator--() {
                --current_position;
                return *this;
            }

            Iterator operator--(int) {
                auto temp(*this);
                --current_position;
                return temp;
            }

            bool operator==(Iterator const& other) const {
                return current_position == other.current_position;
            }

            bool operator!=(Iterator const& other) const {
                return current_position != other.current_position;
            }

            enum_class operator*() const {
                return static_cast<enum_class>(current_position);
            }
        };
    };

    template<class enum_class>
    typename Iterate<enum_class>::Iterator begin(Iterate<enum_class>) {
        return typename Iterate<enum_class>::Iterator(0);
    }

    template<class enum_class>
    typename Iterate<enum_class>::Iterator end(Iterate<enum_class> end) {
        return typename Iterate<enum_class>::Iterator(static_cast<int>(end.last));
    }

    /**
     *  Returns iterator pointing to first element of enumeration.
     */
    template<class enum_class>
    typename Iterate<enum_class>::Iterator Begin(enum_class start = static_cast<enum_class>(0)) {
        return typename Iterate<enum_class>::Iterator(static_cast<int>(start));
    };

    /**
     * Returns iterator pointing to one past the last element of enumeration.
     */
    template<class enum_class>
    typename Iterate<enum_class>::Iterator End(enum_class last_entry) {
        return typename Iterate<enum_class>::Iterator(static_cast<int>(last_entry)+1);
    };
}

#endif //ENUM_ITERATOR_ENUMIT_HPP
