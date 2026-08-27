class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>RadiantQ;
        queue<int>DireQ;
        int position = 0;
        while(position < senate.size()){
            char senator = senate[position];
            if(senator == 'R'){
                RadiantQ.push(position);
            }
            else{
                DireQ.push(position);
            }
            position++;
        }
        while(!RadiantQ.empty() && !DireQ.empty()){
            int r_front = RadiantQ.front();
            RadiantQ.pop();
            int d_front = DireQ.front();
            DireQ.pop();

            if(r_front < d_front){
                // means R will ban D
                RadiantQ.push(position++);
            }
            else{
                DireQ.push(position++);
            }
        }

        if(!RadiantQ.empty()){
            return "Radiant";
        }
        else{
            return "Dire";
        }
    }
};