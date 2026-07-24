class Solution {
public:
    bool isVowel(char ch){
        return ch=='a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.size();
        long long ans = 0;

        vector<int> nextCon(n);
        int lastCons = n;

        for(int i=n-1 ; i>=0 ; i--){

            char ch = word[i];

            if(isVowel(ch)){
                nextCon[i] = lastCons;
            }
            else{
                nextCon[i] = lastCons;
                lastCons = i;
            }
        }

        int conso = 0;
        unordered_map<char,int> vowels;

        int i=0 , j=0;

        while(i<n && j<n){
            char ch = word[j];

            if(isVowel(ch)){
                vowels[ch]++;
            }
            else{
                conso++;
            }

            if(vowels.size() < 5 || conso < k){
                j++;
            }
            else if(vowels.size() == 5 && conso == k){

                while(vowels.size() == 5 && conso == k){
                    int next_c = nextCon[j];
                    ans += (next_c - j);

                    if(isVowel(word[i])){
                        vowels[word[i]]--;
                        if(vowels[word[i]] == 0) vowels.erase(word[i]);
                    }
                    else{
                        conso--;
                    }
                    i++;
                }
                j++;
            }
            else{
                while(conso > k){
                    char c = word[i];
                    if(isVowel(c)){
                        vowels[c]--;
                        if(vowels[c] == 0) vowels.erase(c);
                    }
                    else{
                        conso--;
                    }
                    i++;
                }
                while(vowels.size() == 5 && conso == k){
                    int next_c = nextCon[j];
                    ans += (next_c - j);

                    if(isVowel(word[i])){
                        vowels[word[i]]--;
                        if(vowels[word[i]] == 0) vowels.erase(word[i]);
                    }
                    else{
                        conso--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};