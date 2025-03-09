class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stack;
        for (int ast : asteroids) {
            bool destroyed = false;
            while (!stack.empty() && ast < 0 && stack.back() > 0) {
                if (stack.back() < -ast) {
                    stack.pop_back();
                    continue;
                } else if (stack.back() == -ast) {
                    stack.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                stack.push_back(ast);
            }
        }
        return stack;
    }
};