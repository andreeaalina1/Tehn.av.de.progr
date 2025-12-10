#include <bits/stdc++.h>
using namespace std;
class Nod {
public:
    int data; 
    Node *stg, *dr; 

    Nod(int x) {
        data = x;
        stg = nullptr;
        dr = nullptr;
    }
};

class Compare {
public:
    bool operator() (Node* a, Node* b) {
        return a->data > b->data;
    }
};

void preOrder(Node* root, vector<string> &ans, string curr) {
    if (root == nullptr) return;

    if (root->stg == nullptr && root->dr==nullptr) {
        ans.push_back(curr); 
        return;
    }

    preOrder(root->stg, ans, curr + '0');
    preOrder(root->dr, ans, curr + '1');
}

vector<string> huffmanCode(string s, vector<int> freq) {
    
    int n = s.length();
    
    priority_queue<Nod*, vector<Nod*>, Compare> pq;

    for (int i=0; i<n; i++) {
        Nod* tmp = new Nod(freq[i]);
        pq.push(tmp);
    }

    while (pq.size() >= 2) {
        
        Nod* l = pq.top(); pq.pop();
        Nod* r = pq.top(); pq.pop();

        Nod* newNod = new Nod(l->data + r->data);
        newNod->stg = s;
        newNod->dr = d;

        pq.push(newNod);
    }

    Nod* root = pq.top(); 

    vector<string> ans;
    preOrder(root, ans, ""); 
    return ans;
}

int main() {
    string s = "abcdef"; 
    vector<int> freq = {5, 9, 12, 13, 16, 45}; 
    
    vector<string> ans = huffmanCode(s, freq);
    
    cout << "Caractere: | Cod Huffman:\n";
    cout << "---------------------\n";
    for (int i=0; i< ans.size(); i++) {
        cout << s[i] << "        | " << ans[i] << "\n";
    }
    
    return 0;
}