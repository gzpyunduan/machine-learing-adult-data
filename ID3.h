#ifndef _ID3
#define _ID3

#include <utility>
#include <iostream>
#include <list>
#include <cassert>
#include <cmath>
#include <map>
#include "adult.h"

#define Map1 std::map<int, int>
#define Map2 std::map<int, Map1>
#define Map3 std::map<int, Map2>
#define Pair std::pair<int, int>
#define List std::list<Pair>
#define SampleSpace std::list<List>
#define Child std::map<int, Node*>
#define CI const_iterator

struct Node{
  int index;
  int type;
  Child next;
  SampleSpace sample;
};

class ID3{

public:

  ID3(int dimension){
    this->dimension = dimension;
    root = new Node();
    root->index = -1;
    root->type = -1;
    root->next.clear();
    root->sample.clear();
  }
  ~ID3(){
    this->dimension = 0;
    clear(root);
  }

  void push(const adult &adu){
    List single;
    single.clear();
    for (int i = 0; i < dimension; i++)
      single.push_back(make_pair(i + 1, adu.attr[i]));
    single.push_back(make_pair(0, adu.attr[dimension]));
    root->sample.push_back(single);
  }

  void build(){
    Build(root, dimension);
  }

  int match(const adult &adu){
    return Match(adu, root);
  }

  void print(){
    Print(root);
  }

private:

  void clear(Node *node){
    Child &next = node->next;
    Child::iterator it;
    for (it = next.begin(); it != next.end(); it++)
      clear(it->second);
    next.clear();
    delete node;
  }

  void Build(Node *node, int dimension){
    SampleSpace &sample = node->sample;

    int y = same_class(sample);

    if (y >= 0){
      node->index = -1;
      node->type = y;
      return;
    }

    work(node);

    sample.clear();

    Child &next = node->next;
    for (Child::iterator it = next.begin(); it != next.end(); it++)
      Build(it->second, dimension - 1);
  }

  int same_class(const SampleSpace &ss){
    const List &f = ss.front();

    if (f.size() == 1)
      return f.front().second;

    int y = 0;
    for (List::CI it = f.begin(); it != f.end(); it++){
      if (!it->first){
        y = it->second;
        break;
      }
    }
    //cout << ss.size() << endl;
    for (SampleSpace::CI it = ss.begin(); it != ss.end(); it++){
      const List &single = *it;
      //cout << 1 << endl;
      for(List::CI i = single.begin(); i != single.end(); i++)
      {
        if(!i->first)
        {
          if(y != i->second)
            return -1;
          else
            break;
        }
      }
    }
    return y;
  }

  void work(Node *node){
    int mai = get_max_gain(node->sample);
    assert(mai >= 0);
    node->index = mai;
    split(node, mai);
  }

  int get_max_gain(const SampleSpace &ss){
    Map1 y;
    Map2 x;
    Map3 xy;

    get_data(ss, y, x, xy);
    double s = ss.size();
    double entropy = Entropy(y, s);

    int mai = -1;
    double mag = -1;

    for (Map2::iterator it = x.begin(); it != x.end(); it++){
      double g = info_gain(it->second, xy[it->first], s, entropy);
      if (g > mag){
        mag = g;
        mai = it->first;
      }
    }

    if (!x.size() && !xy.size() && y.size())
      return 0;
    return mai;
  }

  void get_data(const SampleSpace &ss, Map1 &y, Map2 &x, Map3 &xy){
    for (SampleSpace::CI it = ss.begin(); it != ss.end(); it++){
      int c = 0;
      const List &v = *it;
      for (List::CI p = v.begin(); p != v.end(); p++){
        if (!p->first){
          c = p->second;
          break;
        }
      }
      ++y[c];
      for (List::CI p = v.begin(); p != v.end(); p++){
        if (p->first){
          ++x[p->first][p->second];
          ++xy[p->first][p->second][c];
        }
      }
    }
  }

  double Entropy(const Map1 &x, double s){
    double ans = 0;
    for (Map1::CI it = x.begin(); it != x.end(); it++){
      double t = it->second / s;
      ans += t * log2(t);
    }
    return -ans;
  }

  double info_gain(Map1 &att_val, Map2 &val_cls, double s, double entropy){
    double gain = entropy;
    for (Map1::CI it = att_val.begin(); it != att_val.end(); it++){
      double r = it->second / s;
      double e = Entropy(val_cls[it->first], it->second);
      gain -= r * e;
    }
    return gain;
  }

  void split(Node *node, int idx){
    Child &next = node->next;
    SampleSpace &sample = node->sample;

    for (SampleSpace::iterator it = sample.begin(); it != sample.end(); it++){
      List &v = *it;
      for (List::iterator p = v.begin(); p != v.end(); p++){
        if (p->first == idx){
          Node *tmp = next[p->second];
          if (!tmp){
            tmp = new Node();
            tmp->index = -1;
            tmp->type = -1;
            next[p->second] = tmp;
          }
          v.erase(p);
          tmp->sample.push_back(v);
          break;
        }
      }
    }
  }

  int Match(const adult &adu, Node *node){
    if (node->index < 0)
      return node->type;

    Child &next = node->next;
    Child::iterator p = next.find(adu.attr[node->index - 1]);
    if (p == next.end())
      return -1;

    return Match(adu, p->second);
  }

  void Print(Node *node){
    cout << "Index    = " << node->index << endl;
    cout << "Type     = " << node->type << endl;
    cout << "NextSize = " << node->next.size() << endl;
    cout << "SampleSize = " << node->sample.size() << endl;
    cout << endl;

    Child &next = node->next;
    Child::iterator p;
    for(p = next.begin(); p != next.end(); ++p)
        Print(p->second);
  }

private:
  int dimension;
  Node *root;

};

#endif
