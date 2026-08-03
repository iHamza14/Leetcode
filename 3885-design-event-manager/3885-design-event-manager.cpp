class EventManager {
public:
    struct Compare 
    {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;   
        }
    };

    map<int,int> mpp;
    set<pair<int,int>,Compare> st;
    EventManager(vector<vector<int>>& events) {
        for(auto i : events)
        {
            int eventId = i[0];
            int priority = i[1];

            mpp[eventId]=priority;
            st.insert({priority,eventId});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority = mpp[eventId];
        st.erase(st.find({oldPriority,eventId}));
        st.insert({newPriority,eventId});
        mpp[eventId]=newPriority;
        return;
    }
    
    int pollHighest() {
        if(st.empty()) return -1;
        else 
        {
            auto top = *st.begin();
            st.erase(st.begin());
            mpp.erase(mpp.find(top.second));
            return top.second;
        }
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */