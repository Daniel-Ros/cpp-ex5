#include "ReverseOrderChartIterator.hpp"
#include "OrgChart.hpp"
#include <queue>
#include <algorithm>
namespace ariel
{
    ReverseOrderChartIterator::ReverseOrderChartIterator(const OrgNodeRef& head)
    {
        if(head != nullptr)
        {
            std::queue<OrgNodeRef> tmp_queue;
            tmp_queue.push(head);

            std::stack<OrgNodeRef> level_stack;

            int last_level = head.get()->level;
            while(!tmp_queue.empty())
            {
                auto & node = tmp_queue.front();

                if(node->level != last_level)
                {
                    while (!level_stack.empty())
                    {
                        stack.push(level_stack.top());
                        level_stack.pop();
                        last_level  = node->level;
                    }
                    
                }

                for(OrgNodeRef& child : node->childs)
                {
                    tmp_queue.push(child);
                }
                level_stack.push(node);
                tmp_queue.pop();
            }

            while (!level_stack.empty()) // flush the last level;
            {
                stack.push(level_stack.top());
                level_stack.pop();
            }
        }
    }

    ReverseOrderChartIterator::ReverseOrderChartIterator(const ReverseOrderChartIterator& iter)
    {
        stack = iter.stack;
    }

    bool ReverseOrderChartIterator::operator == (const ReverseOrderChartIterator& Other) const 
    {
        if(!stack.empty() && !Other.stack.empty())
        {
            return stack.top().get()->id == Other.stack.top().get()->id;
        }
        return stack.empty() && Other.stack.empty();
    }

    bool ReverseOrderChartIterator::operator != (const ReverseOrderChartIterator& Other) const 
    {
        return !(*this == Other);
    }

    ReverseOrderChartIterator& ReverseOrderChartIterator::operator ++()
    {
        stack.pop();
        return *this;
    }

    ReverseOrderChartIterator ReverseOrderChartIterator::operator ++(int)
    {
        ReverseOrderChartIterator iter = *this;
        stack.pop();
        return iter;
    }

    std::string ReverseOrderChartIterator::operator*()
    {
        if(stack.empty())
        {
            return "";
        }
        return (stack.top().get())->name;
    }

    std::string* ReverseOrderChartIterator::operator->()
    {
        if(stack.empty())
        {
            return nullptr; 
        }
        return &(stack.top().get()->name);
    }
} // namespace ariel