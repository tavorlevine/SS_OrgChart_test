#include "OrgChart.hpp"
#include <iostream>

namespace ariel{
    std::string str = "Hello";
    OrgChart::OrgChart(){

    }
    OrgChart& OrgChart::add_root(std::string s){
        return *this;
    }
    OrgChart& OrgChart::add_sub(std::string s1, std::string s2){
        return *this;
    }
    std::ostream& operator<<(std::ostream& os, const OrgChart& org){
        return os;
    }
    OrgChart::level_order_iter::level_order_iter(){

    }
    bool OrgChart::level_order_iter::operator!=(const level_order_iter& other)const {
        return false;
    }
    bool OrgChart::level_order_iter::operator==(const level_order_iter& other)const {
        return false;
    }
    OrgChart::level_order_iter& OrgChart::level_order_iter::operator++(){
        return *this;
    }
    OrgChart::level_order_iter& OrgChart::level_order_iter::operator*(level_order_iter& other)const {
        return other;
    }
    OrgChart::reverse_order_iter::reverse_order_iter(){

    }
    bool OrgChart::reverse_order_iter::operator!=(const reverse_order_iter& other)const {
        return false;
    }
    bool OrgChart::reverse_order_iter::operator==(const reverse_order_iter& other)const {
        return false;
    }
    OrgChart::reverse_order_iter& OrgChart::reverse_order_iter::operator++(){
        return *this;
    }
    OrgChart::reverse_order_iter& OrgChart::reverse_order_iter::operator*(reverse_order_iter& other)const {
        return other;
    }
    OrgChart::preorder_iter::preorder_iter(){

    }
    bool OrgChart::preorder_iter::operator!=(const preorder_iter& other)const {
        return false;
    }
    bool OrgChart::preorder_iter::operator==(const preorder_iter& other)const {
        return false;
    }        
    OrgChart::preorder_iter& OrgChart::preorder_iter::operator++(){
        return *this;
    }
    OrgChart::preorder_iter& OrgChart::preorder_iter::operator*(preorder_iter& other)const {
        return other;
    }
    std::string* OrgChart::begin_level_order(){
        std::string* s = &str; 
        return s;
    }
    std::string* OrgChart::end_level_order(){
        std::string* s = &str; 
        return s;
    }
    std::string* OrgChart::begin_reverse_order(){
        std::string* s = &str; 
        return s;
    }
    std::string* OrgChart::reverse_order(){
        std::string* s = &str; 
        return s;
    }
    std::string* OrgChart::begin_preorder(){
        std::string* s = &str; 
        return s;
    }
    std::string* OrgChart::end_preorder(){
        std::string* s = &str; 
        return s;
    }
    int* OrgChart::begin(){
        int* ans;
        return ans;
    }
    int* OrgChart::end(){
        int* ans;
        return ans;
    }







}