#pragma once
#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename Key, typename Value>
class ADT {
private:
    struct Node {
        Key key;
        Value value;
        Node* left;
        Node* right;
        int height;

        Node(const Key& k, const Value& v) noexcept : key(k), value(v), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    static inline int getHeight(Node* node) noexcept {
        return node ? node->height : 0;
    }

    static inline int getBalance(Node* node) noexcept {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    static Node* rightRotate(Node* y) noexcept {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        return x;
    }

    static Node* leftRotate(Node* x) noexcept {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = std::max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = std::max(getHeight(y->left), getHeight(y->right)) + 1;
        return y;
    }

    static Node* balanceNode(Node* node, int balance) noexcept {
        return (balance > 1 && getBalance(node->left) >= 0) ? rightRotate(node) :
               (balance > 1 && getBalance(node->left) < 0) ? (node->left = leftRotate(node->left), rightRotate(node)) :
               (balance < -1 && getBalance(node->right) <= 0) ? leftRotate(node) :
               (balance < -1 && getBalance(node->right) > 0) ? (node->right = rightRotate(node->right), leftRotate(node)) :
               node;
    }

    Node* insert(Node* node, const Key& key, const Value& value) noexcept {
        if (!node) return new Node(key, value);
        node = (key < node->key) ? (node->left = insert(node->left, key, value), node) :
               (key > node->key) ? (node->right = insert(node->right, key, value), node) :
               (node->value = value, node);

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        return balanceNode(node, balance);
    }

    Node* minValueNode(Node* node) noexcept {
        return node->left ? minValueNode(node->left) : node;
    }

    Node* remove(Node* node, const Key& key) noexcept {
        if (!node) return node;

        node = (key < node->key) ? (node->left = remove(node->left, key), node) :
               (key > node->key) ? (node->right = remove(node->right, key), node) :
               (!node->left || !node->right) ? (Node* temp = node->left ? node->left : node->right, (temp ? *node = *temp : node = nullptr), delete temp, node) :
               (Node* temp = minValueNode(node->right), node->key = temp->key, node->value = temp->value, node->right = remove(node->right, temp->key), node);

        if (!node) return node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);
        return balanceNode(node, balance);
    }

    bool search(Node* node, const Key& key, Value& value) const noexcept {
        return !node ? false :
               key < node->key ? search(node->left, key, value) :
               key > node->key ? search(node->right, key, value) :
               (value = node->value, true);
    }

    void clear(Node* node) noexcept {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

public:
    ADT() noexcept : root(nullptr) {}
    ~ADT() { clear(root); }

    inline void insert(const Key& key, const Value& value) noexcept { root = insert(root, key, value); }
    inline bool search(const Key& key, Value& value) const noexcept { return search(root, key, value); }
    inline void remove(const Key& key) noexcept { root = remove(root, key); }
};
