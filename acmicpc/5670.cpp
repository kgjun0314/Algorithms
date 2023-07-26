#include <iostream>
#include <cstring>
#include <unordered_map>
#include <vector>
#define endl "\n"
using namespace std;

int N, answer;
string word;
vector<string> dictionary;

class Trie 
{
    private:
        Trie* children[26];
        int numOfChildren;
        bool isRoot, finished;
 
    public:
        Trie(bool isroot) 
        {
            for(int i = 0; i < 26; i++) 
                children[i] = NULL; 
            finished = false;
            isRoot = isroot;
            numOfChildren = 0;
        }
    
        ~Trie() 
        {
            for (int i = 0; i < 26; i++)
                if (children[i] != NULL) 
                    delete children[i];
        }
    
        void insert(const char* cur) 
        {
            if(*cur == '\0') 
            {
                finished = true;
                return;
            }

            int pos = *cur - 'a';
    
            if(children[pos] == NULL) 
            {
                children[pos] = new Trie(false);
                numOfChildren++;
            }
    
            children[pos] -> insert(cur + 1);
        }
    
        void find(const char* cur) 
        {
            if(*cur == '\0') 
                return;
            int pos = *cur - 'a';
    
            if(isRoot) 
                answer++;
            else 
            {
                if(numOfChildren > 1) 
                    answer++;
                else if(finished) 
                    answer++;
            }
    
            children[pos] -> find(cur + 1);
        }
};

int main(void) 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(cin >> N)
    {
        dictionary.clear();

        for(int i = 0; i < N; i++)
        {
            cin >> word;
            dictionary.push_back(word);
        }

        Trie root = Trie(true);

        for(int i = 0; i < dictionary.size(); i++)
            root.insert(dictionary[i].c_str());
        
        int total = 0;
        for(int i = 0; i < dictionary.size(); i++)
        {
            answer = 0;
            root.find(dictionary[i].c_str());
            total += answer;
        }

        double average = (double)total / N;
        printf("%.2lf\n", average);
    }

    return 0;
}