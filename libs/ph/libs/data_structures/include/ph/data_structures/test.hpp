#pragma once
#include <ph/testing/testing.hpp>
#include <ph/data_structures/data_structures.hpp>
#include <ph/utility/utility.hpp>
#include <ph/data_structures/stack.hpp>
#include <ph/data_structures/queue.hpp>
#include <ph/data_structures/linked_list.hpp>
#include <random>
using namespace ph::utility;

namespace ph::data_structures
{

struct Testing : ph::testing::Testing
{
private:
      void stack ()
      {
            cout << "stack:" << endl;
            Stack<int, 10> s1;
            cout << "\t" << s1 << endl;
            s1.push(2);
            cout << "\t" << s1 << endl;
            s1.push(3);
            cout << "\t" << s1 << endl;
            s1.pop();
            cout << "\t" <<  s1 << endl << endl;
      }
      
      void queue ()
      {
            Queue<int, 10> q1;
            q1.enqueue(1);
            cout << "\t" << q1 << endl;
            q1.enqueue(2);
            cout << "\t" << q1 << endl;
            q1.dequeue();
            cout << "\t" << q1 << endl << endl;
      }
      
      void linked_list()
      {
            Linked_list<int> l1;
            cout << "\t" << l1 << endl;
            l1.insert(1);
            cout << "\t" << l1 << endl;
            l1.insert(2);
            cout << "\t" << l1 << endl;
            l1.insert(3);
            cout << "\t" << l1 << endl;
      }
      
public:
      virtual void run () override
      {
            stack();
            queue();
            linked_list();
      }
      
      
      
      
      

      
      
};




}

int random (int f, int l)
{
      std::random_device dev;
      std::mt19937 rng(dev());
      std::uniform_int_distribution<std::mt19937::result_type> dist6(f,l); // distribution in range [1, 6]
      
      //      std::cout << dist6(rng) << std::endl;
      return dist6(rng);
}


template <class Data>
Data* heap_maximum (std::vector<Data*>& A) {
      return A.front();
}

template <class Data>
Data* heap_extract_max (std::vector<Data*>& A) {
      assert(A.size() >= 1);
      Data* max = A.front();
      A.front() = A.back();
      A.pop_back();
      max_heapify(A, 1);
      return max;
}

template <class Data>
void heap_increase_key (std::vector<Data*>& A, int i, Data* key) {
      assert(A[i] == nullptr);
      A[i] = key;
      while (i > 0 and *A[i - 1] < *A[i]) {
            swap (A[i], A[i - 1]);
            --i;
      }
}

template <class Data>
void max_heap_insert (std::vector<Data*>& A, Data* key) {
      A.resize(A.size() + 1);
      heap_increase_key<Data> (A, A.size() - 1, key);
}

template <class Data>
Data* heap_minimum (std::vector<Data*>& A) {
      return A.front();
}

template <class Data>
Data* heap_extract_min (std::vector<Data*>& A) {
      assert(A.size() >= 1);
      Data* max = A.front();
      A.front() = A.back();
      A.pop_back();
      min_heapify(A, 1);
      return max;
}

template <class Data>
void heap_decrease_key (std::vector<Data*>& A, int i, Data* key) {
      assert(A[i] == nullptr);
      A[i] = key;
      while (i > 0 and *A[i - 1] > *A[i]) {
            swap (A[i], A[i - 1]);
            --i;
      }
}

template <class Data>
void min_heap_insert (std::vector<Data*>& A, Data* key) {
      A.resize(A.size() + 1);
      heap_decrease_key<Data> (A, A.size() - 1, key);
}



template <class G>
G* a_l_heap_minimum (G** A) {
      return *A;
}

template <class G>
G* a_l_heap_extract_min (G** A) {
      //      assert(A.size() >= 1);
      
      G* max = A[0];
      A = &((*A[0]).next);
      //      A[0]->next = nullptr;
      //      cout << (**A).ant - 2 << endl;
      //      A[(*A)->ant - 2]->next = nullptr;
      //      cout << (**A).ant << endl;
      (**A).ant--;
      //      a_l_min_heapify(A, 1);
      return max;
}

template <class G>
void a_l_heap_decrease_key (G** A, int i, G* key) {
      //      assert(A[i] == nullptr);
      A[i] = key;
      while (i > 0 and *A[i - 1] > *A[i]) {
            swap (A[i], A[i - 1]);
            --i;
      }
}

template <class G>
void a_l_min_heap_insert (G** A, G* key) {
      //      A.resize(A.size() + 1);
      a_l_heap_decrease_key<G> (A, (**A).ant - 1, key);
}



template <class Data, class Key>
struct MinPrioQueueHeap{
      std::vector<Data*> data;
      
      void insert (Data* data) {
            
      }
      Data* maximum () {
            
      }
      
      void increase_key (Data* data, Key* key) {
            
      }
      MinPrioQueueHeap () {
            
      }
      
      
};

template <class G>
void print (G** g) {
      G* i = g[0];
      while (i != nullptr) {
            cout << i->data << " key: ";
            if ( i->key != nullptr ) {
                  cout << *i->key << " ";
            }
            cout << "parent: ";
            if ( i->parent != nullptr ) {
                  cout << i->parent->data << endl;
            }
            cout << endl;
            i = i->next;
      }
}

template <class T, size_t N>
ostream& operator<< (ostream& os, std::array<T*, N> const& t){
      for (int i = 0; i < N; ++i) {
            os << *t[i] << " ";
      }
      return os;
}

template <class T>
ostream& operator<< (ostream& os, std::vector<T*> const& t){
      for (auto const& i : t) {
            os << *i << " ";
      }
      return os;
}




template <class Edge, size_t N = 1000>
struct ListNode{
      
      inline static ListNode* before = nullptr;
      inline static int ant = 0;
      int data;
      std::vector<Edge*> edges;
      ListNode* next;
      int* key;
      ListNode* parent;
      int ind;
      std::mutex tail_lock;
      inline static ListNode* tail = nullptr;
      
      
      
      ListNode (int const& data) : data(data), next (nullptr), key (nullptr), parent(nullptr), ind(ant){
            
            ant++;
            if ( before != nullptr ) {
                  before -> next = this;
            }
            before = this;
            
            std::lock_guard<std::mutex> guard(tail_lock);
            tail = this;
      }
      
      ListNode (pair<int const&, Edge*>&& p ) : data(move(p.first)), next (nullptr), ind(ant), key (nullptr), parent(nullptr), edges{p.second}{
            tail = this;
            ant++;
            if ( before != nullptr ) {
                  before -> next = this;
            }
            if ( p.second != nullptr ) {
                  p.second->node->push(new Edge(p.second->weight, this));
                  before = this;
            }
      }
      
      
      //      ListNode (int const& data, ListNode* p) : data(data), parent(nullptr), next(nullptr), key(nullptr) {
      //            p->next = this;
      //      }
      void push (Edge* edge){
            edges.push_back(edge);
      }
      void push2 (Edge* edge){
            edges.push_back(edge);
            edge->node->push(new Edge(edge->weight, this));
      }
      friend ostream& operator<< (ostream& os, ListNode const& l){
            os << l.data << " : ";
            for (auto const& i : l.edges) {
                  os << *i << " ";
            }
            if ( l.next != nullptr ) {
                  os << endl;
                  os << *l.next;
            }
            return os;
      }
      
};

template <class Edge>
struct Head : public ListNode<Edge>{
      using ListNode<Edge>::ListNode;
      
      ListNode<Edge>* tail;
};

template <class Weight>
struct Edge{
      ListNode<Edge>* node;
      Weight weight;
      Edge (Weight const& weight, ListNode<Edge>* node) : weight(weight), node (node) {
            
      }
      friend ostream& operator<< (ostream& os, Edge const& l){
            os << "[" << l.node->data << ", " << l.weight << "]";
            return os;
      }
};

using Edg = Edge<int>;
using Node = ListNode<Edge<int>>;






template <size_t n>
auto genGraph (int maxWeight) {
      //      std::vector<ListNode<int, Edge<int, int>>*> l;
      int k = 0;
      
      Node* l = new Node[n]{[0 ... n - 1] = k++};
      for (int i = 1; i < 0; ++i) {
            
            for (int j = 0; j < i; ++j) {
                  int r = random(0, 1);
                  if (r == 0) {
                        int q = random(1, maxWeight);
                        l[j].push(new Edg (q, &l[i]));
                        l[i].push(new Edg (q, &l[j]));
                  }
                  
            }
      }
      
      return l;
      
      //      return l;
}


inline static Head<Edge<int>>* QQ = new Head<Edge<int>> (0);
std::mutex Q_mutex;

template <size_t N>
void save_page(int max)
{
      auto a = genGraph<N>(max);
      
      std::lock_guard<std::mutex> guard(Q_mutex);
      QQ->tail -> next = a;
      QQ-> tail = a-> tail;
      
}



void m()
{
      auto Q = genGraph<5000>(10);
      Q->key = new int(0);
      
      
      Node* q = Q;
      
      
      while (q != nullptr) {
            auto u = q;
            
            
            
            for (auto i : u->edges) {
                  if ( [&]{
                        for (auto j = q->next; j != nullptr; j = j -> next) {
                              if ( i->node == j ) {
                                    return true;
                              }
                        }
                        return false;
                  }() and (i->node->key == nullptr or i->weight < *i->node->key) ) {
                        i->node->parent = u;
                        i->node->key = new int(i->weight);
                  }
            }
            q = q->next;
      }
}
