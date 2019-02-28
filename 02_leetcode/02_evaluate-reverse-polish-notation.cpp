class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        std::stack<int> numbers; int number; string content;
        int first_number, second_number;
        for(unsigned int i=0; i<tokens.size(); i++) {
            content = tokens[i];
            if (0 == content.compare("+")) {
                second_number = numbers.top(); numbers.pop();
                first_number = numbers.top(); numbers.pop();
                numbers.push((first_number+second_number));
            }
            else if (0 == content.compare("-")) {
                second_number = numbers.top(); numbers.pop();
                first_number = numbers.top(); numbers.pop();
                numbers.push((first_number-second_number));
            }
            else if (0 == content.compare("*")) {
                second_number = numbers.top(); numbers.pop();
                first_number = numbers.top(); numbers.pop();
                numbers.push((first_number*second_number));
            }
            else if (0 == content.compare("/")) {
                second_number = numbers.top(); numbers.pop();
                first_number = numbers.top(); numbers.pop();
                numbers.push((first_number/second_number));
            }
            else {
                std::istringstream(content) >> number;
                numbers.push(number);
            }
        }
 
        return numbers.top();
    }
};