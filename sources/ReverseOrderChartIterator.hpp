#pragma once
#include <stack>
#include <memory>
namespace ariel
{
    class OrgNode;
    class ReverseOrderChartIterator
    {
    private:
        using OrgNodeRef = std::shared_ptr<OrgNode>;
        std::stack<OrgNodeRef> stack;
    public:
        ReverseOrderChartIterator(OrgNodeRef);
        ~ReverseOrderChartIterator();

        bool operator == (const ReverseOrderChartIterator&) const ;
        bool operator != (const ReverseOrderChartIterator&) const ;
        ReverseOrderChartIterator& operator ++();
        ReverseOrderChartIterator operator ++(int);

        std::string operator*();
        std::string* operator->();
    };
} // namespace ariel