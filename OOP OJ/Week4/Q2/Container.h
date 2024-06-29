#include <cstddef>
#include <vector>

template <class type> class Container
{
    public:
        struct Node{
            int x, y;
            type item;
        }
        std::vector<Node> nodes;
        Container()
        {
        }
        ~Container()
        {
            delete nodes;
        }
        void insert(int x, int y, type item)
        {
            Node temp{x, y, item};
            nodes.push_back(temp);
        }
        type* find(int x, int y)
        {
            for(int i = 0; i < nodes.size(); i++)
            {
                if(nodes[i].x == x && nodes[i].y == y)
                    return &nodes[i].item;
            }
            return NULL;
        }

};