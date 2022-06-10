// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <cstdint>
#include <string>
#include <vector>

class Tree {
 private:
    struct vetka;
    std::vector<std::string> r;
    vetka* rod;

    void cTree(vetka* rod, std::vector<char> t);

    void perms(vetka* rod, std::string sym);

 public:
    explicit Tree(const std::vector<char>);

    std::string op[] (unsigned int i) const;
};

#endif  // INCLUDE_TREE_H_
