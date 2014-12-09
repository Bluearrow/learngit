/* 22.cpp
 * Given a push sequence and judge whether a given sequence 
 * is a pop sequence.
 */
bool IsPopOrder(const int* p_push, const int* p_pop, int length)
{
    bool result = false;

    if(p_push != NULL && p_pop != NULL && length > 0)
    {
        const int* p1 = p_push;
        const int* p2 = p_pop;
        std::stack<int> s;

        while(p2 - p_pop < length)
        {
            // Push elements from p_push if top element is 
            // not *p2 until all elements are pushed.
            while(s.empty() || s.top() != *p2)
            {
                // If all elements are pushed, break.
                if(p1 - p_push == length)
                    break;
                s.push(*p1);
                p1++;
            }
            // There is no element.
            if(s.top() != *p2)
                break;
            // If *p2 is found.
            s.pop();
            p2++;
                break;
        }
        // If all elements are found.
        if(p2 - p_pop == length && s.empty())
            result = ture;
        return result;
    }
}
