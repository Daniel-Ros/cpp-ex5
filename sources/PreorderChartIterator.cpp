#include <stack>

#include "PreorderChartIterator.hpp"
#include "OrgChart.hpp"

namespace ariel
{
    PreorderChartIterator::PreorderChartIterator(const OrgNodeRef& head)
    {
        if(head != nullptr)
        {
           createSearchTree(head);
        }
    }

    PreorderChartIterator::PreorderChartIterator(const PreorderChartIterator& iter)
    {
        queue = iter.queue;
    }
    
    void PreorderChartIterator::createSearchTree(const OrgNodeRef& head)
    {
        queue.push(head);
        for(OrgNodeRef& child : head.get()->childs)
        {
            createSearchTree(child);
        }
    }

    bool PreorderChartIterator::operator == (const PreorderChartIterator& Other) const 
    {
        if(!queue.empty() && !Other.queue.empty())
        {
            return queue.front()->id == Other.queue.front()->id;
        }
        return queue.empty() && Other.queue.empty();

    }

    bool PreorderChartIterator::operator != (const PreorderChartIterator& Other) const 
    {
        return !(*this == Other);
    }

    PreorderChartIterator& PreorderChartIterator::operator ++()
    {
        queue.pop();
        return *this;
    }

    PreorderChartIterator PreorderChartIterator::operator ++(int)
    {
        PreorderChartIterator iter = *this;
        queue.pop();
        return iter;
    }

    std::string PreorderChartIterator::operator*()
    {
        if(queue.empty())
        {
            return "";
        }
        return (queue.front().get())->name;
    }

    std::string* PreorderChartIterator::operator->()
    {
        if(queue.empty())
        {
            return nullptr; 
        }
        return &(queue.front().get()->name);
    }
} // namespace ariel