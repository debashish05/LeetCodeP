/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        
        if(topRight[0]<bottomLeft[0] || topRight[1]<bottomLeft[1])return 0;
        
        bool ans=sea.hasShips(topRight,bottomLeft);
        
        if(topRight==bottomLeft || !ans){   //single point
            return ans;
        }
        
        // topRight and bottom left coordinate are different
        if(topRight[0]==bottomLeft[0]){
            //same x coordinate
            int mid=(topRight[1]+bottomLeft[1])/2;  // mid y coordinate
            return countShips(sea,{topRight[0],topRight[1]},{topRight[0],mid+1})+
            countShips(sea,{bottomLeft[0],mid},{bottomLeft[0],bottomLeft[1]});
        }
        //different x coordinate
        
        int mid=(topRight[0]+bottomLeft[0])/2;  // mid y coordinate
        return countShips(sea,{topRight[0],topRight[1]},{mid+1,bottomLeft[1]})+
            countShips(sea,{mid,topRight[1]},{bottomLeft[0],bottomLeft[1]});
    }
};