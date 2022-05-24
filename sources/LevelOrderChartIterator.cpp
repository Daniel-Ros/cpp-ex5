#include "LevelOrderChartIterator.hpp"
#include "OrgChart.hpp"
namespace ariel
{
    LevelOrderChartIterator::LevelOrderChartIterator(const OrgNodeRef& head)
    {
        if(head != nullptr)
        {
            std::queue<OrgNodeRef> tmp_queue;
            tmp_queue.push(head);
            queue.push(head);
            while(!tmp_queue.empty())
            {
                auto & node = tmp_queue.front();
                for(OrgNodeRef& child : node->childs)
                {
                    tmp_queue.push(child);
                    queue.push(child);
                }
                tmp_queue.pop();
            }
        }
    }

    LevelOrderChartIterator::LevelOrderChartIterator(LevelOrderChartIterator& lvlIter)
    {
        queue = lvlIter.queue;
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
        // Not allowed to use else if because of TIDY! what a yoke
        return queue.empty() && Other.queue.empty();
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
        LevelOrderChartIterator iter = *this;
        queue.pop();
        return iter;
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