class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freqs[26] = { 0 };
        for (char t: tasks) {
            freqs[t - 'A']++;
        }

        struct task {
            char name;
            int times;
            int ready_at;
        };
        auto cmp = [](task& l, task& r) -> bool { return l.times < r.times; };
        priority_queue<task, vector<task>, decltype(cmp)> q;
        for (int i = 0; i < 26; i++) {
            if (freqs[i] > 0) {
                q.push(task{ .name = static_cast<char>('A'+i), .times = freqs[i], .ready_at = 0 });
            }
        }

        int clock = 0;
        queue<task> cooldown;
        while (!q.empty() || !cooldown.empty()) {
            if (!q.empty()) {
                task t = q.top();
                q.pop();
                t.times--;
                t.ready_at = clock + n + 1;
                if (t.times > 0) {
                    cooldown.push(t);
                }
            }

            if (!cooldown.empty() && clock >= cooldown.front().ready_at - 1) {
                q.push(cooldown.front());
                cooldown.pop();
            }

            clock++;
        }
        return clock;
    }
};



