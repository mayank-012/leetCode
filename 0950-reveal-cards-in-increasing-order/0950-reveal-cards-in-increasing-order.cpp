class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        queue <int> q;


        
        for(int i =deck.size()-1; i>=0; i--)
        {
            if(q.size()>0)
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
                q.push(deck[i]);
            }
            else{
                q.push(deck[i]);
            }
        }
        int i =0;
        while(q.size()>0)
        {
            deck[i]=q.front();
            q.pop();
            i++;
        }

        reverse(deck.begin(),deck.end());
        return deck;
    }
};