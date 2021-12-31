#ifndef OCP_H
#define OCP_H

#include <string>
#include <vector>

using namespace std;

enum class Color
{
    red,
    blue,
    green
};
enum class Size
{
    small,
    medium,
    large
};

struct Product
{
    string name;
    Color color;
    Size size;
};

struct ProductFilter
{

    typedef vector<Product *> Items;

    Items by_color(const Items &items, const Color &color)
    {
        Items result;

        for (auto &item : items)
        {
            if (item->color == color)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Items by_size(const Items &items, const Size &size)
    {
        Items result;

        for (auto &item : items)
        {
            if (item->size == size)
            {
                result.push_back(item);
            }
        }
        return result;
    }

    Items by_size_and_color(const Items &items, const Color &color, const Size &size)
    {
        Items result;

        for (auto &item : items)
        {
            if (item->size == size && item->size == size)
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

template <typename T>
struct Specification
{

    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0;

    // this breaks OCP if added post-hoc
    /*
    AndSpecification<T> operator&&(Specification<T> &&other)
    {
        return AndSpecification(*this, other);
    }*/
};

template <typename T>
struct Filter
{

    virtual ~Filter() = default;
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{

    virtual vector<Product *> filter(vector<Product *> items, Specification<Product> &spec)
    {
        vector<Product *> result;

        for (auto &item : items)
        {
            if (spec.is_satisfied(item))
            {
                result.push_back(item);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{

    Color color;

    ColorSpecification(Color color) : color(color)
    {
    }

    bool is_satisfied(Product *item) const
    {
        return (item->color == color);
    }
};

struct SizeSpecification : Specification<Product>
{

    Size size;

    SizeSpecification(Size size) : size(size)
    {
    }

    bool is_satisfied(Product *item) const
    {
        return (item->size == size);
    }
};

template <typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T> &first;
    const Specification<T> &second;

    AndSpecification(const Specification<T> &first, const Specification<T> &second) : first(first), second(second)
    {
    }

    bool is_satisfied(T *item) const
    {
        return (first.is_satisfied(item) && second.is_satisfied(item));
    }
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{

    return {first, second};
}

/* We create a filter for this class -> the single responsability principle is respected. */

/* Here we will apply the open-close principle, open to extension & close to modification */

// Filter one by color, good & workable solution.
/*Starting to be problematic because we are coming back into an already done solution and we are mofifying it which is not ideal.*/

/* The color specification do the same work but the technique used is way more flexible and extensible for other products. */

#endif