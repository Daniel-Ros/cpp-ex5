#include "LevelOrderChartIterator.hpp"
#include "OrgChart.hpp"
namespace ariel
{
    LevelOrderChartIterator::LevelOrderChartIterator(OrgNodeRef head)
    {
        if(head != nullptr)
        {
            std::queue<OrgNodeRef> tmp_queue;
            tmp_queue.push(head);
            queue.push(head);
            while(!tmp_queue.empty())
            {
                auto & node = tmp_queue.front();
                for(OrgNodeRef& child : node.get()->childs)
                {
                    tmp_queue.push(child);
                    queue.push(child);
                }
                tmp_queue.pop();
            }
        }
    }

    LevelOrderChartIterator::~LevelOrderChartIterator()
    {

    }

    bool LevelOrderChartIterator::operator == (const LevelOrderChartIterator& Other) const 
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

    bool LevelOrderChartIterator::operator != (const LevelOrderChartIterator& Other) const
    {

        return !(*this == Other);
    }

    LevelOrderChartIterator& LevelOrderChartIterator::operator ++()
    {
        queue.pop();
        return *this;
    }

    LevelOrderChartIterator LevelOrderChartIterator::operator ++(int)
    {
        LevelOrderChartIterator it = *this;
        queue.pop();
        return it;
    }

    std::string LevelOrderChartIterator::operator*()
    {
        if(queue.empty())
        {
            return ""; 
        }
        return ((queue.front().get()))->name;
    }

    std::string* LevelOrderChartIterator::operator->()
    {
        if(queue.empty())
        {
            return nullptr; 
        }
        return &(queue.front().get()->name);
    }


} // namespace name