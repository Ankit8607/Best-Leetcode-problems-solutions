// https://leetcode.com/problems/design-a-text-editor/submissions/

class TextEditor {
public:
    stack<char>a,b;
    TextEditor() {
    }
    
    void addText(string text) {
        for(char i: text) a.push(i);
    }
    
    int deleteText(int k) {
        int cnt=0;
        while(k-- and !a.empty()){
            a.pop();
            cnt++;
        }
        return cnt;
    }
    
    string fun(){
        string ans;
        int cnt=10;
        while(cnt-- and !a.empty()){
            ans+=a.top();
            a.pop();
        }
        reverse(ans.begin(),ans.end());
        for(char i:ans) a.push(i);
        return ans;
    }

    string cursorLeft(int k) {
        while(k-- and !a.empty()){
            b.push(a.top());
            a.pop();
        }
        return fun();
    }
    
    string cursorRight(int k) {
        while(k-- and !b.empty()){
            a.push(b.top());
            b.pop();
        }
        return fun();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
