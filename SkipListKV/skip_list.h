
#include<iostream>
#include<string>
#include<set>
#include<time.h>
using namespace std;
template<typename T>
struct Less {
    bool operator () (const T& a, const T& b) const {
        return a < b;
    }
};
template<typename K, typename V, typename Comp = Less<K>>
class skip_list {
private:
    struct skip_list_node {
        int level;
        const K key;
        V value;
        skip_list_node** forward;
        skip_list_node() :key{ 0 }, value{ 0 }, level{ 0 }, forward{ 0 } {}
        skip_list_node(K k, V v, int l, skip_list_node* nxt = nullptr) :key(k), value(v), level(l) {
            forward = new skip_list_node * [level + 1];
            for (int i = 0; i <= level; ++i) forward[i] = nxt;
        }
        ~skip_list_node() { delete[] forward; }
    };
    using node = skip_list_node;
    void init() {
        srand((uint32_t)time(NULL));
        level = length = 0;
        head->forward = new node * [MAXL + 1];
        for (int i = 0; i <= MAXL; i++)
            head->forward[i] = tail;
    }
    int randomLevel() {
        int lv = 1; while ((rand() & S) < PS) ++lv;
        return MAXL > lv ? lv : MAXL;
    }
    int level;
    int length;
    static const int MAXL = 32;
    static const int P = 4;
    static const int S = 0xFFFF;
    static const int PS = S / P;
    static const int INVALID = INT_MAX;
    node* head, * tail;
    Comp less;
    node* find(const K& key, node** update) {
        node* p = head;
        for (int i = level; i >= 0; i--) {
            while (p->forward[i] != tail && less(p->forward[i]->key, key)) {
                p = p->forward[i];
            }
            update[i] = p;
        }
        p = p->forward[0];
        return p;
    }
public:
    struct Iter {
        node* p;
        Iter() : p(nullptr) {};
        Iter(node* rhs) : p(rhs) {}
        node* operator ->()const { return (p); }
        node& operator *() const { return *p; }
        bool operator == (const Iter& rhs) { return rhs.p == p; }
        bool operator != (const Iter& rhs) { return !(rhs.p == p); }
        void operator ++() { p = p->forward[0]; }
        void operator ++(int) { p = p->forward[0]; }
    };

    skip_list() : head(new node()), tail(new node()), less{ Comp() } {
        init();
    }
    skip_list(Comp _less) : head(new node()), tail(new node()), less{ _less } {
        init();
    }


    void insert(const K& key, const V& value) {
        node* update[MAXL + 1];
        node* p = find(key, update);
        if (p->key == key) {
            p->value = value;
            return;
        }
        int lv = randomLevel();
        if (lv > level) {
            lv = ++level;
            update[lv] = head;
        }
        node* newNode = new node(key, value, lv);
        for (int i = lv; i >= 0; --i) {
            p = update[i];
            newNode->forward[i] = p->forward[i];
            p->forward[i] = newNode;
        }
        ++length;
    }


	V& operator[](const K& key) {
		node* update[MAXL + 1];
		node* p = find(key, update);
		if (p->key == key)return p->value;
		int lv = randomLevel();
		if (lv > level) {
			lv = ++level;
			update[lv] = head;
		}
		node* newNode = new node(key, V(), lv);
		for (int i = lv; i >= 0; --i) {
			p = update[i];
			newNode->forward[i] = p->forward[i];
			p->forward[i] = newNode;
		}
		++length;
		return newNode->value;
	}

    bool erase(const K& key) {
        node* update[MAXL + 1];
        node* p = find(key, update);
        if (p->key != key)return false;
        for (int i = 0; i <= p->level; ++i) {
            update[i]->forward[i] = p->forward[i];
        }
        delete p;
        while (level > 0 && head->forward[level] == tail) --level;
        --length;
        return true;
    }
    Iter find(const K& key) {
        node* update[MAXL + 1];
        node* p = find(key, update);
        if (p == tail)return tail;
        if (p->key != key)return tail;
        return Iter(p);
    }
    bool count(const K& key) {
        node* update[MAXL + 1];
        node* p = find(key, update);
        if (p == tail)return false;
        return key == p->key;
    }
    Iter end() {
        return Iter(tail);
    }
    Iter begin() {
        return Iter(head->forward[0]);
    }
};
