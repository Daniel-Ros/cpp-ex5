#pragma once
#include <queue>
#include <memory>
#include <map>
namespace ariel
{
    class OrgNode;
    class LevelOrderChartIterator
    {
    private:
        using OrgNodeRef = std::shared_ptr<OrgNode>;
        std::queue<OrgNodeRef> queue;
    public:
        LevelOrderChartIterator(const OrgNodeRef&);
        LevelOrderChartIterator(LevelOrderChartIterator&);
        LevelOrderChartIterator(LevelOrderChartIterator&&) = default;
        ~LevelOrderChartIterator();

        LevelOrderChartIterator& operator= ( const LevelOrderChartIterator& ) = default; 	
        LevelOrderChartIterator& operator= ( LevelOrderChartIterator&& )= default; 	

        bool operator == (const LevelOrderChartIterator&) const ;
        bool operator != (const LevelOrderChartIterator&) const ;
        LevelOrderChartIterator& operator ++();
        LevelOrderChartIterator operator ++(int);

        std::string operator*();
        std::string* operator->();
    };
} // namespace ariel