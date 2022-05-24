#pragma once
#include <queue>
#include <memory>
namespace ariel
{
    class OrgNode;
    class PreorderChartIterator
    {
    private:
        using OrgNodeRef = std::shared_ptr<OrgNode>;
        std::queue<OrgNodeRef> queue;
        void createSearchTree(const OrgNodeRef&);
    public:
        PreorderChartIterator(const OrgNodeRef&);
        PreorderChartIterator(const PreorderChartIterator&);
        PreorderChartIterator( PreorderChartIterator&&) = default;
        ~PreorderChartIterator() = default;

        PreorderChartIterator& operator= ( const PreorderChartIterator& ) = default; 	
        PreorderChartIterator& operator= ( PreorderChartIterator&& ) = default; 	

        bool operator == (const PreorderChartIterator&) const ;
        bool operator != (const PreorderChartIterator&) const ;
        PreorderChartIterator& operator ++();
        PreorderChartIterator operator ++(int);

        std::string operator*();
        std::string* operator->();
    };
} // namespace ARIEL