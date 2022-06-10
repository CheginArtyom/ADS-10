// Copyright 2022 NNTU-CS
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

std::vector<char> getPerm(const Tree& tree, int n) {
  std::string perm_string = tree[n - 1];
  std::vector<char> permisdone;
  for (int i = 0; i < perm_string.length(); i++) {
    permisdone.push_back(perm_string[i]);
  }
  return permisdone;
}

struct Tree::vetka {
  char nvalue;
  std::vector<vetka*> child;
};

void Tree::per(vetka* rod, std::string sym = "") {
  if (!rod->child.size()) {
    sym += rod->nvalue;
    r.push_back(sym);
  }
  if (rod->nvalue != '*') {
    sym += rod->nvalue;
  }
  for (int i = 0; i < rod->child.size(); i++) {
    per(rod->child[i], sym);
  }
}

void Tree::cTree(vetka* rod, std::vector<char> t) {
  if (!t.size()) {
    return;
  }
  if (rod->nvalue != '*') {
    for (auto i = t.begin(); i < t.end(); i++) {
      if (*i == rod->nvalue) {
        t.erase(i);
        break;
      }
    }
  }
  for (int i = 0; i < t.size(); i++) {
    rod->child.push_back(new vetka);
  }
  for (int i = 0; i < rod->child.size(); i++) {
    rod->child[i]->nvalue = t[i];
  }
  for (int i = 0; i < rod->child.size(); i++) {
    cTree(rod->child[i], t);
  }
}

Tree::Tree(const std::vector<char> val) {
  rod = new vetka();
  rod->nvalue = '*';
  cTree(rod, val);
  per(rod);
}

std::string Tree::op[] (unsigned int i) const {
  if (i >= r.size()) {
    return "";
  }
  if (i < 0) {
    throw std::string("Wrong index!");
  }
  return r[i];
}
