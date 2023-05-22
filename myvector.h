#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <memory>
#include <algorithm>

template <class T> class Vector
{
    public:
        using iterator = T*;
        using const_iterator = const T*;
        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator> ;
        using size_type = size_t;
        using value_type = T;

        Vector() { create(); };
        explicit Vector(size_t n, const T& val = T{}) { create(n, val); }
        Vector(const std::initializer_list<T> initList) { create(initList.begin(), initList.end()); } // c-tor su initializer list
        Vector(iterator first, iterator last) { create(first, last); }
        Vector(const Vector& v) { create(v.begin(), v.end()); } // copy c-tor
        Vector(Vector&& v) : data(std::move(v.data)), avail(std::move(v.avail)), limit(std::move(v.limit)) // move c-tor
        {
            v.data = v.avail = v.limit = nullptr;
        }

        Vector& operator=(Vector&& rhs) // move priskyrimo operatorius
        {
            if (&rhs != this) {
                uncreate();
                data = std::move(rhs.data);
                avail = std::move(rhs.avail);
                limit = std::move(rhs.limit);
                rhs.data = rhs.avail = rhs.limit = nullptr;
            }
            return *this;
        }

        Vector& operator=(const Vector& rhs) // copy priskyrimo operatorius
        {
            if (&rhs != this) {
                uncreate();
                create(rhs.begin(), rhs.end());
            }
            return *this;
        }

        ~Vector() { uncreate(); } // d-tor

        void assign(size_type n, const T& value)  //assign funkcijos su dydzio bei reiksmes, dvieju iteratoriu bei initializer list argumentais
        {
            clear();
            if (n > capacity())
                grow(n);

            while (size() < n)
                unchecked_append(value);
        }

        void assign(iterator first, iterator last)
        {
            size_type n = std::distance(first, last);

            clear();
            if (n > capacity())
                grow(n);

            while (first != last)
            {
                unchecked_append(*first);
                ++first;
            }
        }

        void assign(std::initializer_list<T> initList)
        {
            assign(initList.begin(), initList.end());
        }

        /*= = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = =*/

        T& at(size_type n)
        {
            if(n < size())
                return data[n];
            else
                throw std::out_of_range("Vector::at()");
        }

        T& operator[](size_type i){ return data[i]; } // indeksavimas
        const T& operator[](size_type i) const { return data[i]; }

        T& front() { return data[0]; }
        const T &front() const { return data[0]; }

        T& back() { return data[size()-1]; }
        const T &back() const { return data[size()-1]; }

        /*= = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = =*/

        iterator begin() { return data; } // begin, end, rbegin ir ir rend persidengiancios funkcijos, grazinancios iteratorius
        const_iterator begin() const { return data; }

        iterator end() { return avail; }
        const_iterator end() const { return avail; }

        reverse_iterator rbegin() { return reverse_iterator(avail); }
        const_reverse_iterator rbegin() const { return reverse_iterator(avail); }

        reverse_iterator rend() { return reverse_iterator(data); }
        const_reverse_iterator rend() const { return reverse_iterator(data); }


        /*= = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = =*/

        bool empty() const { return (begin() == end()); }
        size_type size() const { return avail - data; }
        typename Vector<T>::size_type max_size() const noexcept
        {
            return std::numeric_limits<size_type>::max() / sizeof(T);
        }
        void reserve(size_type n) { if (n > capacity()) grow(n); }
        size_type capacity() const { return limit - data; }
        void shrink_to_fit() { limit = avail; }

        /*= = = = = = = = = = = = = = = = = =  = = = = = = = = = = = = = = =*/

        void clear()
        {
            iterator it = avail;
            while (it != data){
                alloc.destroy(--it);
            }
            avail = data;
        }

        iterator insert(iterator position, const T& value)
        {
            if (avail == limit) // jei netelpa naujas elementas - didinti vektoriaus talpa
                grow();
            std::move_backward(position, avail, avail + 1); // elementai paslenkami "i desine", pradedant nuo position
            *(position) = value; // iterpiamas elementas i nustatyta vieta
            ++avail; // nes size padidejo vienu elementu

            return position; // grazinamas iteratorius tos atminties vietos, i kuria buvo iterptas elementas
        }

        iterator emplace(iterator position, T&& value)
        {
            if (avail == limit)
                grow();
            for (iterator it = avail; it != position; --it)
                *(it) = *(it - 1);

            alloc.construct(position, std::forward<T>(value)); // sukonstruoti elementa nustatytoje vietoje
            ++avail;

            return position;

        }

        iterator erase(iterator pos)
        {
            if (pos >= avail)
                return pos; // klaidingo iteratoriaus atveju tiesiog grazinamas pats iteratorius

            std::move(pos + 1, avail, pos); // elementai paslenkami "i kaire", perrasant istrintus elementus

            alloc.destroy(--avail);
            return pos + 1; // Iterator pointing to the next element
        }

        iterator erase(iterator first, iterator last)
        {
            if (first >= last)
                return last; // klaidingo iteratoriaus atveju tiesiog grazinamas pats iteratorius

            iterator new_end = std::move(last, avail, first);

            while (avail != new_end) // pasalinami like elementai
                alloc.destroy(--avail);

            return new_end; // grazinamas iteratorius, rodantis i nauja vektoriaus pabaiga
        }

        template<class... Args> void emplace_back(Args&&... args)
        {
            if (avail == limit)
                grow();
            alloc.construct(avail++, std::forward<Args>(args)...); // elementai sukonstruojami vektoriaus pabaigoje
        }

        void pop_back()
        {
            if (avail == data)
                throw std::out_of_range("Vector::pop_back()");
            --avail;
            alloc.destroy(avail); // sunaikinamas paskutinis elementas
        }


        void push_back(const T& val)  // push_back() realizacija
        {
            if (avail == limit)
                grow();
            unchecked_append(val);
        }

        void push_back(T&& val)  // push_back() su rvalue
        {
            if (avail == limit)
                grow();
            unchecked_append(std::move(val));
        }

        void resize(size_type n, const T& value = T{})
        {
            if (n < size()) {
                while (avail != data + n)
                    alloc.destroy(--avail); // sunaikinami uz nauju ribu esantys elementai
            }
            else if (n > size()) {
                if (n > capacity())
                    grow(n);
                while (avail != data + n)
                    alloc.construct(avail++, value);
            }
        }

        void swap(Vector<T>& other)
        {
            std::swap(data, other.data);
            std::swap(avail, other.avail);
            std::swap(limit, other.limit);
        }


    private:
        iterator data;
        iterator avail;
        iterator limit;

        std::allocator<T> alloc; // objektas atminties valdymui
        // išskirti atmintį (array) ir ją inicializuoti
        void create();
        void create(size_t, const T&);
        void create(const_iterator, const_iterator);
        void create(iterator, iterator);

        // sunaikinti elementus array ir atlaisvinti atmintį
        void uncreate();
        // pagalbinės funkcijos push_back realizacijai
        void grow();
        void grow(int);
        void unchecked_append(const T&);


};

template <class T> void Vector<T>::create()
{
    data = avail = limit = nullptr;
}

template <class T> void Vector<T>::create(size_t n, const T& val)
{
    data = alloc.allocate(n); // grąžina ptr į array pirmą elementą
    limit = avail = data + n; // sustato rodykles į vietas
    std::uninitialized_fill(data, limit, val); // inicializuoja elementus val reikšme
}

template <class T> void Vector<T>::create(const_iterator i, const_iterator j)
{
    size_type size = std::distance(i, j);
    data = alloc.allocate(size);  // išskirti vietos elementams
    limit = avail = std::uninitialized_copy(i, j, data); // nukopijuoja elementus iš intervalo
}

template <class T> void Vector<T>::create(iterator i, iterator j)
{
    size_type size = std::distance(i, j);
    data = alloc.allocate(size);  // išskirti vietos elementams
    limit = avail = std::uninitialized_copy(i, j, data); // nukopijuoja elementus iš intervalo
}

template <class T> void Vector<T>::uncreate()
{
    if (data) {
        iterator it = avail; // sunaikinti (atbuline tvarka) sukonstruotus elementus
        while (it != data)
            alloc.destroy(--it);
        alloc.deallocate(data, limit - data); // atlaisvinti išskirtą atmintį. Turi būti data != nullptr
    }
    data = limit = avail = nullptr; // reset pointerius - Vector'ius tuščias
}

template <class T> void Vector<T>::grow()
{
    size_type new_size = std::max(10*(limit - data), ptrdiff_t(1)); // dvigubai daugiau vietos, nei buvo
    iterator new_data = alloc.allocate(new_size); // išskirti naują vietą
    iterator new_avail = std::uninitialized_copy(data, avail, new_data); //  ir perkopijuoti egzistuojančius elementus
    uncreate();  // atlaisvinti seną vietą
    data = new_data;  // reset'int rodykles į naujai išskirtą vietą
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vector<T>::grow(int n)
{
    size_type new_size = n;
    iterator new_data = alloc.allocate(new_size); // išskirti naują vietą
    iterator new_avail = std::uninitialized_copy(data, avail, new_data); //  ir perkopijuoti egzistuojančius elementus
    uncreate();  // atlaisvinti seną vietą
    data = new_data;  // reset'int rodykles į naujai išskirtą vietą
    avail = new_avail;
    limit = data + new_size;
}

template <class T> void Vector<T>::unchecked_append(const T& val)
{
    alloc.construct(avail++, val);
}

#endif // MYVECTOR_H
