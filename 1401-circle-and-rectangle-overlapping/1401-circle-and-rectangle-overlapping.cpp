class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        if(xCenter < x2 && xCenter > x1 && yCenter < y2 && yCenter >y1) return true;
        for(int i = x1 ; i<=x2 ; i++)
        {
            int dist = (y1-yCenter)*(y1-yCenter) + (i-xCenter)*(i-xCenter);
            if(dist <= radius*radius) return true;
        }
        for(int i = x1 ; i<=x2 ; i++)
        {
            int dist = (y2-yCenter)*(y2-yCenter) + (i-xCenter)*(i-xCenter);
            if(dist <= radius*radius) return true;
        }
        for(int i = y1 ; i<=y2 ; i++)
        {
            int dist = (i-yCenter)*(i-yCenter) + (x1-xCenter)*(x1-xCenter);
            if(dist <= radius*radius) return true;
        }
        for(int i = y1 ; i<=y2 ; i++)
        {
            int dist = (i-yCenter)*(i-yCenter) + (x2-xCenter)*(x2-xCenter);
            if(dist <= radius*radius) return true;
        }
        return false;
    }
};