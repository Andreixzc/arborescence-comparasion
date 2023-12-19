
#include <cassert>
#include <utility>
#include <set>

#include <arbok/tarjan/tarjan_base.h>

namespace arbok {

class TarjanSet : public Tarjan<TarjanSet> {
    std::vector<std::set<std::pair<int,int>>> managedSets; // (weight, idx)
    std::vector<int> offsets;

public:
    TarjanSet(int n, int m) : Tarjan<TarjanSet>(n,m), managedSets(n), offsets(n,0) { }

    void create_edge_internal(int /* from */, int to, int weight, int idx) {
        managedSets[to].emplace(weight,idx);
    }

    std::pair<int,int> get_min_edge(int v) {
        assert(size(managedSets[v]));
        while(co.find(edges[managedSets[v].begin()->second].from) == v)
            managedSets[v].erase(managedSets[v].begin()); // delete selfloops
        auto res = *managedSets[v].begin();
        managedSets[v].erase(managedSets[v].begin()); // extract the edge that is returned
        res.first -= offsets[v];
        return res;
    }

    void update_incoming_edge_weights(int v, int w) {
        offsets[v] += w;
    }

    void move_edges(int from, int to) {
        // make sure set of from is smaller than to
        auto& small = managedSets[from];
        auto& large = managedSets[to];
        if(size(small)>size(large)) {
            swap(small, large);
            std::swap(offsets[from], offsets[to]);
        }

        // smaller into larger while applying offset
        while(size(small)) {
            auto e = small.extract(begin(small));
            e.value().first -= offsets[from] - offsets[to];
            large.insert(move(e));
        }
    }
};

}
