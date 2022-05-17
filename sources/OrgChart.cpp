#include "OrgChart.hpp"
#include <queue>


namespace ariel
{

    std::ostream& operator<<(std::ostream& stream,const OrgNode& node)
    {
        stream << node.name;
        return stream;
    }

    std::ostream& operator<<(std::ostream& stream,const OrgChart& node)
    {
        stream << node.root.get()->name;
        return stream;
    }

    OrgChart::OrgChart() : currentID{0}
    {

    }

    OrgChart::~OrgChart()
    {

    }

    OrgChart& OrgChart::add_root(const std::string& role)
    {
        if(root.get() == nullptr)
        {   
            root = std::make_shared<OrgNode>(role,currentID++,0);
        }
        else
        {
            root.get()->name =  role;
        }
        return *this;
    }

    OrgChart& OrgChart::add_sub(const std::string& super,const  std::string& role)
    {
        if(root == nullptr)
        {
            throw std::runtime_error("Not root found");
        }
        std::queue<OrgNodeRef> queue;
        queue.push(root);
        while(!queue.empty())
        {
            auto & node = queue.front();
            if(node.get()->name == super)
            {
                node.get()->childs.push_back(std::make_shared<OrgNode>(role,currentID++,node.get()->level + 1));
                return *this;
            }
            for(OrgNodeRef& child : node.get()->childs)
            {
                queue.push(child);
            }
            queue.pop();
        }
        throw std::runtime_error("Superviser role does not exists");
        return *this;
    }

    LevelOrderChartIterator OrgChart::begin_level_order()
    {
        return LevelOrderChartIterator(root);
    }

    LevelOrderChartIterator OrgChart::end_level_order()
    {
        return LevelOrderChartIterator(nullptr);
    }

    ReverseOrderChartIterator OrgChart::begin_reverse_order()
    {
        return ReverseOrderChartIterator(root);
    }
    ReverseOrderChartIterator OrgChart::reverse_order()
    {
        return ReverseOrderChartIterator(nullptr);
    }

    PreorderChartIterator OrgChart::begin_preorder()
    {
        return PreorderChartIterator(root);
    }

    PreorderChartIterator OrgChart::end_preorder()
    {
        return PreorderChartIterator(nullptr);
    }

    LevelOrderChartIterator OrgChart::begin()
    {
        return LevelOrderChartIterator(root);
    }

    LevelOrderChartIterator OrgChart::end()
    {
        return LevelOrderChartIterator(nullptr);
    }


} // namespace ariel