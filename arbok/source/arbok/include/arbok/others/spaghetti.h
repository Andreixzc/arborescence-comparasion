#pragma once

#include <vector>
#include <algorithm>
#include <limits>

namespace SpaghettiDS {
    struct edge {
        int src, dst;
        int weight;
    };
} // end namespace

namespace arbok {
    class Spaghetti {
        int n;
        std::vector<SpaghettiDS::edge> edges;

    public:
        Spaghetti(int _n, int /* _m */) : n(_n) {}

        void create_edge(int src, int dst, int weight) {
            edges.push_back({src, dst, weight});
        }

        long long run(int root) {
            const int INF = std::numeric_limits<int>::max();
            int N = n;
            int r = root;

            for (long long res = 0;;) {
                std::vector<SpaghettiDS::edge> in(N, {-1, -1, INF});
                std::vector<int> C(N, -1);

                for (const auto& e : edges) {
                    if (in[e.dst].weight > e.weight)
                        in[e.dst] = e;
                }
                in[r] = {r, r, 0};

                for (int u = 0; u < N; ++u) {
                    if (in[u].src < 0)
                        return -1;
                    res += in[u].weight;
                }

                std::vector<int> mark(N, -1);
                int index = 0;

                for (int i = 0; i < N; ++i) {
                    if (mark[i] != -1)
                        continue;
                    int u = i;
                    while (mark[u] == -1) {
                        mark[u] = i;
                        u = in[u].src;
                    }
                    if (mark[u] != i || u == r)
                        continue;
                    for (int v = in[u].src; u != v; v = in[v].src)
                        C[v] = index;
                    C[u] = index++;
                }

                if (index == 0)
                    return res;

                for (int i = 0; i < N; ++i)
                    if (C[i] == -1)
                        C[i] = index++;

                std::vector<SpaghettiDS::edge> next;
                for (const auto& e : edges)
                    if (C[e.src] != C[e.dst] && C[e.dst] != C[r])
                        next.push_back({C[e.src], C[e.dst], e.weight - in[e.dst].weight});
                edges.swap(next);
                N = index;
                r = C[r];
            }
        }

        std::vector<int> reconstruct(int /* root */) {
            return {}; // TODO
        }
    };
} // end arbok
