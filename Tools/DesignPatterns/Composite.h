#include <vector>
#include <algorithm>
#include <stdexcept>
#include <functional>

template<typename ChildCompositeType> //Just allows to create different types of composites that will not mix together
class Composite
{
public:
    Composite(Composite* parent = nullptr) : m_parent(nullptr)
    {
        setParent(parent);
    }

    virtual ~Composite()
    {
        setParent(nullptr);

        auto sonsCpy = m_sons;
        for (auto& son : sonsCpy)
            delete son;
    }

    void setParent(Composite* newParent)
    {
        if (m_parent)
            m_parent->_remove(this);

        m_parent = newParent;

        if (m_parent)
            m_parent->_add(this);
    }

    void add(Composite* newChild)
    {
        newChild->setParent(this);
    }

    using ChildrenListType = std::vector<Composite*>;
    const ChildrenListType& getChildren()
    {
        return m_sons;
    }

    using TraverseCallbackType = std::function<void(const Composite*)>;
    void traverse(TraverseCallbackType fn)
    {
        for (auto& son : m_sons)
            son->traverse(fn);

        fn(this);
    }

protected:
    void _add(Composite* newChild)
    {
        m_sons.push_back(newChild);
    }

    void _remove(Composite* child)
    {
        auto it = std::find(m_sons.begin(), m_sons.end(), child);
        if (it == m_sons.end())
            throw std::runtime_error("Son could not be found.");

        m_sons.erase(it);
    }

private:
    ChildrenListType m_sons;
    Composite* m_parent;
};
