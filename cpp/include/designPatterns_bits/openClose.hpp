#include <string>
#include <vector>

using namespace std;

enum class Color
{
    red,
    green,
    blue
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
        for (auto &i : items)
        {
            if (i->color == color)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    Items by_size(const Items &items, const Size &size)
    {
        Items result;
        for (auto &i : items)
        {
            if (i->size == size)
            {
                result.push_back(i);
            }
        }
        return result;
    }

    Items by_size_and_color(const Items &items, const Color &color, const Size &size)
    {
        Items result;
        for (auto &i : items)
        {
            if (i->size == size && i->color == color)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};

template <typename T>
struct AndSpecification;

template <typename T>
struct Specification
{
    virtual ~Specification() = default;
    virtual bool is_satisfied(T *item) const = 0;

    // If we add it post-hoc we break OCP
    /*AndSpecification<T> operator&&(Specification<T> &&other)
    {
        return AndSpecification<T>(*this, other);
    }*/
};

template <typename T>
AndSpecification<T> operator&&(const Specification<T> &first, const Specification<T> &second)
{
    return {first, second};
}

template <typename T>
struct Filter
{
    virtual vector<T *> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product *> filter(vector<Product *> items, Specification<Product> &spec) override
    {
        vector<Product *> result;

        for (auto &p : items)
        {
            if (spec.is_satisfied(p))
            {
                result.push_back(p);
            }
        }
        return result;
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;
    ColorSpecification(Color color) : color{color}
    {
    }

    bool is_satisfied(Product *item) const
    {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{

    Size size;
    SizeSpecification(Size size) : size{size}
    {
    }

    bool is_satisfied(Product *item) const
    {
        return item->size == size;
    }
};

template <typename T>
struct AndSpecification : Specification<T>
{
    const Specification<T> &first;
    const Specification<T> &second;

    AndSpecification(const Specification<T> &first, const Specification<T> &second) : first{first}, second{second}
    {
    }

    bool is_satisfied(T *item) const override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};

/* We create a filter for this class -> the single responsability principle is respected. */

/* Here we will apply the open-close principle, open to extension & close to modification */

// Filter one by color, good & workable solution.
/*Starting to be problematic because we are coming back into an already done solution and we are mofifying it which is not ideal.*/

/* The color specification do the same work but the technique used is way more flexible and extensible for other products. */