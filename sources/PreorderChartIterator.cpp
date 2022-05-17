#include <stack>

#include "PreorderChartIterator.hpp"
#include "OrgChart.hpp"

namespace ariel
{
    PreorderChartIterator::PreorderChartIterator(OrgNodeRef head)
    {
        if(head != nullptr)
        {
           createSearchTree(head);
        }
    }

    PreorderChartIterator::~PreorderChartIterator()
    {

    }

    void PreorderChartIterator::createSearchTree(OrgNodeRef head)
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
            return queue.front().get()->id == Other.queue.front().get()->id;
        }
        else if(queue.empty() && Other.queue.empty())
        {
            return true;
        }
        return false;
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
        PreorderChartIterator it = *this;
        queue.pop();
        return it;
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