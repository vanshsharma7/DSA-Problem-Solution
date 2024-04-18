class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char sign='+';
        for(int i=0;i<s.length();i++){
            char c=s[i];
            if(isdigit(c)){
                int val=0;
                while(i<s.length() && isdigit(c)){
                    val=val*10+(c-'0');
                    i++;
                    c=s[i];
                }
                i--;
                if(sign=='+')
                st.push(val);
                else if(sign=='-')
                st.push(-val);
                else if(sign=='*'){
                    int a=st.top();
                    st.pop();
                    int ans=a*val;
                    st.push(ans);
                }
                else if(sign=='/'){
                    int a=st.top();
                    st.pop();
                    int ans=a/val;
                    st.push(ans);
                }
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='/' || s[i]=='*'){
                sign=c;
            }
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};