#include<string>
#include <iostream>
#include <stack>

namespace ariel{
    // template<typename T>
    class OrgChart{
    private:
        std::string* node;
        struct Node{
            std::string data;

        };
        
    public:
        OrgChart(/* args */);
        ~OrgChart(){};
        OrgChart& add_root(std::string str); 
        OrgChart& add_sub(std::string str1, std::string str2); 
        friend std::ostream& operator<<(std::ostream& os, const OrgChart& other);
        class level_order_iter{
            private:
            //stack<Node*>iter;
            public:
            level_order_iter();
            ~level_order_iter(){};
            bool operator!=(const level_order_iter& other) const;
            bool operator==(const level_order_iter& other) const;
            level_order_iter& operator++();
            level_order_iter& operator*(level_order_iter& other) const;
            //int size();
        };
        class reverse_order_iter{
            private:
            public:
            reverse_order_iter();
            ~reverse_order_iter(){};
            bool operator!=(const reverse_order_iter& other) const;
            bool operator==(const reverse_order_iter& other) const;
            reverse_order_iter& operator++();
            reverse_order_iter& operator*(reverse_order_iter& other) const;

        };
        class preorder_iter{
            private:
            public:
            preorder_iter();
            ~preorder_iter(){};
            bool operator!=(const preorder_iter& other) const;
            bool operator==(const preorder_iter& other) const;
            preorder_iter& operator++();
            preorder_iter& operator*(preorder_iter& other) const;
        };

        std::string* begin_level_order();
        std::string* end_level_order();
        std::string* begin_reverse_order();
        std::string* reverse_order();
        std::string* begin_preorder();
        std::string* end_preorder();
        int* begin();
        int* end();
    };
    
};