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
        void createSearchTree(OrgNodeRef);
    public:
        PreorderChartIterator(OrgNodeRef);
        ~PreorderChartIterator();

        bool operator == (const PreorderChartIterator&) const ;
        bool operator != (const PreorderChartIterator&) const ;
        PreorderChartIterator& operator ++();
        PreorderChartIterator operator ++(int);

        std::string operator*();
        std::string* operator->();
    };
} // namespace ARIEL