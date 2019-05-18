/* -*- C++ -*- */
#pragma once
/**
* @file menu.h
* @author Rui Azevedo
* @date 10 May 2019
* @copyright 2019 Rui Azevedo
* @brief ArduinoMenu std::vector based menu
*/

#include <vector>
#include <iostream>
using namespace std;

#include <menu.h>
// using namespace Menu;

// namespace Menu {
  template<typename O=Empty<>>
  struct VectorMenu:public O,vector<Item*> {
    using vector<Item*>::vector;
    inline idx_t size() {return (idx_t)vector<Item*>::size();}
    template<typename Nav,typename Out>
    static inline void print(Nav& bav,Out& out) {}
    template<typename... OO>
    inline VectorMenu(OO... oo):vector<Item*>{oo...} {}
    template<typename Nav,typename Out>
    inline void printItem(Nav& nav,Out& out,idx_t n) {
      operator[](n)->print(nav,out);
    }
    inline bool enabled(idx_t n) const {
      return operator[](n)->enabled(0);
    }
    inline void enable(idx_t n,bool o) {
       operator[](n)->enable(n,o);
    }
    inline Item& getItem(idx_t n) {return *operator[](n);}
  };
// };
