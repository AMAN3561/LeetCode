class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string node;

        int slots = 1;
        while(getline(ss, node, ',')){
            // no empty slots are available :
            if(slots == 0){
                return false;
            }
            // current node takes the slot :
            slots--;
            // non-null nodes creates two childs :
            if(node != "#"){
                slots += 2;
            }
        }
        // all slots must be filled :
        return slots == 0;
    }
};