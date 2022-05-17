#include "ReverseOrderChartIterator.hpp"
#include "OrgChart.hpp"
#include <queue>
#include <algorithm>
namespace ariel
{
    ReverseOrderChartIterator::ReverseOrderChartIterator(OrgNodeRef head)
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

                if(node.get()->level != last_level)
                {
                    while (!level_stack.empty())
                    {
                        stack.push(level_stack.top());
                        level_stack.pop();
                        last_level  = node.get()->level;
                    }
                    
                }

                for(OrgNodeRef& child : node.get()->childs)
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

    ReverseOrderChartIterator::~ReverseOrderChartIterator()
    {

    }

    bool ReverseOrderChartIterator::operator == (const ReverseOrderChartIterator& Other) const 
    {
        if(!stack.empty() && !Other.stack.empty())
        {
            return stack.top().get()->id == Other.stack.top().get()->id;
        }
        else if(stack.empty() && Other.stack.empty())
        {
            return true;
        }
        return false;
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
        ReverseOrderChartIterator it = *this;
        stack.pop();
        return it;
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