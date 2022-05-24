#pragma once
#include <string>
#include <list>
#include <map>
#include <memory>

// For the tests
#include <vector>
#include <iostream>

#include "LevelOrderChartIterator.hpp"
#include "ReverseOrderChartIterator.hpp"
#include "PreorderChartIterator.hpp"

namespace ariel
{
    struct OrgNode // Node in a tree 
    {
        std::string name;
        int id;
        int level;
        std::list<std::shared_ptr<OrgNode>> childs;

        OrgNode(const std::string & _name,int _id, int _level){
            name = _name;
            id = _id;
            level = _level;
        }

        friend std::ostream& operator<<(std::ostream&,const OrgNode&);
    };

    class OrgChart
    {
    public:
        OrgChart();
        OrgChart(const OrgChart&) = default;
        OrgChart(OrgChart&&) = default;
        ~OrgChart() = default;

        OrgChart& add_root(const std::string&);
        OrgChart& add_sub(const std::string& ,const  std::string&);

        friend std::ostream& operator<<(std::ostream&,const OrgChart&);
        OrgChart& operator= ( const OrgChart& ) = default; 	
        OrgChart& operator= ( OrgChart&& ) = default; 	

        LevelOrderChartIterator begin();
        LevelOrderChartIterator end();
        LevelOrderChartIterator begin_level_order();
        LevelOrderChartIterator end_level_order();
        ReverseOrderChartIterator begin_reverse_order();
        ReverseOrderChartIterator reverse_order();
        PreorderChartIterator begin_preorder();
        PreorderChartIterator end_preorder();
    private:
        using OrgNodeRef = std::shared_ptr<OrgNode>; // same as typedef
        OrgNodeRef root;

        int currentID;
    };
} // namespace ariel